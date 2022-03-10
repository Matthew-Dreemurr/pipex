/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ppx_init_dir.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahadad <mahadad@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 16:37:59 by mahadad           #+#    #+#             */
/*   Updated: 2022/03/10 16:42:47 by mahadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
 */
static void	ppx_init_bin(t_data *data)
{
//TODO use vector to find `dir/bin`, to avoid usless malloc.
	while (data->)
	{
		/* code */
	}
	
}
