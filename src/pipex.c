/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahadad <mahadad@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 17:05:49 by mahadad           #+#    #+#             */
/*   Updated: 2022/06/10 15:11:12 by mahadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//EXIT_FAIL, malloc();
#include <stdlib.h>

//strerror();
#include <string.h>
#include <stdio.h>

//access();
#include <unistd.h>
#include <fcntl.h>

#include "pipex.h"

#include "ppx_struct.h"
#include "ppx_debug.h"
#include "ppx_error_msg.h"
#include "ppx_libft.h"
#include "ppx_exit_prog.h"
#include "ppx_debug.h"

static void	ppx_init_var(t_data *data, int ac, char **av)
{
	data->ac = ac - 1;
	data->av = av;
	data->cmd = NULL;
	data->bin_dir = NULL;
	data->vec.buff = NULL;
}

static void	ppx_check_file(int ac, char **arg)
{
	int	file;

	// if (access(arg[1], R_OK) == -1)
	// 	ppx_exit_prog(P_EXIT_FAILURE, NULL, "Fail read file1\n");
	if (access(arg[1], R_OK) == -1)
		printf("test\n");
	else if (PPX_DEBUG)
		ft_putstr_fd("[OK] read file1\n", STDOUT_FILENO);
	if (access(arg[ac - 1], W_OK) == -1)
	{
		file = open(arg[ac - 1], O_CREAT , 0666);
		if (file == -1)
			ppx_exit_prog(P_EXIT_FAILURE, NULL, "Fail write file2\n");
		close(file);
	}
	else if (PPX_DEBUG)
		ft_putstr_fd("[OK] write file2\n", STDOUT_FILENO);
}

/**
 * @brief `./pipex file1 cmd1 cmd2 <...> file2`.
 *        `ac--` to remove the first `av`.
 * 
 * @param ac
 * @param av 
 * @return int 
 */
int	main(int ac, char **av, char **env)
{
	t_data	data;

	ppx_init_var(&data, ac, av);
	if (ac < 5)
		ppx_exit_prog(P_EXIT_FAILURE, NULL, PPX_ERR_USAGE);
	ppx_check_file(ac, av);
	ppx_init_data(&data, env);
	ppx_exit_prog(ppx_run(&data), &data, NULL);
	return (0);
}
