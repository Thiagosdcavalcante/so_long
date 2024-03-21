/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsantana <tsantana@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 11:15:53 by tsantana          #+#    #+#             */
/*   Updated: 2024/03/18 15:59:55 by tsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "elements.h"
# include <fcntl.h>
# include <unistd.h>

int		ft_game(t_game *game, char *file);
int		read_map(int fd, char *buf);
int		flood_fill(t_list *plr, t_list *map);
int		start_items(t_game *gm);
int		validations_lines(t_game *gm, char *bfr);
void	print_objcts(mlx_t *mlx, t_list *gm, t_items *item, t_sizes szs);
void	def_size(char *buf, t_sizes *sz);
void	init_gm(t_game *game);
void	render_game(void *game);
void	ft_putnumb(int n);

#endif
