/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahadad <mahadad@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 17:05:49 by mahadad           #+#    #+#             */
/*   Updated: 2022/03/09 11:37:49 by mahadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "pipex.h"
#include "ppx_struct.h"

int	main(int ac, char **av)
{
	if (ac < 5)
		ppx_exit_prog(EXIT_FAILURE, NULL, "Bad arg\n");
	(void)av;
	return (0);
}
