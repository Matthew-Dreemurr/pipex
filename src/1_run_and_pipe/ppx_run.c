/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ppx_run.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahadad <mahadad@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 14:50:21 by mahadad           #+#    #+#             */
/*   Updated: 2022/03/15 16:55:18 by mahadad          ###   ########.fr       */
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
/**
**/
static void	ppx_middle_cmd(t_data *data, char **env, int fds[])
{
	int	frk;

	frk = fork();
	if (frk > 0)
	{
		return ;
	}
	else if (!frk)
	{
		dup2(fds[0], STDIN_FILENO);
		dup2(data->out_file, STDOUT_FILENO);
		execve(data->cmd[1].bin, data->cmd[1].arg, env);
	}
	
}

#include <stdio.h> //TODO REMOVE
void	ppx_run(t_data *data, char **env)
{
	int	frk;
	int	fds[2];
	int	old_stdout;

	old_stdout = dup(STDOUT_FILENO);
	ppx_open_files(data);
	if (pipe(fds))
		ppx_exit_prog(EXIT_FAILURE, data, NULL);
	printf("Parent : %d,%d\n", fds[0], fds[1]);
	frk = fork();//first cmd
	if (frk > 0)//end
	{
		ppx_middle_cmd(data, env, fds);
		close(data->in_file);
		close(data->out_file);
		close(fds[0]);
		close(fds[1]);
		ppx_exit_prog(EXIT_SUCCESS, data, "Clean exit ppx_run\n");
	}
	else if (!frk)//exe fist cmd and pipe
	{
		dup2(data->in_file, STDIN_FILENO);
		dup2(fds[1], STDOUT_FILENO);
		execve(data->cmd[0].bin, data->cmd[0].arg, env);
		dup2(STDOUT_FILENO, old_stdout);
		printf("Child : %d,%d\n", fds[0], fds[1]);
	}
	else
		;//TODO return error
}