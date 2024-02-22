/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsantana <tsantana@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 11:15:53 by tsantana          #+#    #+#             */
/*   Updated: 2024/02/22 20:06:59 by tsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "elements.h"
# include "size_definition.h"
# include <fcntl.h>
# include <unistd.h>

//int	file_to_list(char *buffer, t_sizes *sizes, t_elmnts *data);
//int	parse_map(char *file, t_game *data);
void	ft_game(t_game *game);
//void	put_wall(mlx_t wndw, t_image *wall, t_sizes *size, t_list *data);
void	init_data(t_game *data);
//int	mllc_data(t_elmnts *elem);
//int	mllc_imgs(t_background *backg);
//int	mllc_strct(t_game *game);

#endif
