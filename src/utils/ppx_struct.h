/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ppx_struct.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahadad <mahadad@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 11:22:26 by mahadad           #+#    #+#             */
/*   Updated: 2022/03/10 15:46:53 by mahadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PPX_STRUCT_H
# define PPX_STRUCT_H

typedef struct s_bin
{
	char	*cmd;
	char	*flag;
	char	*path;
	char	**array;
}				t_bin;

typedef struct s_data
{
	t_bin	*bin;
	char	*env;
	int		ac;
	char	**av;
	char	**bin_dir;
}				t_data;

#endif
