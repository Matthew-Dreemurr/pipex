/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ppx_populate_cmd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahadad <mahadad@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 13:23:57 by mahadad           #+#    #+#             */
/*   Updated: 2022/03/10 14:27:28 by mahadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// malloc(); EXIT_FAIL
#include <stdlib.h>

//access();
#include <unistd.h>

#include "ppx_struct.h"
#include "ppx_libft.h"
#include "ppx_exit_prog.h"

#include "ppx_debug.h"

/**
 * @brief 
 * 
 * @param path 
 * @param cmd 
static void	ppx_check_bin(char *path, char *cmd)
{
	int	x;

	x = 2;
	while (x < ac)
	{
		if (access(arg[x], X_OK) == -1)
		{
			ft_putstr_fd(arg[x], STDERR_FILENO);
			ppx_exit_prog(EXIT_FAILURE, NULL, " : command not found\n");
		}
	}
}
 */

/**
 * @brief Store all cmd form `av` to `data-cmd`.
 * 
 * @param data 
 * @param ac 
 * @param av 
 */
static void	ppx_populate_cmd(t_data *data, int ac, char **av)
{
	int	x;

	x = 0;
	data->cmd = (t_cmd *)malloc(sizeof(t_cmd) * (ac - 2));
	if (!data->cmd)
		ppx_exit_prog(EXIT_FAILURE, data, "Fail malloc **data !\n");
	while (x < (ac - 2))
	{
		data->cmd[x].cmd = av[x + 2];
		x++;
	}
	x = 0;
}

/**
 * @brief Split all `$PATH` in `data->bin_dir`.
 */
static void	ppx_init_bindir(t_data *data, char **env)
{
	int	x;

	x = 0;
	while (ft_strncmp("PATH=", env[x], 5))
		x++;
	data->bin_dir = ft_split(env[x] + 5, ':');
	if (!data->bin_dir)
		ppx_exit_prog(EXIT_FAILURE, NULL, "Fail ft_plit(); to `data->bin_dir`");
}

void	ppx_init_data(t_data *data, int ac, char **av, char **env)
{
	data->ac = ac - 1;
	data->av = av;
	ppx_populate_cmd(data, ac, av);
	ppx_init_bindir(data, env);
}
