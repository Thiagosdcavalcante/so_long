/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsantana <tsantana@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 17:04:07 by tsantana          #+#    #+#             */
/*   Updated: 2024/03/25 21:13:48 by tsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/MLX42.h"
#include "elements.h"
#include "so_long.h"

void	reload_render(t_game *gm)
{
	t_cllct	*collect;

	collect = gm->cllct;
	mlx_delete_image(gm->connect_mlx, gm->items.collectible.img);
	mlx_delete_image(gm->connect_mlx, gm->items.player.img);
	gm->items.collectible.img = mlx_texture_to_image(gm->connect_mlx,
			gm->items.collectible.texture);
	gm->items.player.img = mlx_texture_to_image(gm->connect_mlx,
			gm->items.player.texture);
	mlx_resize_image(gm->items.collectible.img, gm->sizes.tile, gm->sizes.tile);
	mlx_resize_image(gm->items.player.img, gm->sizes.tile, gm->sizes.tile);
	while (collect)
	{
		if (collect->active == 1)
			mlx_image_to_window(gm->connect_mlx, gm->items.collectible.img,
				(gm->sizes.tile * collect->column),
				gm->sizes.tile * collect->line);
		collect = collect -> next;
	}
	mlx_image_to_window(gm->connect_mlx, gm->items.player.img,
		(gm->sizes.tile * gm->plr.p->column), gm->sizes.tile
		* gm->plr.p->line);
}

void	def_p_around(int i, int j, t_list *mp_p, t_player *plr)
{
	t_list	*map;

	map = mp_p;
	while (map)
	{
		if (map->line == (i - 1) && map->column == j)
			plr->w = map;
		else if (map->line == i && map->column == (j - 1))
			plr->a = map;
		else if (map->line == i && map->column == (j + 1))
			plr->d = map;
		else if (map->line == (i + 1) && map->column == j)
			plr->s = map;
		map = map -> next;
	}
}

void	make_player(t_list *mp_to_p, t_player *plr)
{
	t_list	*map;

	map = mp_to_p;
	while (map)
	{
		if (map->content == 'P')
		{
			plr->p = map;
			break ;
		}
		map = map->next;
	}
	def_p_around(plr->p->line, plr->p->column, mp_to_p, plr);
}

void	cllct_work(t_cllct **cllct, int ln, int cl)
{
	t_cllct	*coll;

	coll = *cllct;
	while (coll)
	{
		if (coll->line == ln && coll->column == cl)
			coll->active = 0;
		coll = coll->next;
	}
}

void	plr_remake(t_game *gm, char move)
{
	t_list	*map;

	map = gm->map;
	if (move == 'w' && gm->plr.w->content != '1')
	{
		print_moves(&gm->sizes);
		gm->plr.p = gm->plr.w;
	}
	else if (move == 's' && gm->plr.s->content != '1')
	{
		print_moves(&gm->sizes);
		gm->plr.p = gm->plr.s;
	}
	else if (move == 'd' && gm->plr.d->content != '1')
	{
		print_moves(&gm->sizes);
		gm->plr.p = gm->plr.d;
	}
	else if (move == 'a' && gm->plr.a->content != '1')
	{
		print_moves(&gm->sizes);
		gm->plr.p = gm->plr.a;
	}
	if (plr_exit(gm) == 0)
		mlx_close_window(gm->connect_mlx);
}
