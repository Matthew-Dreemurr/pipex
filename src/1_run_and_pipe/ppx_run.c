/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ppx_run.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahadad <mahadad@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 14:50:21 by mahadad           #+#    #+#             */
/*   Updated: 2022/03/15 18:17:45 by mahadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//open();
#include <fcntl.h>
//EXIT_FAILURE
#include <stdlib.h>
//dup();
#include <unistd.h>
//strerror();
#include <string.h>

#include "pipex.h"
#include "ppx_struct.h"
#include "ppx_exit_prog.h"

static void	ppx_open_files(t_data *data)
{
	data->in_file = open(data->av[1], O_RDONLY);
	if (0 > data->in_file)
		ppx_exit_prog(EXIT_FAILURE, data, "Fail to open the input file\n");
	data->out_file = open(data->av[data->ac], O_WRONLY);
	if (0 > data->out_file)
		ppx_exit_prog(EXIT_FAILURE, data, "Fail to open the output file\n");
}


void	ppx_run(t_data *data, char **env)
{
	int	pipe_[2];
	pid_t	id;
	int		status;

	ppx_open_files(data);
	pipe(pipe_);

	id = fork();
	if (!id)
	{
		close(pipe_[0]);
		dup2(data->in_file, STDIN_FILENO);
		dup2(pipe_[1], STDOUT_FILENO);
		execve(data->cmd[0].bin, data->cmd[0].arg, env);
	}
	id = fork();
	if (!id)
	{
		close(pipe_[1]);
		dup2(pipe_[0], STDIN_FILENO);
		dup2(pipe_[1], STDOUT_FILENO);
		execve(data->cmd[1].bin, data->cmd[1].arg, env);
	}
	id = fork();
	if (!id)
	{
		dup2(pipe_[0], STDIN_FILENO);
		dup2(data->out_file, STDOUT_FILENO);
		close(pipe_[1]);
		execve(data->cmd[2].bin, data->cmd[2].arg, env);
	}
		close(pipe_[1]);
		close(pipe_[0]);
		close(data->in_file);
		close(data->out_file);
		waitpid(id, &status, 0);
}