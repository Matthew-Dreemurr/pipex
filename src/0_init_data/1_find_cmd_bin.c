/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_find_cmd_bin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahadad <mahadad@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 15:47:57 by mahadad           #+#    #+#             */
/*   Updated: 2022/03/18 15:57:39 by mahadad          ###   ########.fr       */
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

static void	ppx_vect_dir_path(t_data *data, t_vector *vec, char *dir, char *cmd)
{
	if (!vect_write(vec, dir))
		ppx_exit_prog(EXIT_FAILURE, data, "vect_write fail !\n");
	if (!vect_push(vec, '/'))
		ppx_exit_prog(EXIT_FAILURE, data, "vect_push fail !\n");
	if (!vect_cat(vec, cmd))
		ppx_exit_prog(EXIT_FAILURE, data, "vect_cat fail !\n");
}

static int	check_bin(t_data *data, int x, char *tmp)
{
	vect_init_strict(&data->vec, 32);
	ppx_vect_dir_path(data, &data->vec, tmp, data->cmd[x].arg[0]);
	if (access(data->cmd[x].arg[0], X_OK) != -1)
	{
		data->cmd[x].bin = ft_strdup(data->cmd[x].arg[0]);
		return (EXIT_SUCCESS);
	}
	else if (access(data->vec.buff, X_OK) != -1)
	{
		data->cmd[x].bin = ft_strdup(data->vec.buff);
		return (EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}

/**
 * @brief Will find the binary file for eatch command
 *          and check if is executable.
 *        Will store in data->cmd[x].bin
 */
void	ppx_find_cmd_dir(t_data *data)
{
	int			x;
	char		**tmp;

	x = 0;
	while (x < (data->ac - 2))
	{
		tmp = data->bin_dir;
		while (*tmp)
		{
			if (check_bin(data, x, *tmp) == EXIT_SUCCESS)
				break ;
			tmp++;
			if (!(*tmp))
			{
				ft_putstr_fd(data->cmd[x].arg[0], STDOUT_FILENO);
				ppx_exit_prog(EXIT_FAILURE, data, "\nCommand not found !\n");
			}
		}
		x++;
	}
}

/**
 * @brief Split all `env $PATH` in `data->bin_dir`.
 */
void	ppx_init_bindir(t_data *data, char **env)
{
	int	x;

	x = 0;
	while (ft_strncmp("PATH=", env[x], 5))
		x++;
	data->bin_dir = ft_split(env[x] + 5, ':');
	if (!data->bin_dir)
		ppx_exit_prog(EXIT_FAILURE, NULL, "Fail ft_plit(); to `data->bin_dir`");
}
