/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_definition.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsantana <tsantana@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 14:19:09 by tsantana          #+#    #+#             */
/*   Updated: 2024/02/19 11:46:09 by tsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "size_definition.h"

void	tile_def(t_sizes *sizes)
{
	if ((WIDTH / sizes->x) < (HEIGHT / sizes->y))
		sizes->tile = WIDTH / sizes->x;
	else
		sizes->tile = HEIGHT / sizes->y;
}
