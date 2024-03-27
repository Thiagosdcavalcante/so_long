/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsantana <tsantana@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 21:59:03 by tsantana          #+#    #+#             */
/*   Updated: 2024/03/25 21:38:34 by tsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

static void	aux_ff(t_list **map, int line, int column)
{
	t_list	*check;

	check = *map;
	while (check && !(check->line == line && check->column == column))
		check = check->next;
	if (check->content == '1' || check->content == 'Z' || check->content == 'V')
		return ;
	check->content = 'Z';
	aux_ff(map, (check->line - 1), check->column);
	aux_ff(map, (check->line + 1), check->column);
	aux_ff(map, check->line, (check->column + 1));
	aux_ff(map, check->line, (check->column - 1));
}

int	flood_fill(t_list *plr, t_list *map)
{
	t_list	*lst;

	lst = map;
	while (lst && !(lst->content == 'P'))
		lst = lst->next;
	aux_ff(&map, plr->line, plr->column);
	while (map)
	{
		if (!((map->content == 'Z' || map->content == '1'
					|| map->content == 'V')
				|| map->content == '0'))
			return (write(2, "Error!\nImpossible to Win!\n", 26), 0);
		map = map->next;
	}
	return (1);
}
