/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ppx_init_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahadad <mahadad@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 13:23:57 by mahadad           #+#    #+#             */
/*   Updated: 2022/03/15 12:02:38 by mahadad          ###   ########.fr       */
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
static void	ppx_populate_cmd(t_data *data, char **av)
{
	int		index;
	int		x;
	int		len;

	index = 0;
	x = 2;
	while (index < (data->ac - 2))
	{
		len = strlen_protect(av[x]);
		if (!len)
			ppx_exit_prog(EXIT_FAILURE, data, "Empty commad ?\n");
		data->cmd[index].arg = ft_split(av[x], ' ');
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

#include <stdio.h>//TODO REMOVE
#include <unistd.h>
static void	ppx_test_fork(t_data *data, char **env);
/**
 * @brief Will init all data, will free data->cmd[x].arg[0]
 *                        and replace with data->cmd[x].bin.
 */
void	ppx_init_data(t_data *data, int ac, char **av, char **env)
{
	data->ac = ac - 1;
	data->av = av;
	data->vec.buff = NULL;
		data->cmd = (t_cmd *)ft_calloc((data->ac - 2), sizeof(t_cmd));
	if (!data->cmd)
		ppx_exit_prog(EXIT_FAILURE, data, "Fail malloc **data !\n");
	ppx_populate_cmd(data, av);
	ppx_init_bindir(data, env);
	ppx_find_cmd_dir(data);




//TODO REMOVE DEBUG
/**
**/
	for (int x = 0; x < (data->ac - 2); x++)
	{
		printf("cmd[%d]: %-12s ",x,data->cmd[x].bin);
		for (int y = 1; data->cmd[x].arg[y]; y++)
			printf("[%s] ",  data->cmd[x].arg[y]);
		printf("\n");
	}
	// for (int v = 0; v < (data->ac - 2); v++)
	// {
		// free(data->cmd[v].arg[0]);
		// data->cmd[v].arg[0] = data->cmd[v].bin;
		// printf("%s\n", data->cmd[v].arg[0]);
	// }
	// printf("[[%d]]", execve(data->cmd[0].bin, data->cmd[0].arg, env));
	ppx_test_fork(data, env);
}

static void	ppx_test_fork(t_data *data, char **env)
{
	// pid_t	cpid;
	int		uwu[2];
	int		uwuq[2];

	// printf("cpid [%d]\n", cpid = fork());
	// if (!cpid)
	// {
		// printf("end\n");
		// ppx_exit_prog(EXIT_SUCCESS, data, "Clean quit test fork\n");
	// }
	// else
	// {
		if (pipe(uwu))
		{
			ft_putstr_fd("error!!!\n", 1);
			return ;
		}
		dup2(STDOUT_FILENO, uwu[0]);
		execve(data->cmd[0].bin, data->cmd[0].arg, env);
		if (pipe(uwuq))
		{
			ft_putstr_fd("error!!!\n", 1);
			return ;
		}
		close(uwu[0]);
		dup2(uwu[1], STDIN_FILENO);
		dup2(STDOUT_FILENO, uwuq[0]);
		execve(data->cmd[1].bin, data->cmd[1].arg, env);
		dup2(uwuq[1], STDOUT_FILENO);
		execve(data->cmd[1].bin, data->cmd[1].arg, env);
		dup2(STDOUT_FILENO, uwuq[0]);
		execve(data->cmd[1].bin, data->cmd[1].arg, env);
		dup2(uwuq[1], STDOUT_FILENO);
		ft_putstr_fd("end\n", 1);
	// }
}
