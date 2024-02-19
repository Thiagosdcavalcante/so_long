/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsantana <tsantana@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 18:49:26 by tsantana          #+#    #+#             */
/*   Updated: 2024/02/19 15:56:17 by tsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "elements.h"

static void	del_textures(t_items *items, t_background *bg)
{
	if (items->wall->texture)
		mlx_delete_texture(items->wall->texture);
	if (items->fish->texture)
		mlx_delete_texture(items->fish->texture);
	if (items->exit->texture)
		mlx_delete_texture(items->exit->texture);
	if (items->player->texture)
		mlx_delete_texture(items->player->texture);
	if (bg->background->texture)
		mlx_delete_texture(bg->background->texture);
	if (bg->left->texture)
		mlx_delete_texture(bg->left->texture);
	if (bg->baseboard->texture)
		mlx_delete_texture(bg->baseboard->texture);
}

void	free_imgs(t_items *items, t_background *bg)
{
	del_textures(items, bg);
	if (items->wall)
		free(items->wall);
	if (items->fish)
		free(items->fish);
	if (items->exit)
		free(items->exit);
	if (items->player)
		free(items->player);
	if (items)
		free(items);
	if (bg->left)
		free(bg->left);
	if (bg->background)
		free(bg->background);
	if (bg->baseboard)
		free(bg->baseboard);
	if (bg)
		free(bg);
}

void	ft_free_dt(t_eledata *data, t_sizes *sizes)
{
	if (sizes)
		free(sizes);
	if (data->map)
		ft_columnsclear(&data->map);
	if (data->player->p)
		ft_lstclear(&data->player->p);
	if (data->player->w)
		ft_lstclear(&data->player->w);
	if (data->player->s)
		ft_lstclear(&data->player->s);
	if (data->player->a)
		ft_lstclear(&data->player->a);
	if (data->player->d)
		ft_lstclear(&data->player->d);
}

void	free_game(t_elmnts *to_free)
{
	ft_free_dt(to_free->data, to_free->sizes);
	free_imgs(to_free->items, to_free->background);
}

