/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ppx_init_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahadad <mahadad@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 13:23:57 by mahadad           #+#    #+#             */
/*   Updated: 2022/03/17 17:27:03 by mahadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// malloc(); EXIT_FAIL
#include <stdlib.h>

//access();
#include <unistd.h>

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
		len = strlen_protect(data->av[x]);
		if (!len)
			ppx_exit_prog(EXIT_FAILURE, data, "Empty commad ?\n");
		data->cmd[index].arg = ft_split(data->av[x], ' ');
		x++;
		index++;
	}
}

/**
 * @brief Split all `env $PATH` in `data->bin_dir`.
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

static void	ppx_vect_dir_path(t_data *data, t_vector *vec, char *dir, char *cmd)
{
	if (!vect_write(vec, dir))
		ppx_exit_prog(EXIT_FAILURE, data, "vect_write fail !\n");
	if (!vect_push(vec, '/'))
		ppx_exit_prog(EXIT_FAILURE, data, "vect_push fail !\n");
	if (!vect_cat(vec, cmd))
		ppx_exit_prog(EXIT_FAILURE, data, "vect_cat fail !\n");
}

/**
 * @brief Will find the binary file for eatch command
 *          and check if is executable.
 *        Will store in data->cmd[x].bin
 */
static void	ppx_find_cmd_dir(t_data *data)
{
	int			x;
	char		**tmp;

	vect_init_strict(&data->vec, 32);
	x = 0;
	while (x < (data->ac - 2))
	{
		tmp = data->bin_dir;
		while (*tmp)
		{
			ppx_vect_dir_path(data, &data->vec, *tmp, data->cmd[x].arg[0]);
			if (access(data->vec.buff, X_OK) != -1)
			{
				data->cmd[x].bin = ft_strdup(data->vec.buff);
				break ;
			}
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
 * @brief Will init all data, will free data->cmd[x].arg[0]
 *                        and replace with data->cmd[x].bin.
 */
void	ppx_init_data(t_data *data, char **env)
{
	data->cmd = (t_cmd *)ft_calloc((data->ac - 2), sizeof(t_cmd));
	if (!data->cmd)
		ppx_exit_prog(EXIT_FAILURE, data, "Fail malloc **data !\n");
	ppx_populate_cmd(data);
	ppx_init_bindir(data, env);
	ppx_find_cmd_dir(data);
}
