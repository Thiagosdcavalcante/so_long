/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_elements.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsantana <tsantana@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 16:08:30 by tsantana          #+#    #+#             */
/*   Updated: 2024/02/23 20:25:23 by tsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	print_fish(mlx_t *win, t_list *node, int tile, t_items item)
{
	t_list	*print;

	print = node;

	if (tile < 16)
	{
		mlx_resize_image(item.fish.img, 16, 16);
		mlx_image_to_window(win, item.fish.img, START + (node->line * 16), node->column * 16);
	}
	else 
	{
		mlx_resize_image(item.fish.img, tile, tile);
		mlx_image_to_window(win, item.fish.img, (START + (node->column * tile)), (node->line * tile));
	}
}

static void	print_exit(mlx_t *win, t_list *node, int tile, t_items item)
{
	t_list	*print;

	print = node;

	if (tile < 16)
	{
		mlx_resize_image(item.exit.img, 16, 16);
		mlx_image_to_window(win, item.exit.img, START + (node->line * 16), node->column * 16);
	}
	else 
	{
		mlx_resize_image(item.exit.img, tile, tile);
		mlx_image_to_window(win, item.exit.img, (START + (node->column * tile)), (node->line * tile));
	}
}

void	print_objcts(t_game *gm)
{
	t_list	*map;

	map = gm->map;
	while(map)
	{
		if (map->content == '1')
			print_wall(gm->connect_mlx, map, gm->sizes.tile, gm->items);
		else if (map->content == 'C')
			print_fish(gm->connect_mlx, map, gm->sizes.tile, gm->items);
		else if (map->content == 'E')
			print_exit(gm->connect_mlx, map, gm->sizes.tile, gm->items);
		map = map->next;
	}
}

void	print_wall(mlx_t *win, t_list *node, int tile, t_items item)
{
	t_list	*print;

	print = node;

	if (tile < 16)
	{
		mlx_resize_image(item.wall.img, 16, 16);
		mlx_image_to_window(win, item.wall.img, START + (node->line * 16), node->column * 16);
	}
	else 
	{
		mlx_resize_image(item.wall.img, tile, tile);
		mlx_image_to_window(win, item.wall.img, (START + (node->column * tile)), (node->line * tile));
	}
}


// {
// 	t_data	*temp;
//
// 	temp = map;
// 	while (temp != NULL)
// 	{
// 		while (temp->line)
// 		{
// 			if (temp->line->content == '1')
// 			{
// 				mlx_resize_image(wall->img, size->tile, size->tile);
// 				mlx_image_to_window(&wndw, wall->img, ((map->position) * size->tile),
// 					(START + (map->line->position * (size->tile))));
// 			}
// 			temp->line = temp->line->next;
// 		}
// 		temp = temp->next;
// 	}
// }
