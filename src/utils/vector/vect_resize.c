/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect_resize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahadad <mahadad@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 13:24:27 by mahadad           #+#    #+#             */
/*   Updated: 2021/11/26 23:54:16 by mahadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include <stdlib.h>

/**
 * @brief Resize the buffer wit `size`.
 * 
 * @param vec 
 * @param size 
 * @return char* 
 */
char	*vect_resize(t_vector *vec, size_t size)
{
	char	*tmp;

	if (!vec || !vec->max)
		return (VEC_EXIT_FAILURE);
	tmp = vec->buff;
	vec->max = size;
	vec->buff = (char *)malloc(vec->max);
	if (!vec->buff)
	{
		vec->buff = tmp;
		return (VEC_EXIT_FAILURE);
	}
	ft_memcpy(vec->buff, tmp, vec->len);
	free(tmp);
	return (vec->buff);
}
