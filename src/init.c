/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsantana <tsantana@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 17:23:51 by tsantana          #+#    #+#             */
/*   Updated: 2024/02/23 18:43:28 by tsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_sizes	*sizes_init(void)
{
	static t_sizes	variables;

	return(&variables);
}

static t_player	*p_init(void)
{
	static t_player	p;
	
	return (&p);
}

void	init_data(t_game *data)
{
	data->sizes = *sizes_init();
	data->plr = *p_init();
}

