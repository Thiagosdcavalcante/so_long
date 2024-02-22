/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_elements.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsantana <tsantana@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 16:08:30 by tsantana          #+#    #+#             */
/*   Updated: 2024/02/22 20:04:05 by tsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_wall(mlx_t *win, t_list *node, int tile, t_items item)
{
	t_list	*print;

	print = node;

	if (tile < 16)
	{
		mlx_resize_image(item.wall.img, 16, 16);
		mlx_image_to_window(win, item.wall.img, node->line * 16, (START + (node->column * 16)));
	}
	else 
	{
		mlx_resize_image(item.wall.img, tile, tile);
		mlx_image_to_window(win, item.wall.img, node->line * tile, (START + (node->column * tile)));
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
