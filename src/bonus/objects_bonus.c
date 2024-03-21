/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsantana <tsantana@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 17:35:05 by tsantana          #+#    #+#             */
/*   Updated: 2024/03/20 21:47:11 by tsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

static void	ft_putchar(char put)
{
	write(1, &put, 1);
}

void	ft_putnumb(int n)
{
	long	num;

	num = (long)n;
	if (num <= 9)
	{
		ft_putchar(num + '0');
	}
	if (num >= 10)
	{
		ft_putnumb(num / 10);
		ft_putnumb(num % 10);
	}
}

void	objects_start(mlx_t *window_open, t_items *map_obj, t_sizes szs)
{
	map_obj->background.texture = mlx_load_png("assets/grass.png");
	map_obj->wall.texture = mlx_load_png("assets/wall.png");
	map_obj->baseboard.texture = mlx_load_png("assets/baseboard.png");
	map_obj->collectible.texture = mlx_load_png("assets/planks.png");
	map_obj->exit.texture = mlx_load_png("assets/exit.png");
	map_obj->background.img = mlx_texture_to_image
		(window_open, map_obj->background.texture);
	map_obj->wall.img = mlx_texture_to_image(window_open,
			map_obj->wall.texture);
	map_obj->exit.img = mlx_texture_to_image(window_open,
			map_obj->exit.texture);
	map_obj->collectible.img = mlx_texture_to_image(window_open,
			map_obj->collectible.texture);
	map_obj->baseboard.img = mlx_texture_to_image(window_open,
			map_obj->baseboard.texture);
	mlx_resize_image(map_obj->baseboard.img, 1920, 80);
	mlx_resize_image(map_obj->collectible.img, szs.tile, szs.tile);
	mlx_resize_image(map_obj->wall.img, szs.tile, szs.tile);
	mlx_resize_image(map_obj->exit.img, szs.tile, szs.tile);
	mlx_resize_image(map_obj->background.img, 1920, 1080);
	mlx_image_to_window(window_open, map_obj->background.img, 0, 0);
	mlx_image_to_window(window_open, map_obj->baseboard.img, 0, 1000);
}

void	obj_calculator(char value, t_sizes **count)
{
	if (value == 'C')
		(*count)->qnt_f += 1;
	else if (value == 'P')
		(*count)->qnt_p += 1;
	else if (value == 'E')
		(*count)->qnt_e += 1;
	else if (value == 'V')
		(*count)->qnt_v += 1;
}

int	start_items(t_game *gm)
{
	objects_start(gm->connect_mlx, &gm->items, gm->sizes);
	print_wall_exit(gm->connect_mlx, gm->sizes.tile, &gm->items, gm->map);
	make_player(gm->map, &gm->plr);
	if (flood_fill(gm->plr.p, gm->check) == 0)
	{
		mlx_close_window(gm->connect_mlx);
		return (0);
	}
	render_game(gm);
	gm->sizes.collect = gm->sizes.qnt_f;
	return (1);
}
