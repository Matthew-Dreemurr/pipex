/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahadad <mahadad@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 17:21:18 by mahadad           #+#    #+#             */
/*   Updated: 2022/03/13 12:58:28 by mahadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ppx_libft.h"
#include <stdlib.h>

/*
* SYNOPSIS
*  #include <stdlib.h>
*
*  void *
*  calloc(size_t count, size_t size);
*
* DESCRIPTION
*  The malloc(), calloc(), valloc(), realloc(), and reallocf() functions
*  allocate memory.  The allocated memory is aligned such that it can be
*  used for any data type, including AltiVec- and SSE-related types.  The
*  aligned_alloc() function allocates memory with the requested alignment.
*  The free() function frees allocations that were created via the preceding
*  allocation functions.
*
*  The calloc() function contiguously allocates enough space for count
*  objects that are size bytes of memory each and returns a pointer to the
*  allocated memory.  The allocated memory is filled with bytes of value
*  zero.
*
* RETURN VALUES
*  If successful, calloc(), malloc(), realloc(), reallocf(), valloc(), and
*  aligned_alloc() functions return a pointer to allocated memory.  If there
*  is an error, they return a NULL pointer and set errno to ENOMEM.
*/

void	*ft_calloc(size_t count, size_t size)
{
	void	*mem;

	mem = (void *)malloc(count * size);
	if (!mem)
		return (NULL);
	ft_bzero(mem, count * size);
	return (mem);
}
