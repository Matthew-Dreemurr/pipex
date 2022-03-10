/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahadad <mahadad@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 17:05:49 by mahadad           #+#    #+#             */
/*   Updated: 2022/03/10 14:44:37 by mahadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//EXIT_FAIL, malloc();
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
#include "ppx_libft.h"
#include "ppx_exit_prog.h"
#include "ppx_debug.h"

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

	if (ac < 5)
		ppx_exit_prog(EXIT_FAILURE, NULL, PPX_ERR_USAGE);
	ppx_check_file(ac, av);
	ppx_init_data(&data, ac, av, env);
	if (PPX_DEBUG)
		ft_putstr_fd("Clean exit\n", STDOUT_FILENO);
	ppx_exit_prog(EXIT_SUCCESS, &data, NULL);
	return (0);
}
