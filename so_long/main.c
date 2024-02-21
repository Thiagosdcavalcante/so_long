/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsantana <tsantana@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 16:58:05 by tsantana          #+#    #+#             */
/*   Updated: 2024/02/21 14:28:35 by tsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src/so_long.h"

static void	control_hooks(mlx_key_data_t keydata, void *param)
{
	t_game	*infor;

	infor = (t_game *)param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(infor->connect_mlx);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc == 2)
	{
		// if (mllc_strct(&game) == 1)
		// 	free_game(&game.elemnts);
		game.connect_mlx = mlx_init(1920, 1080, "Minha Primeira tela", true);
		if (!game.connect_mlx)
			return (1);
		// if (parse_map(argv[1], &game) == 1)
		// 	mlx_close_window(game.connect_mlx);
		ft_game(&game, argv[4]);
		mlx_key_hook(game.connect_mlx, &control_hooks, &game);
		mlx_loop(game.connect_mlx);
	}
	mlx_terminate(game.connect_mlx);
	free_game(&game.elemnts);
	return (0);
}
