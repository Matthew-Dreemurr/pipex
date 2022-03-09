/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahadad <mahadad@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 17:05:49 by mahadad           #+#    #+#             */
/*   Updated: 2022/03/09 15:30:30 by mahadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//EXIT_FAIL
#include <stdlib.h>

//strerror();
#include <string.h>
#include <stdio.h>

//access();
#include <unistd.h>

#include "pipex.h"
#include "ppx_struct.h"
#include "ppx_debug.h"
#include "ppx_error_msg.h"

void	ppx_check_bin(int ac, char **arg)
{
	int	x;

	x = 2;
	while (x < ac)
	{
		if (access(arg[x], X_OK) == -1)
		{
			ft_putstr_fd(arg[x], STDERR_FILENO);
			ppx_exit_prog(EXIT_FAILURE, NULL, " : command not found\n");//Check how to check the bin with ENV
		}
	}
}

static void	ppx_check_file(int ac, char **arg)
{
	if (access(arg[1], R_OK) == -1)
		ppx_exit_prog(EXIT_FAILURE, NULL, "Fail read file1\n");
	else if (PPX_DEBUG)
		ft_putstr_fd("[OK] read file1\n", STDOUT_FILENO);
	if (access(arg[ac - 1], R_OK) == -1)
		ppx_exit_prog(EXIT_FAILURE, NULL, "Fail read file2\n");
	else if (PPX_DEBUG)
		ft_putstr_fd("[OK] read file2\n", STDOUT_FILENO);
	if (access(arg[ac - 1], W_OK) == -1)
		ppx_exit_prog(EXIT_FAILURE, NULL, "Fail write file2\n");
	else if (PPX_DEBUG)
		ft_putstr_fd("[OK] write file2\n", STDOUT_FILENO);
	ppx_check_bin(ac, arg);
}

/**
 * @brief `./pipex file1 cmd1 cmd2 file2`
 * 
 * @param ac 
 * @param av 
 * @return int 
 */
int	main(int ac, char **av)
{
	if (ac < 5)
		ppx_exit_prog(EXIT_FAILURE, NULL, PPX_ERR_USAGE);
	ppx_check_file(ac, av);
	if (PPX_DEBUG)
		ft_putstr_fd("Clean exit\n", STDOUT_FILENO);
	return (0);
}
