/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_definition.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsantana <tsantana@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 14:19:09 by tsantana          #+#    #+#             */
/*   Updated: 2024/03/21 20:54:00 by tsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "elements.h"

static int	tile_def(int x, int y)
{
	int	height;
	int	width;

	height = 1060;
	width = 1920;
	if ((width / x) < (height / y))
		return (width / x);
	else
		return (height / y);
}

static int	x_line(char *str, t_sizes *size_obj)
{
	int	counter;

	counter = 0;
	while (str[counter] && str[counter] != '\n')
	{
		if (wall_check(str[counter], counter, 0, size_obj) == 1)
			counter++;
		else
			return (write(2, "Error\nFind Wrong char in the file!\n", 35), 0);
	}
	return (counter);
}

static int	item_check(char *buf, t_sizes *szs)
{
	int	i_buf;

	i_buf = 0;
	while (buf[i_buf])
	{
		obj_calculator(buf[i_buf], &szs);
		i_buf++;
	}
	if (szs->qnt_p != 1 || szs->qnt_f < 1 || szs->qnt_e != 1)
		return (write(2, "Error\nWrong qnt of items in the map!\n", 38), 0);
	return (1);
}

int	validations_lines(t_game *gm, char *bfr)
{
	int	i;
	int	nline;

	i = 1;
	nline = 1;
	if (item_check(bfr, &gm->sizes) != 1)
		return (0);
	gm->sizes.x = x_line(bfr, &gm->sizes);
	if (gm->sizes.x == 0)
		return (0);
	while (*bfr++ != '\0')
	{
		if (*bfr == '\n' && ((i / nline != gm->sizes.x)))
			return (write(2, "Error\nAll Lines Must Be Equal!\n", 32), 0);
		i++;
		if (*bfr == '\n')
			nline++;
	}
	gm->sizes.y = nline;
	gm->sizes.tile = tile_def(gm->sizes.x, gm->sizes.y);
	return (1);
}
