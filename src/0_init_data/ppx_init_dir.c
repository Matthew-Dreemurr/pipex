/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ppx_init_dir.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahadad <mahadad@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 16:37:59 by mahadad           #+#    #+#             */
/*   Updated: 2022/03/10 17:36:17 by mahadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//access();
#include <unistd.h>

#include "ppx_struct.h"
#include "ppx_libft.h"
#include "ppx_exit_prog.h"

#include "vector.h"

#include "ppx_debug.h"

/**
 * @brief 
 * execve(binaryPath, arg, env);
 *     binaryPath = `env $PATH`
 *     arg = {$binaryPath, `flag`}
 *     env = env[]
 * // TODO use vector to find `dir/bin`, to avoid usless malloc.
static void	ppx_init_bin(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	while (x < (data->ac))
	{
		y = 0;
		{

		}
		x++;
	}
}
 */
