/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsantana <tsantana@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 21:51:30 by tsantana          #+#    #+#             */
/*   Updated: 2024/03/21 22:57:36 by tsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

static int	dotber_checker(char *arch_name)
{
	int		len;
	int		result;
	char	*dotber;

	dotber = ".ber";
	result = 0;
	len = 0;
	while (arch_name[len])
		len++;
	len -= 4;
	while (*dotber)
		result += (arch_name[len++] - *dotber++);
	return (result);
}

int	args_verify(int c, char *v)
{
	if (c < 2)
		return (write(2, "Error\nNot Enough Argso!\n", 24), 0);
	else if (c > 2)
		return (write(2, "Error\nToo Many Args!\n", 21), 0);
	else
	{
		if (dotber_checker(v) != 0)
			return (write(2, "Error\nNot a .ber file!\n", 23), 0);
		else
			return (1);
	}
}

int	check_char(char c)
{
	if (c == '1' || c == '0' || c == 'C' || c == 'P' || c == 'E' || c == 'V')
		return (1);
	return (write(2, "Error\nMap has wrong elements!\n", 30), 0);
}

int	wall_check(char ch, int c, int l, t_sizes *size)
{
	if (c == 0 && ch != '1')
		return (0);
	else if (l == 0 && ch != '1')
		return (0);
	else if (l == size->y && ch != '1')
		return (0);
	else if (c == size->x && ch != '1')
		return (0);
	return (1);
}
