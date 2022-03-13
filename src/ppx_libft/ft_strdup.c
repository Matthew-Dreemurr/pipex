/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahadad <mahadad@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 17:57:34 by mahadad           #+#    #+#             */
/*   Updated: 2022/03/13 13:03:31 by mahadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ppx_libft.h"
#include <stdlib.h>

/*
* SYNOPSIS
*   #include <string.h>
*
*   char *
*   strdup(const char *s1);
*
* DESCRIPTION
*   The strdup() function allocates sufficient memory for a copy of the
*   string s1, does the copy, and returns a pointer to it.  The pointer may
*   subsequently be used as an argument to the function free(3).
*
*   If insufficient memory is available, NULL is returned and errno is set to
*   ENOMEM.
*
*   The strndup() function copies at most n characters from the string s1
*   always NUL terminating the copied string.
*/

static size_t	fk_strlen(const char *str)
{
	const char	*start;

	start = str;
	while (str && *str)
		str++;
	return ((size_t)(str - start));
}

char	*ft_strdup(const char *s1)
{
	char	*ret;
	char	*start;

	ret = (char *)ft_calloc((fk_strlen(s1) + 1), sizeof(char));
	if (!ret)
		return (NULL);
	start = ret;
	while (*s1)
	{
		*ret = *s1;
		ret++;
		s1++;
	}
	*ret = '\0';
	return (start);
}
