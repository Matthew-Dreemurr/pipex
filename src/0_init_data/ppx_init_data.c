/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ppx_init_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahadad <mahadad@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 13:23:57 by mahadad           #+#    #+#             */
/*   Updated: 2022/03/10 16:37:34 by mahadad          ###   ########.fr       */
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
 * @brief Store all cmd form `av` to `data->bin[x].cmd`.
 */
static void	ppx_populate_cmd(t_data *data, char **av)
{
	int	x;

	x = 0;
	data->bin = (t_bin *)malloc(sizeof(t_bin) * (data->ac - 2));
	if (!data->bin)
		ppx_exit_prog(EXIT_FAILURE, data, "Fail malloc **data !\n");
	while (x < (data->ac - 2))
	{
		data->bin[x].cmd = av[x + 2];
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

#include <stdio.h>//TODO
void	ppx_init_data(t_data *data, int ac, char **av, char **env)
{
	data->ac = ac - 1;
	data->av = av;
	ppx_populate_cmd(data, av);
	ppx_init_bindir(data, env);
	// ppx_find_cmd_dir(data);

//TODO REMOVE DEBUG
	for (int x = 0; x < (data->ac - 2); x++)
		printf("cmd[%d]:%s\n",x,data->bin[x].cmd);
	// for (int x = 0; data->bin_dir[x]; x++)
		// printf("bin[%d]:%s\n",x,data->bin_dir[x]);
}
