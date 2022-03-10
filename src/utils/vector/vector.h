/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahadad <mahadad@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 23:52:54 by mahadad           #+#    #+#             */
/*   Updated: 2022/03/10 16:31:40 by mahadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# include <stddef.h>
# include "libft.h"
# ifdef WRA
#  include "wraloc.h"
# endif

# define VEC_EXIT_FAILURE ((void *)0)
# define VEC_EXIT_SUCCESS ((int)1)

# ifndef VEC_BUFFER_SIZE
#  define VEC_BUFFER_SIZE  ((unsigned long)256)
# endif

/**
 * @brief s_vector struc to manage the memory of a char array.
 * 
 * @param len      Actual size use in buff.
 * @param max      Actual max size.
 * @param buff     The buffer is alloc whit (VEC_BUFFER_SIZE + 1).
 */
typedef struct s_vector
{
	size_t	len;
	size_t	max;
	char	*buff;
}				t_vector;

char		*vect_init(t_vector *vec);
char		*vect_init_strict(t_vector *vec, size_t size);
char		*vect_resize(t_vector *vec, size_t size);
char		*vect_cat(t_vector *vec, char *str);
char		*vect_push(t_vector *vec, char c);
char		*vect_itoa_cat(int n, t_vector *vec);
char		*vect_utoa_cat(unsigned int n, t_vector *vec);
char		*vect_utohex_cat(unsigned int n, t_vector *vec, int upper);
char		*vect_ultohex_cat(size_t n, t_vector *vec, int upper);
int			putvectbuff_ret_int(t_vector *vect);
char	*vect_write(t_vector *vec, char *str);

#endif