/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsantana <tsantana@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 11:15:53 by tsantana          #+#    #+#             */
/*   Updated: 2024/03/21 19:56:01 by tsantana         ###   ########.fr       */
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
int		plr_exit(t_game *gm);
void	print_objcts(mlx_t *mlx, t_list *gm, t_items *item, t_sizes szs);
void	def_size(char *buf, t_sizes *sz);
void	init_gm(t_game *game);
void	render_game(void *game);
void	ft_putnumb(int n);
void	print_moves(t_sizes *infor);
void	plr_cllct(t_player *p, t_sizes *szs, t_cllct *cllct);
void	reload_render(t_game *gm);
void	def_p_around(int i, int j, t_list *mp_p, t_player *plr);
void	cllct_work(t_cllct **cllct, int ln, int cl);

#endif
