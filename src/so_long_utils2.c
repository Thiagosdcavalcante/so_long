/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsantana <tsantana@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 18:24:49 by tsantana          #+#    #+#             */
/*   Updated: 2024/03/23 17:07:31 by tsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "elements.h"
#include "so_long.h"

void	print_moves(t_sizes *infor)
{
	(*infor).moves++;
	write(1, "moves: ", 7);
	ft_putnumb((*infor).moves);
	write(1, "\n", 1);
}

void	plr_cllct(t_player *p, t_sizes *szs, t_cllct *cllct)
{
	if (p->p->content == 'C')
	{
		szs->collect--;
		p->p->content = '0';
		cllct_work(&cllct, p->p->line, p->p->column);
	}
}

int	plr_exit(t_game *gm)
{	
	plr_cllct(&gm->plr, &(gm->sizes), gm->cllct);
	def_p_around(gm->plr.p->line, gm->plr.p->column, gm->map, &gm->plr);
	reload_render(gm);
	if (gm->plr.p->content == 'E' && gm->sizes.collect == 0)
	{
		mlx_close_window(gm->connect_mlx);
		return (0);
	}
	return (1);
}
