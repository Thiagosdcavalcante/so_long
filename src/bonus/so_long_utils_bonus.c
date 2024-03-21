/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsantana <tsantana@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 17:17:39 by tsantana          #+#    #+#             */
/*   Updated: 2024/03/20 21:46:30 by tsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

static void	control_hooks(mlx_key_data_t keydata, void *param)
{
	t_game	*infor;

	infor = (t_game *)param;
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		plr_remake(infor, 'a');
	else if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		plr_remake(infor, 'w');
	else if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		plr_remake(infor, 'd');
	else if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		plr_remake(infor, 's');
	else if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(infor->connect_mlx);
	infor->sizes.moves += 1;
	write(1, "moves: ", 7);
	ft_putnumb(infor->sizes.moves);
	write(1, "\n", 1);
}

void	file_to_cllct(char *bffr, t_cllct **collect)
{
	int		line;
	int		column;
	int		index;
	t_cllct	*temp;

	index = 0;
	column = 0;
	line = 0;
	while (bffr[index] != '\0')
	{
		while (bffr[index] != '\0' && bffr[index] != '\n')
		{
			if (bffr[index] == 'C')
			{
				temp = ft_cllctnew(bffr[index], line, column);
				ft_cllctadd_back(collect, temp);
			}
			index++;
			column++;
		}
		index++;
		column = 0;
		line++;
	}
}

int	file_list(char *bffr, t_list **map)
{
	int		line;
	int		column;
	int		idx;
	t_list	*tmp;

	idx = 0;
	column = 0;
	line = 0;
	while (bffr[idx] != '\0')
	{
		while (bffr[idx] != '\0' && bffr[idx] != '\n')
		{
			if (check_char(bffr[idx]) == 0)
				return (0);
			tmp = ft_lstnew(bffr[idx], line, column);
			ft_lstadd_back(map, tmp);
			idx++;
			column++;
		}
		if (bffr[idx] == '\n')
			idx++;
		column = 0;
		line++;
	}
	return (1);
}

int	read_map(int fd, char *buf)
{
	size_t	bytes_read;

	bytes_read = 0;
	bytes_read = read(fd, buf, BUFFERSIZE);
	buf[bytes_read + 1] = '\0';
	if (bytes_read < 15 || bytes_read > 6914)
		return (write (2, "Error!\nMap Is Too Small or Too Big to Render!\n",
				46), 0);
	return (0);
}

int	ft_game(t_game *game, char *file)
{
	static char	buf[BUFFERSIZE];
	size_t		fd;

	fd = 0;
	fd = open(file, O_RDONLY);
	if (fd < 1)
		return (write (2, "Error!\nSomething Wrong with File!\n", 34), 0);
	if (read_map(fd, buf) == 1)
		return (0);
	close(fd);
	if (validations_lines(game, buf) == 1)
	{
		if (file_list(buf, &game->map) == 0)
			return (0);
		file_list(buf, &game->check);
		file_to_cllct(buf, &game->cllct);
		if (start_items(game) == 0)
			return (0);
		mlx_key_hook(game->connect_mlx, &control_hooks, &game->connect_mlx);
		mlx_loop(game->connect_mlx);
	}
	else
		return (0);
	return (1);
}
