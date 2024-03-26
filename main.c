/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsantana <tsantana@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 16:58:05 by tsantana          #+#    #+#             */
/*   Updated: 2024/03/23 17:41:35 by tsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src/so_long.h"

int	main(int argc, char **argv)
{
	static t_game	game;

	if (args_verify(argc, argv[1]) == 1)
	{
		game.connect_mlx = mlx_init(1920, 1080, "SO_LONG", true);
		if (game.connect_mlx)
		{
			game.check = NULL;
			game.map = NULL;
			game.cllct = NULL;
			game.plr = (t_player){0};
			game.sizes = (t_sizes){0};
			ft_game(&game, argv[1]);
		}
		else
			return ((write(2, "Error\nSomething Wrong With the Window(mlz)!\n",
						44)), 0);
	}
	else
		return (write(2, "Error\nMust to pass two args!\n", 29), 1);
	mlx_terminate(game.connect_mlx);
	free_game(&game);
	return (0);
}
