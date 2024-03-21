/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsantana <tsantana@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 17:39:06 by tsantana          #+#    #+#             */
/*   Updated: 2024/03/20 21:46:54 by tsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

void	free_bg_imgs(t_items *img)
{
	if (img->background.texture)
		mlx_delete_texture(img->background.texture);
	if (img->baseboard.texture)
		mlx_delete_texture(img->baseboard.texture);
	if (img->wall.texture)
		mlx_delete_texture(img->wall.texture);
	if (img->collectible.texture)
		mlx_delete_texture(img->collectible.texture);
	if (img->exit.texture)
		mlx_delete_texture(img->exit.texture);
}

void	free_game(t_game *to_free)
{
	free_bg_imgs(&to_free->items);
	if (to_free->cllct)
		ft_cllctclear(&to_free->cllct);
	if (to_free->map)
		ft_lstclear(&to_free->map);
	if (to_free->check)
		ft_lstclear(&to_free->check);
}
