/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ppx_run.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahadad <mahadad@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 14:50:21 by mahadad           #+#    #+#             */
/*   Updated: 2022/06/10 15:12:44 by mahadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//open();
#include <fcntl.h>
//P_EXIT_FAILURE
#include <stdlib.h>
//dup();
#include <unistd.h>
//strerror();
#include <string.h>

#include "pipex.h"
#include "ppx_struct.h"
#include "ppx_exit_prog.h"
#include "ppx_debug.h"

#include <stdio.h>//TODO
static void	ppx_open_files(t_data *data)
{
	data->in_file = open(data->av[1], O_RDONLY);
	// if (0 > data->in_file)//TODO
	// 	ppx_exit_prog(P_EXIT_FAILURE, data, "Fail to open the input file\n");
	if (0 > data->in_file)
		printf("Test2\n");
	data->out_file = open(data->av[data->ac], O_WRONLY);
	if (0 > data->out_file)
		ppx_exit_prog(P_EXIT_FAILURE, data, "Fail to open the output file\n");
}

static void	ppx_dup_and_close(int old, int new)
{
	dup2(old, new);
	close(old);
}

static int	get_out(t_data *data, int ppipe, int index)
{
	if (index < (data->ac - 3))
		return (ppipe);
	return (data->out_file);
}

int	ppx_exe(t_data *data, int prevfd, int index)
{
	int		ppipe[2];
	int		status;
	pid_t	pid;

	status = 0;
	if ((data->ac - 3) != index)
		if (pipe(ppipe))
			ppx_exit_prog(P_EXIT_FAILURE, data, NULL);
	pid = fork();
	if (!pid)
	{
		ppx_dup_and_close(prevfd, STDIN_FILENO);
		ppx_dup_and_close(get_out(data, ppipe[1], index), STDOUT_FILENO);
		execve(data->cmd[index].bin, data->cmd[index].arg, &data->env);
		ft_putstr_fd("Error execve fail!\n", STDERR_FILENO);
		exit(P_EXIT_SUCCESS);
	}
	waitpid(pid, &status, WNOHANG);
	close(prevfd);
	close(get_out(data, ppipe[1], index));
	if (pid == -1)
		ppx_exit_prog(P_EXIT_FAILURE, data, "Fork failed!\n");
	if ((data->ac - 3) != index)
		return (ppx_exe(data, ppipe[0], index + 1));
	return (WEXITSTATUS(status));
}

int	ppx_run(t_data *data)
{
	ppx_open_files(data);
	return (ppx_exe(data, data->in_file, 0));
}
