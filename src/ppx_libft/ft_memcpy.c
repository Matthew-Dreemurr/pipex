/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahadad <mahadad@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 12:06:29 by mahadad           #+#    #+#             */
/*   Updated: 2022/03/10 17:21:41 by mahadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ppx_libft.h"

/*
*  LIBRARY
*       Standard C Library (libc, -lc)
*  
*  SYNOPSIS
*       #include <string.h>
*  
*       void *
*       memcpy(void * dst, const void * src, size_t n);
*  
*  DESCRIPTION
*       The memcpy() function copies n bytes from memory area src to memory
*       area dst.  If dst and src overlap, behavior is undefined.  Applications
*       in which dst and src might overlap should use memmove(3) instead.
*  
*  RETURN VALUES
*       The memcpy() function returns the original value of dst.
*/

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*dst_ptr;
	const unsigned char	*src_ptr;

	if (!dst && !src)
		return (NULL);
	dst_ptr = (unsigned char *)dst;
	src_ptr = (unsigned const char *)src;
	while (n > 0)
	{
		n--;
		dst_ptr[n] = src_ptr[n];
	}
	return (dst);
}
