/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_elements.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsantana <tsantana@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 16:08:30 by tsantana          #+#    #+#             */
/*   Updated: 2024/02/19 18:45:42 by tsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_wall(mlx_t wndw, t_image *wall, t_sizes *size, t_data *map)
{
	t_data	*temp;

	temp = map;
	while (temp != NULL)
	{
		while (temp->line)
		{
			if (temp->line->content == '1')
			{
				mlx_resize_image(wall->img, size->tile, size->tile);
				mlx_image_to_window(&wndw, wall->img, ((map->position) * size->tile),
					(START + (map->line->position * (size->tile))));
			}
			temp->line = temp->line->next;
		}
		temp = temp->next;
	}
}
