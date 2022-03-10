/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahadad <mahadad@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 18:36:41 by mahadad           #+#    #+#             */
/*   Updated: 2022/03/10 14:44:31 by mahadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ppx_libft.h"

#include "ppx_debug.h"

/*
*  SYNOPSIS
*    #include <string.h>
*
*    int
*    strncmp(const char *s1, const char *s2, size_t n);
*
*  DESCRIPTION
*    The strcmp() and strncmp() functions lexicographically compare the null-
*    terminated strings s1 and s2.
*
*    The strncmp() function compares not more than n characters.  Because
*    strncmp() is designed for comparing strings rather than binary data,
*    characters that appear after a `\0' character are not compared.
*
*  RETURN VALUES
*    The strcmp() and strncmp() functions return an integer greater than,
*    equal to, or less than 0, according as the string s1 is greater than,
*    equal to, or less than the string s2.  The comparison is done using
*    unsigned characters, so that `\200' is greater than `\0'.
*/

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (!n)
		return (0);
	while (*s1 && *s2 && (*s2 == *s1))
	{
		n--;
		if (!n)
			break ;
		s1++;
		s2++;
	}
	return ((int)((unsigned char)*s1 - (unsigned char)*s2));
}
