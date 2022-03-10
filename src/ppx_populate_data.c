/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ppx_populate_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahadad <mahadad@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 13:23:57 by mahadad           #+#    #+#             */
/*   Updated: 2022/03/10 13:34:02 by mahadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// malloc(); EXIT_FAIL
#include <stdlib.h>

//access();
#include <unistd.h>

#include "pipex.h"
#include "ppx_struct.h"

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
 * @brief 
 * 
 * @param data 
 * @param ac 
 * @param av 
 */
void	ppx_populate_data(t_data *data, int ac, char **av)
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
