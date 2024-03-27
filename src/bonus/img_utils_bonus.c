/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_utils_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsantana <tsantana@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 17:44:18 by tsantana          #+#    #+#             */
/*   Updated: 2024/03/25 21:32:37 by tsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

void	init_villain(mlx_t *window, t_sizes szs, t_items *obj)
{
	obj->villain.below.texture = mlx_load_png("assets/villainb.png");
	obj->villain.below.img = mlx_texture_to_image(window,
			obj->villain.below.texture);
	mlx_resize_image(obj->villain.below.img, szs.tile, szs.tile);
}
