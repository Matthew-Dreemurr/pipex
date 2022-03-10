/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   len_chrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahadad <mahadad@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 14:52:06 by mahadad           #+#    #+#             */
/*   Updated: 2021/11/09 15:44:24 by mahadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ppx_libft.h"

/**
 * @brief `strlen` but whiout crash when `NULL` and stop count when find
 *         the first occurence of char `c`
 * 
 * @param str      the tring to pars
 * @param c        the caracter to find
 * @return size_t  the number of character befor `c` (`c` include)
 */
size_t	len_chrchr(char *str, char c)
{
	char	*start;

	start = str;
	while (str && *str && *str != c)
		str++;
	if (str && *str == c)
		str++;
	else
		return (0);
	return ((size_t)(str - start));
}
