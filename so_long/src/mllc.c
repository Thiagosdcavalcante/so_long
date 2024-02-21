/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mllc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsantana <tsantana@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 16:15:16 by tsantana          #+#    #+#             */
/*   Updated: 2024/02/21 14:46:31 by tsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_player	*p_init(void)
{
	static t_player	p;
	
	return (&p);
}

static int	init_data(t_eledata *data, t_sizes *sizes)
{
	sizes->y = 0;
	sizes->x = 0;
	sizes->tile = 0;
	data->map->line = malloc(sizeof(t_list));
	data->player.p = malloc(sizeof(t_list *));
	if (!data->map->line || !data->player.p)
		return (1);
	data->map->line->position = 0;
	data->player.w = malloc(sizeof(t_list *));
	data->player.s = malloc(sizeof(t_list *));
	data->player.a = malloc(sizeof(t_list *));
	data->player.d = malloc(sizeof(t_list *));
	if (!data->player.w || !data->player.s || !data->player.a ||
		!data->player.d)
		return (1);
	data->map = ft_newcolumns('1', 0, 0);
	data->player = *p_init();
	return (0);
}

int	mllc_data(t_elmnts *elem)
{
	// elem->data = mallog(sizeof(t_eledata));
	elem->data.map = malloc(sizeof(t_data));
	elem->data.map->position = 0;
	// elem->sizes = malloc(sizeof(t_sizes));
	// elem->data.player = malloc(sizeof(t_player));
	elem->data.player.p = malloc(sizeof(t_list));
	if (!elem->data.map || !elem->data.player.p)
		return (ft_free_dt(&elem->data), 1);
	elem->data.player.w = malloc(sizeof(t_list));
	elem->data.player.s = malloc(sizeof(t_list));
	elem->data.player.a = malloc(sizeof(t_list));
	elem->data.player.d = malloc(sizeof(t_list));
	if (!elem->data.player.w || !elem->data.player.s ||
		!elem->data.player.a || !elem->data.player.d)
		return (ft_free_dt(&elem->data), 1);
	if (init_data(&elem->data, &elem->sizes) == 1)
		return (ft_free_dt(&elem->data), 1);
	return (0);
}

int	mllc_imgs(t_background *backg)
{
	backg->background.texture = malloc(sizeof(mlx_texture_t));
	backg->background.img = malloc(sizeof(mlx_image_t));
	backg->baseboard.texture = malloc(sizeof(mlx_texture_t));
	backg->baseboard.img = malloc(sizeof(mlx_image_t));
	backg->left.texture = malloc(sizeof(mlx_texture_t));
	backg->left.img = malloc(sizeof(mlx_image_t));
//	items = malloc(sizeof(t_items));
	//if (!items)
	//	return (free_imgs(items, backg), 1);
	// items->player = malloc(sizeof(t_image));
	// items->exit = malloc(sizeof(t_image));
	// items->fish = malloc(sizeof(t_image));
	// items->wall = malloc(sizeof(t_image));
	// if (!items->wall || !items->player || !items->exit || !items->fish)
	// 	return (free_imgs(items, backg), 1);
//	backg = malloc(sizeof(t_background));
	// backg->baseboard = malloc(sizeof(t_image));
	// backg->background = malloc(sizeof(t_image));
	// backg->left = malloc(sizeof(t_image));
	// if (!backg->baseboard || !backg->background	|| !backg->left
	// 	|| !backg)
	// 	return (free_imgs(items, backg), 1);
	return (0);
}

int	mllc_strct(t_game *game)
{
	// game->elemnts = malloc(sizeof(t_elmnts));
	// if (!game->elemnts)
	// 	return (write(2, "Error!\n", 7), 1);
	if ((mllc_imgs(&game->elemnts.background) == 1) ||
		(mllc_data(&game->elemnts) == 1))
	{
		free_imgs(&game->elemnts.background);
	//	ft_free_dt(&game->elemnts.data);
		return (write(2, "Error!\nSomething wrong with data and img!", 41), 1);
	}
	return (0);
}
