/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_definition.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsantana <tsantana@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 14:19:09 by tsantana          #+#    #+#             */
/*   Updated: 2024/02/22 19:47:34 by tsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "size_definition.h"
#include <stdio.h>

int	tile_def(int x, int y)
{
	if ((WIDTH / x) < (HEIGHT / y))
		return (WIDTH / x);
	else
		return (HEIGHT / y);
}
