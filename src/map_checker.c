/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsantana <tsantana@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:11:19 by tsantana          #+#    #+#             */
/*   Updated: 2024/02/22 19:37:59 by tsantana         ###   ########.fr       */
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

// int	items_checker(char map_char, int fish, int player, int exit)
// {
// 	int	*collectible;
// 	int	*p_count;
// 	int	*e_count;
// 	int	i;
//
// 	collectible = fish;
// 	p_count = player;
// 	e_count = exit;
// 	i = 0;
// 	while (MAP_ITEMS[i] != '\0')
// 	{
// 		if (MAP_ITEMS[i] == map_char)
// 		{
// 			if (map_char == 'C' || map_char == 'P' || map_char == 'E')
// 			{
// 				if (map_char == 'C')
// 					collectible += 1;
// 				else if (map_char == 'P')
// 					p_count += 1;
// 				else if (map_char == 'E')
// 					e_count += 1;
// 			}
// 			if (*p_count > 1 || *e_count > 1)
// 				return (write (2, "Error!\nIvalid Map - More than 1 E or P", 38), 1);
// 			return (0);
// 		}
// 		i++;
// 	}
// 	return (1);
// }
