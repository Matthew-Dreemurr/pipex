/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahadad <mahadad@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 13:56:02 by mahadad           #+#    #+#             */
/*   Updated: 2022/03/10 13:44:21 by mahadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "ppx_libft.h"

/**
 * @brief Outputs the string ’s’ to the given file descriptor.
 * 
 * @param s  The string to output.
 * @param fd The file descriptor on which to write.
 */
void	ft_putstr_fd(char *s, int fd)
{
	char	*ptr;

	if (!s || fd < 0)
		return ;
	ptr = s;
	while (*ptr)
		ptr++;
	write(fd, s, (size_t)(ptr - s));
}
