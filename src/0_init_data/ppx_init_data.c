/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ppx_init_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahadad <mahadad@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 13:23:57 by mahadad           #+#    #+#             */
/*   Updated: 2022/06/10 13:44:53 by mahadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// malloc(); EXIT_FAIL
#include <stdlib.h>

//access();
#include <unistd.h>

#include "pipex.h"
#include "ppx_struct.h"
#include "ppx_libft.h"
#include "ppx_exit_prog.h"
#include "vector.h"

#include "ppx_debug.h"

/**
 * @brief Store all cmd form `av` to `data->cmd[x].arg`.
 */
static void	ppx_populate_cmd(t_data *data)
{
	int		index;
	int		x;
	int		len;

	index = 0;
	x = 2;
	while (index < (data->ac - 2))
	{
		data->cmd[index].arg = NULL;
		len = strlen_protect(data->av[x]);
		if (!len)
			ppx_exit_prog(P_EXIT_FAILURE, data, "Empty commad ?\n");
		data->cmd[index].arg = ft_split(data->av[x], ' ');
		x++;
		index++;
	}
}

/**
 * @brief Will init all data, will free data->cmd[x].arg[0]
 *                        and replace with data->cmd[x].bin.
 */
void	ppx_init_data(t_data *data, char **env)
{
	data->cmd = (t_cmd *)ft_calloc((data->ac - 2), sizeof(t_cmd));
	if (!data->cmd)
		ppx_exit_prog(P_EXIT_FAILURE, data, "Fail malloc **data !\n");
	ppx_populate_cmd(data);
	ppx_init_bindir(data, env);
	ppx_find_cmd_dir(data);
}
