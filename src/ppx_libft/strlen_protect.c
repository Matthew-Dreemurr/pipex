/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlen_protect.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahadad <mahadad@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 14:02:17 by mahadad           #+#    #+#             */
/*   Updated: 2022/03/10 17:20:43 by mahadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ppx_libft.h"


/**
 * @brief Strlen but dont crash with a NULL pointer.
 */
size_t	strlen_protect(const char *s)
{
	char	*start;

	start = (char *)s;
	while (s && *s)
		s++;
	return ((size_t)(s - start));
}
