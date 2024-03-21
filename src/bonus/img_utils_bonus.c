/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_utils_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsantana <tsantana@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 17:44:18 by tsantana          #+#    #+#             */
/*   Updated: 2024/03/20 21:46:49 by tsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

static void	*new_node(mlx_t *win, char *orig, t_sprites **head)
{
	t_sprites	*asset;
	t_sprites	*temp;

	temp = NULL;
	if (head != NULL)
	{
		temp = *head;
		while (temp && temp->next != NULL)
			temp = temp->next;
	}
	asset = malloc(sizeof(t_sprites));
	if (asset == NULL)
		return (NULL);
	asset->img.texture = mlx_load_png(orig);
	asset->img.img = mlx_texture_to_image(win, asset->img.texture);
	asset->previous = temp;
	asset->next = NULL;
	return (asset);
}

static void	resize_png(t_sprites *orig, t_sizes szs)
{
	t_sprites	*img;

	img = orig;
	while (img)
	{
		mlx_resize_image(img->img.img, szs.tile, szs.tile);
		img = img->next;
	}
}

void	init_villain(mlx_t *window, t_sizes szs, t_items *obj)
{
	obj->villain.top.texture = mlx_load_png("assets/villaint.png");
	obj->villain.below.texture = mlx_load_png("assets/villainb.png");
	obj->villain.left.texture = mlx_load_png("assets/villainl.png");
	obj->villain.right.texture = mlx_load_png("assets/villainr.png");
	obj->villain.top.img = mlx_texture_to_image(window, obj->villain.top.texture);
	obj->villain.below.img = mlx_texture_to_image(window,
			obj->villain.below.texture);
	obj->villain.left.img = mlx_texture_to_image(window, obj->villain.left.texture);
	obj->villain.right.img = mlx_texture_to_image(window,
			obj->villain.right.texture);
	mlx_resize_image(obj->villain.top.img, szs.tile, szs.tile);
	mlx_resize_image(obj->villain.below.img, szs.tile, szs.tile);
	mlx_resize_image(obj->villain.left.img, szs.tile, szs.tile);
	mlx_resize_image(obj->villain.right.img, szs.tile, szs.tile);
}

void	init_sprite(mlx_t *wind, t_sizes szs, t_items *obj)
{
	new_node(wind, PTOP01, &obj->player.top);
	new_node(wind, PTOP02, &obj->player.top);
	new_node(wind, PTOP03, &obj->player.top);
	new_node(wind, PTOP04, &obj->player.top);
	new_node(wind, PTOP05, &obj->player.top);
	new_node(wind, PB01, &obj->player.below);
	new_node(wind, PB02, &obj->player.below);
	new_node(wind, PB03, &obj->player.below);
	new_node(wind, PB04, &obj->player.below);
	new_node(wind, PB05, &obj->player.below);
	new_node(wind, PRIGHT01, &obj->player.right);
	new_node(wind, PRIGHT02, &obj->player.right);
	new_node(wind, PRIGHT03, &obj->player.right);
	new_node(wind, PRIGHT04, &obj->player.right);
	new_node(wind, PRIGHT05, &obj->player.right);
	new_node(wind, PLEFT01, &obj->player.left);
	new_node(wind, PLEFT02, &obj->player.left);
	new_node(wind, PLEFT03, &obj->player.left);
	new_node(wind, PLEFT04, &obj->player.left);
	new_node(wind, PLEFT05, &obj->player.left);
	resize_png(obj->player.top, szs);
	resize_png(obj->player.below, szs);
	resize_png(obj->player.right, szs);
	resize_png(obj->player.left, szs);
}
