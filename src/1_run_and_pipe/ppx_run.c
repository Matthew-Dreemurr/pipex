/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ppx_run.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahadad <mahadad@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 14:50:21 by mahadad           #+#    #+#             */
/*   Updated: 2022/03/16 13:32:06 by mahadad          ###   ########.fr       */
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

#include <stdio.h>//TODO REMOVE
#include "ppx_libft.h"//TODO REMOVE
void	ppx_run(t_data *data, char **env)
{
	int	pipe1[2], pipe2[2];
	pid_t	pid;
	int		status;

	ppx_open_files(data);

	// write(data->out_file, "23", 2);
	status = 0;
	pipe(pipe1);
	pid = fork();
	if (!pid)
	{
		ft_putstr_fd("test1\n", STDOUT_FILENO);
		dup2(data->in_file, STDIN_FILENO);
		dup2(pipe1[1], STDOUT_FILENO);
		execve(data->cmd[0].bin, data->cmd[0].arg, env);
	}
	waitpid(pid, &status, 1);
	pipe(pipe2);
	pid = fork();
	if (!pid)
	{
		ft_putstr_fd("test2\n", STDOUT_FILENO);
		dup2(pipe1[0], STDIN_FILENO);
		dup2(pipe2[1], STDOUT_FILENO);
		execve(data->cmd[1].bin, data->cmd[1].arg, env);
	}
	waitpid(pid, &status, 1);
	pid = fork();
	if (!pid)
	{
		ft_putstr_fd("test3\n", STDOUT_FILENO);
		dup2(pipe2[0], STDIN_FILENO);
		dup2(data->out_file, STDOUT_FILENO);
		execve(data->cmd[2].bin, data->cmd[2].arg, env);
	}
	waitpid(pid, &status, 1);
	// close(pipe1[1]);
	// close(pipe2[0]);
	// close(data->in_file);
	// close(data->out_file);
}