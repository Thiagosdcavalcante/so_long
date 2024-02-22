/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsantana <tsantana@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 16:43:41 by tsantana          #+#    #+#             */
/*   Updated: 2024/02/22 20:05:08 by tsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// static int	map_infor(char *buffer, int index, t_sizes *sizes, t_elmnts *data)
// {
// 	int counter;
// 	int	col;
// 	int ind;
//
// 	col = sizes->y;
// 	ind = index;
// 	while (buffer[ind] != '\0')
// 	{
// 		ind++;
// 		counter = 0;
// 		while (buffer[ind] != '\n' && buffer[ind] != '\0')
// 		{
// 			if (items_checker(buffer[ind], &data->qnt_fish,
// 						&data->qnt_player, &data->qnt_exit) == 0)
// 				ft_lstadd_back(&data->data.map->line, ft_lstnew(buffer[ind], sizes->x));
// 			else	
// 				return (1);
// 			ind++;
// 			counter++;
// 		}
// 		if (buffer[ind] == '\n' && (counter - 1 != sizes->x))
// 			col++;
// 		else
// 			return (write(2, "Error!\nlines not equal!", 23), 1);
// 		ft_columnsadd_back(&data->data.map, ft_newcolumns(buffer[ind], 0, col));
// 	}
// 	sizes->y = col;
// 	return (0);
// }
//
// static int	first_line(char *buffer, t_sizes *sizes, t_data *map)
// {
// 	int	index;
//
// 	index = 1;
// 	sizes->x = 1;
// 	if (buffer[0] != '1')
// 		return (write (2, "Error!\nWrong map config.!", 25), 1);
// 	while (buffer[index] && buffer[index] == '1' && buffer[index] != '\n')
// 	{
// 		if (buffer[index] != '1' && buffer[index] != '\n')
// 			return (write (2, "Error!\nInvalid Map Configuration!", 34), 1);
// 		else
// 			ft_lstadd_back(&map->line, ft_lstnew(buffer[index], sizes->x));
// 	}
// 	if (buffer[index] == '\n')
// 		index--;
// 	sizes->x = index;
// 	return (index);
// }
//
// int	file_to_list(char *buffer, t_sizes *sizes, t_elmnts *ele)
// {
// 	int	i;
//
// 	i = 0;
// 	i = first_line(buffer, sizes, ele->data.map);
// 	if (i == 1)
// 		return (1);
// 	if (map_infor(buffer, i, sizes, ele) == 1)
// 		return (1);
// 	sizes->tile = tile_def(sizes->x, sizes->y);
// 	return (0);
// }

// int	parse_map(char *file, t_game *data)
// {
// 	static char	buf[BUFFERSIZE];
// 	size_t	fd;
// 	size_t bytes_read;
//
// 	fd = 0;
// 	bytes_read = 0;
// 	fd = open(file, O_RDONLY);
// 	if (fd < 0)
// 		return (write (2, "Error!\nFile didnt open!", 23), 1);
// 	bytes_read = read(fd, buf, BUFFERSIZE);
// 	if (bytes_read <= 0)
// 		return (write (2, "Error!\nEmpty file!", 18), 1);
// 	if (file_to_list(buf, &data->elemnts.sizes, &data->elemnts) == 1)
// 		return (1);
// 	close(fd);
// 	return (0);
// }

void	ft_game(t_game *game)
{
	init_data(game);
	//if (parse_map(file, game) == 1)
 	//	return (write(2, "Error\nParse Map!", 16), 1);
	bg_init(game->connect_mlx, &game->background);
	objects_start(*game->connect_mlx, &game->items);
	print_wall(game->connect_mlx, game->map, game->sizes.tile, game->items);
	// objects_start(*game->connect_mlx, &game->elemnts.items);
	// put_wall(*game->connect_mlx, &game->elemnts.items.wall,
	// 	&game->elemnts.sizes, game->elemnts.data.map);
}
