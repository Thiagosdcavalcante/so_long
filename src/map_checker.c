/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsantana <tsantana@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:11:19 by tsantana          #+#    #+#             */
/*   Updated: 2024/02/23 20:01:53 by tsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "elements.h"

int	dotber_checker(char *arch_name)
{
	char	*dotber;
	int	len;
	int	result;

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
		return (write(2,"Error\nNot Enough Args!", 23), 1);
	else if (c > 2)
		return (write(2, "Error!\nToo Many Args!", 21), 1);
	else
	{
		if (dotber_checker(v) != 0)
			return (write(2,"Error\nNot a .ber file!", 22), 1);
		else
			return (0);
	}
}

int	check_char(char c)
{
	return (c == '1' || c == '0' || c == 'C' || c == 'E' || c == 'P');
}

int	item_check(char ch, int c, int l, t_sizes *size)
{
	if (check_char(ch) != 1)
		return (1);
	if (c == 0 && ch != '1')
		return (1);
	else if (l == 0 && ch != '1')
		return (1);
	else if (l == size->y && ch != '1')
		return (1);
	else if (c == size->x && ch != '1')
		return (1);
	else
		return (obj_calculator(ch, size), 0);
}
