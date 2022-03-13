/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sandbox.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahadad <mahadad@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 13:27:06 by mahadad           #+#    #+#             */
/*   Updated: 2022/03/13 15:15:36 by mahadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/wait.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int
main(int argc, char *argv[])
{
	pid_t	cpid;
	cpid = fork();
	if (cpid)
	{
		printf("Parent %d\n", cpid);
	}
	if (!cpid){
		printf("Child %d\n", cpid);
		cpid = fork();
		if (cpid)
			printf("Child of child %d\n", cpid);
	}
}
