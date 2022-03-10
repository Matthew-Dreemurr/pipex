/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahadad <mahadad@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 17:06:20 by mahadad           #+#    #+#             */
/*   Updated: 2022/03/10 13:44:50 by mahadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "ppx_struct.h"

void	ppx_exit_prog(int ret, t_data *data, const char *debug);
void	ppx_populate_data(t_data *data, int ac, char **av);

#endif