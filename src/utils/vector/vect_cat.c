/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect_cat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahadad <mahadad@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 13:31:01 by mahadad           #+#    #+#             */
/*   Updated: 2022/03/10 17:20:34 by mahadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "ppx_libft.h"

/**
 * @brief
 * 
 * @param vec 
 * @param str 
 * @return int 
 */
char	*vect_cat(t_vector *vec, char *str)
{
	size_t	len;

	if (!str && !vec)
		return (VEC_EXIT_FAILURE);
	len = strlen_protect(str);
	while (vec->max < (vec->len + (len + 1)))
		if (!vect_resize(vec, (vec->max * 2) + len))
			return (VEC_EXIT_FAILURE);
	while (*str)
		vec->buff[vec->len++] = *str++;
	vec->buff[vec->len] = '\0';
	return (vec->buff);
}
