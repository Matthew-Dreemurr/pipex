/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahadad <mahadad@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 17:05:49 by mahadad           #+#    #+#             */
/*   Updated: 2022/03/10 13:57:24 by mahadad          ###   ########.fr       */
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



static void	ppx_check_file(int ac, char **arg)
{
	if (access(arg[1], R_OK) == -1)
		ppx_exit_prog(EXIT_FAILURE, NULL, "Fail read file1\n");
	else if (PPX_DEBUG)
		ft_putstr_fd("[OK] read file1\n", STDOUT_FILENO);
	if (access(arg[ac], R_OK) == -1)
		ppx_exit_prog(EXIT_FAILURE, NULL, "Fail read file2\n");
	else if (PPX_DEBUG)
		ft_putstr_fd("[OK] read file2\n", STDOUT_FILENO);
	if (access(arg[ac], W_OK) == -1)
		ppx_exit_prog(EXIT_FAILURE, NULL, "Fail write file2\n");
	else if (PPX_DEBUG)
		ft_putstr_fd("[OK] write file2\n", STDOUT_FILENO);
}

static void	ppx_init_data(t_data *data, int ac, char **av, char **env)
{
	int	x;

	x = 0;
	data->ac = ac - 1;
	data->av = av;
	while (ft_strncmp("PATH=", env[x], 5))
		x++;
	ft_putstr_fd(env[x], STDOUT_FILENO);
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
	ppx_init_data(&data, ac, av, env);
	ppx_check_file(ac, av);
	ppx_populate_data(&data, ac, av);
	if (PPX_DEBUG)
		ft_putstr_fd("Clean exit\n", STDOUT_FILENO);
	return (0);
}
