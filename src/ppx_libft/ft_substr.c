/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahadad <mahadad@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 14:20:29 by mahadad           #+#    #+#             */
/*   Updated: 2021/10/20 12:46:47 by mahadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ppx_libft.h"
#include <stdlib.h>

/**
 * @brief Allocates (with malloc(3)) and returns a substring
 *        from the string ’s’.
 *        The substring begins at index ’start’ and is of maximum size ’len’.
 * 
 * @param s      The string from which to create the substring.
 * @param start  The start index of the substring in the string ’s’.
 * @param len    The maximum length of the substring.
 * @return char* The substring. NULL if the allocation fails.
 */
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	len_alloc;
	char	*str;
	char	*str_ptr;

	if (!s)
		return (NULL);
	while (*s && start--)
		s++;
	len_alloc = strlen_protect(s);
	len_alloc = (size_t []){len, len_alloc}[len_alloc < len];
	str = (char *)malloc((len_alloc + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str_ptr = str;
	while (len_alloc-- > 0)
		*str_ptr++ = *s++;
	*str_ptr = '\0';
	return (str);
}
