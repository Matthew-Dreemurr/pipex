/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect_write.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahadad <mahadad@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 16:19:45 by mahadad           #+#    #+#             */
/*   Updated: 2022/03/10 16:25:44 by mahadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

/**
 * @brief Will write for the index [0], will erase the old content.
 * 
 * @return Return the actual address of `vec->buff`,
 *           if fail return VEC_EXIT_FAILURE.
 */
char	*vect_write(t_vector *vec, char *str)
{
	size_t	len;

	if (!str && !vec)
		return (VEC_EXIT_FAILURE);
	len = strlen_protect(str);
	while (vec->max < (len + 1))
		if (!vect_resize(vec, (vec->max * 2)))
			return (VEC_EXIT_FAILURE);
	vec->len = 0;
	while (*str)
		vec->buff[vec->len++] = *str++;
	vec->buff[vec->len] = '\0';
	return (vec->buff);
}
