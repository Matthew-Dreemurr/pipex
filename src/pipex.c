/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahadad <mahadad@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 17:05:49 by mahadad           #+#    #+#             */
/*   Updated: 2022/03/09 11:54:35 by mahadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//EXIT_FAIL
#include <stdlib.h>

//strerror();
#include <string.h>
#include <stdio.h>

//access();
#include <unistd.h>

#include "pipex.h"
#include "ppx_struct.h"

static void	ppx_check_file(int ac, char **arg)
{
	if (ac != 5)
		ppx_exit_prog(EXIT_FAILURE, NULL, "Bad arg\n");
	if (access(arg[1], R_OK) == -1)
		ppx_exit_prog(EXIT_FAILURE, NULL, "Fail acces file arg[1]\n");
	if (access(arg[4], R_OK) == -1)
		ppx_exit_prog(EXIT_FAILURE, NULL, "Fail acces file arg[4]\n");
}

/**
 * @brief `./pipex file1 cmd1 cmd2 file2`
 * 
 * @param ac 
 * @param av 
 * @return int 
 */
int	main(int ac, char **av)
{
	ppx_check_file(ac, av);
	return (0);
}
