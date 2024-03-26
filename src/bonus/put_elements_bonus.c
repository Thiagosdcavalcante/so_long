/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_elements_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsantana <tsantana@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 17:05:19 by tsantana          #+#    #+#             */
/*   Updated: 2024/03/25 20:44:44 by tsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

void	render_game(void *game)
{
	t_game	*gm;
	t_cllct	*lst;

	gm = (t_game *) game;
	lst = gm->cllct;
	while (lst)
	{
		if (lst->content == 'C')
			mlx_image_to_window(gm->connect_mlx, gm->items.collectible.img,
				(lst->column * gm->sizes.tile), (lst->line * gm->sizes.tile));
		lst = lst->next;
	}
	mlx_image_to_window(gm->connect_mlx, gm->items.player.img,
		(gm->plr.p->column * gm->sizes.tile),
		(gm->plr.p->line * gm->sizes.tile));
}

void	print_wall_exit(mlx_t *win, int tile, t_items *item, t_list *node)
{
	t_list	*map;

	map = node;
	while (map)
	{
		if (map->content == '1')
			mlx_image_to_window(win, item->wall.img,
				(map->column * tile), (map->line * tile));
		if (map->content == 'E')
			mlx_image_to_window(win, item->exit.img,
				(map->column * tile), (map->line * tile));
		if (map->content == 'V')
			mlx_image_to_window(win, item->villain.below.img,
				(map->column * tile), (map->line * tile));
		map = map->next;
	}
}
