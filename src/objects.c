/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsantana <tsantana@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 10:44:58 by tsantana          #+#    #+#             */
/*   Updated: 2024/02/19 18:17:17 by tsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "elements.h"

void	objects_start(mlx_t window_open, t_items *map_obj)
{
	map_obj->wall->texture = mlx_load_png("assets/wall.png");
	map_obj->player->texture = mlx_load_png("assets/player00.png");
	map_obj->fish->texture = mlx_load_png("assets/collectible.png");
	map_obj->exit->texture = mlx_load_png("assets/exit.png");
	map_obj->wall->img = mlx_texture_to_image(&window_open,
			map_obj->wall->texture);
	map_obj->player->img = mlx_texture_to_image(&window_open,
			map_obj->player->texture);
	map_obj->fish->img = mlx_texture_to_image(&window_open,
			map_obj->fish->texture);
	map_obj->exit->img = mlx_texture_to_image(&window_open,
			map_obj->exit->texture);
}

void	bg_init(mlx_t* window_open, t_background *bg_creation)
{
	bg_creation->background->texture = 
		mlx_load_png("assets/background002.png");
	bg_creation->left->texture = mlx_load_png("assets/Menu01.png");
	bg_creation->baseboard->texture = mlx_load_png("assets/rodape.png");
	bg_creation->background->img = mlx_texture_to_image
		(window_open, bg_creation->background->texture);
	bg_creation->left->img = mlx_texture_to_image
		(window_open, bg_creation->left->texture);
	bg_creation->baseboard->img = mlx_texture_to_image
		(window_open, bg_creation->baseboard->texture);
	mlx_image_to_window(window_open, bg_creation->background->img, 0, 0);
	mlx_image_to_window(window_open, bg_creation->left->img, 0, 0);
	mlx_image_to_window(window_open, bg_creation->baseboard->img, 0, 900);
}

void	obj_calculator(char value, t_elmnts *game)
{
	if (value == 'C')
		game->qnt_fish += 1;
	else if (value == 'P')
		game->qnt_player += 1;
	else if (value == 'E')
		game->qnt_exit += 1;
}
