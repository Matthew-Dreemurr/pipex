/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahadad <mahadad@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 17:06:20 by mahadad           #+#    #+#             */
/*   Updated: 2022/03/18 15:56:13 by mahadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "ppx_struct.h"

void	ppx_init_data(t_data *data, char **env);
void	ppx_init_bindir(t_data *data, char **env);
void	ppx_find_cmd_dir(t_data *data);
int		ppx_run(t_data *data);

#endif