/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sandbox.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahadad <mahadad@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 13:27:06 by mahadad           #+#    #+#             */
/*   Updated: 2022/03/13 16:28:28 by mahadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/wait.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

int
main(int argc, char *argv[])
{
	setbuf(stdout, NULL);

	char buff[500];
	while (1)//Test stdin
	{
		printf("Read fd 0 [%lu]\n", read(STDIN_FILENO, buff, 1));
		if (*buff == 'q')
			break;
	}

	int oldStdou = dup(STDIN_FILENO);//bkp stdin
	printf("oldStdin = %d\n", oldStdou);
	close(STDIN_FILENO);//Close stdin

	printf("Try to read old stdin fd [%zd]\n", read(STDIN_FILENO, buff, 1));//Check if stdout is not readeble
	

	dup2(oldStdou, 5);
	
	while (1)//Test read stdin in fd 5
	{
		printf("Read fd 5 [%lu]\n", read(5, buff, 1));
		if (*buff == 'q')
			break;
	}
	
	int	newFile;
	if (0 > (newFile = open("./Makefile", O_RDONLY)))
		return (1);
	dup2(newFile, STDIN_FILENO);
	read(STDIN_FILENO, buff, 449);
	printf("Write buff for stdin:\n%s", buff);
	return (0);
}
