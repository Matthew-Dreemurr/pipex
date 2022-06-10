/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ppx_debug.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahadad <mahadad@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 11:13:11 by mahadad           #+#    #+#             */
/*   Updated: 2022/06/10 13:46:32 by mahadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PPX_DEBUG_H
# define PPX_DEBUG_H

# ifndef PPX_DEBUG
#  define PPX_DEBUG 0
# endif

# ifndef PPX_DEBUG2
#  define PPX_DEBUG2 0
# endif

# define P_EXIT_FAILURE -1
# define P_EXIT_SUCCESS  1

# ifdef WRA
#  include "wraloc.h"
# endif

#endif