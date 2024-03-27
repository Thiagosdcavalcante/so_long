/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils2_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsantana <tsantana@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 20:58:02 by tsantana          #+#    #+#             */
/*   Updated: 2024/03/25 21:44:54 by tsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

void	print_moves(mlx_t *mlx, t_sizes *infor, mlx_image_t **counter)
{
	char	*str_itoa;

	if (counter)
		mlx_delete_image(mlx, *counter);
	(*infor).moves++;
	write(1, "moves: ", 7);
	ft_putnumb((*infor).moves);
	write(1, "\n", 1);
	str_itoa = ft_itoa((*infor).moves);
	*counter = mlx_put_string(mlx, str_itoa, 1800, 940);
	mlx_resize_image(*counter, 40, 40);
	free(str_itoa);
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
	if ((gm->plr.p->content == 'E' && gm->sizes.collect == 0)
		|| gm->plr.p->content == 'V')
	{
		if (gm->plr.p->content == 'V')
			write(1, "GAME OVER!\n", 11);
		else
			write(1, "YOU WIN!\n", 9);
		mlx_close_window(gm->connect_mlx);
		return (0);
	}
	return (1);
}
