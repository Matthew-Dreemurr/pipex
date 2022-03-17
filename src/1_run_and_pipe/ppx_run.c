/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ppx_run.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahadad <mahadad@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 14:50:21 by mahadad           #+#    #+#             */
/*   Updated: 2022/03/17 15:04:44 by mahadad          ###   ########.fr       */
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
#include "ppx_debug.h"


static void	ppx_open_files(t_data *data)
{
	data->in_file = open(data->av[1], O_RDONLY);
	if (0 > data->in_file)
		ppx_exit_prog(EXIT_FAILURE, data, "Fail to open the input file\n");
	data->out_file = open(data->av[data->ac], O_WRONLY);
	if (0 > data->out_file)
		ppx_exit_prog(EXIT_FAILURE, data, "Fail to open the output file\n");
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

#include <stdio.h>//TODO REMOVE
#include "ppx_libft.h"//TODO REMOVE
int	ppx_exe(t_data *data, int prevfd, int index)
{
	printf("index %d\n", index);
	int		ppipe[2];
	int		status;
	pid_t	pid;

	if ((data->ac - 3) != index)
		pipe(ppipe);
	pid = fork();
	if (!pid)
	{
		ppx_dup_and_close(prevfd, STDIN_FILENO);
		ppx_dup_and_close(get_out(data, ppipe[1], index), STDOUT_FILENO);
		// printf("UwU shan %d\n", prevfd);
		execve(data->cmd[index].bin, data->cmd[index].arg, &data->env);
		ft_putstr_fd("Error execve fail!\n", STDERR_FILENO);
		exit(EXIT_SUCCESS);
	}
	else if (pid == -1)
	{
		printf("FUK!\n");
		exit(EXIT_FAILURE);
	}
	close(prevfd);
	close(get_out(data, ppipe[1], index));
	// printf("FUK!\n");
	waitpid(pid, &status, 0);
	if ((data->ac - 3) != index)
		return (ppx_exe(data, ppipe[0], index + 1));
	return (WEXITSTATUS(status));
}




int	ppx_run(t_data *data)
{
	ppx_open_files(data);
	return (ppx_exe(data, data->in_file, 0));
}







/**
 * @brief 
 * 
 * @param data 
 * @param env 
void	ppx_run(t_data *data, char **env)
{
	int	pipe1[2], pipe2[2];
	pid_t	pid;
	int		status;

	ppx_open_files(data);

	status = 0;
	
	pipe(pipe1);
	pid = fork();
	if (!pid)
	{
		ft_putstr_fd("test1\n", STDOUT_FILENO);
		ppx_dup_and_close(data->in_file, STDIN_FILENO);
		ppx_dup_and_close(pipe1[1], STDOUT_FILENO);
		execve(data->cmd[0].bin, data->cmd[0].arg, env);
	}
	status = 0;
	waitpid(pid, &status, 1);//TODO close all file descriport
	pipe(pipe2);
	pid = fork();
	if (!pid)
	{
		ft_putstr_fd("test2\n", STDOUT_FILENO);
		ppx_dup_and_close(pipe1[0], STDIN_FILENO);
		ppx_dup_and_close(pipe2[1], STDOUT_FILENO);
		execve(data->cmd[1].bin, data->cmd[1].arg, env);
	}
	status = 0;
	waitpid(pid, &status, 1);//TODO close all file descriport
	pid = fork();
	if (!pid)
	{
		setbuf(stdout, NULL);
		ft_putstr_fd("test3\n", STDOUT_FILENO);
		char buff[500];
		buff[read(pipe2[0], &buff, 21) - 1] = '\0';
		printf("buff[%s", buff);
		ppx_dup_and_close(pipe2[0], STDIN_FILENO);
		// ppx_dup_and_close(data->out_file, STDOUT_FILENO);
		// write(STDOUT_FILENO, "1234", 4);
		execve(data->cmd[2].bin, data->cmd[2].arg, env);
	}
	status = 0;
	waitpid(pid, &status, 1);//TODO close all file descriport
	ft_putstr_fd("exit run\n", STDOUT_FILENO);
	close(pipe1[1]);
	close(pipe2[0]);
	close(data->in_file);
	close(data->out_file);
}
 */