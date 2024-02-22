/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsantana <tsantana@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 18:49:26 by tsantana          #+#    #+#             */
/*   Updated: 2024/02/22 19:41:39 by tsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "elements.h"

void	free_bg_imgs(t_background *bg)
{
	if (bg->background.texture)
		mlx_delete_texture(bg->background.texture);
	if (bg->left.texture)
		mlx_delete_texture(bg->left.texture);
	if (bg->baseboard.texture)
		mlx_delete_texture(bg->baseboard.texture);
}

void	free_game(t_game *to_free)
{
	free_bg_imgs(&to_free->background);
}

