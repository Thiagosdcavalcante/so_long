/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsantana <tsantana@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 11:15:53 by tsantana          #+#    #+#             */
/*   Updated: 2024/02/19 17:56:45 by tsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "elements.h"
# include "size_definition.h"

typedef struct	s_game
{
	mlx_t	*connect_mlx;
	t_elmnts elemnts;
}	t_game;

int	file_to_list(char *buffer, t_sizes *sizes, t_elmnts *data);
int	parse_map(char *file, t_game *data);
int	ft_game(t_game *game, char *file);
void	put_wall(mlx_t wndw, t_image *wall, t_sizes *size, t_data *data);
int	mllc_data(t_eledata *data, t_sizes *sizes);
int	mllc_imgs(t_items *items, t_background *backg);
int	mllc_strct(t_game *game);
t_sizes	*sizes_init(void);

#endif
