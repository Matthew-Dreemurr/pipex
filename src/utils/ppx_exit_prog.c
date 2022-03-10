/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ppx_exit_prog.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahadad <mahadad@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 11:12:07 by mahadad           #+#    #+#             */
/*   Updated: 2022/03/10 14:12:52 by mahadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "ppx_debug.h"
#include "ppx_struct.h"
#include "ppx_libft.h"

static void	ppx_free_bindir(t_data *data)
{
	int	x;

	x = 0;
	if (data->bin_dir)
	{
		while (x < (data->ac - 2))
		{
			free(data->bin_dir[x]);
			x++;
		}
		free(data->bin_dir);
	}
}

static void	ppx_prog_free(t_data *data)
{
	if (data->bin_dir)
		ppx_free_bindir(data);
}

void	ppx_exit_prog(int ret, t_data *data, const char *debug)
{
	if (data)
		ppx_prog_free(data);
	if (debug)
		ft_putstr_fd((char *)debug, STDOUT_FILENO);
	else
		(void)debug;
	if (ret == EXIT_FAILURE)
		ft_putstr_fd("Error\n", STDERR_FILENO);
	exit(ret);
}
