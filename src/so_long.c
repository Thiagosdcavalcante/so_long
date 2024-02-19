/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsantana <tsantana@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 16:43:41 by tsantana          #+#    #+#             */
/*   Updated: 2024/02/19 18:42:59 by tsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

static int	map_infor(char *buffer, int index, t_sizes *sizes, t_elmnts *data)
{
	int counter;

	while (buffer[index] != '\0')
	{
		index++;
		counter = 0;
		while (buffer[index] != '\n' && buffer[index] != '\0')
		{
			if (items_checker(buffer[index], &data->qnt_fish,
						&data->qnt_player, &data->qnt_exit) == 0)
				ft_lstadd_back(&data->data.map->line, ft_lstnew(buffer[index], sizes->x));
			else	
				return (1);
			index++;
			counter++;
		}
		if (counter - 1 != sizes->x)
			sizes->y++;
		else
			return (write(2, "Error!\nlines not equal!", 23), 1);
		ft_columnsadd_back(&data->data.map, ft_newcolumns(buffer[index], 0, sizes->y));
	}
	return (0);
}

static int	first_line(char *buffer, t_sizes *sizes, t_data *map)
{
	int	index;

	index = 1;
	sizes->x = 1;
	if (buffer[0] != '1')
		return (write (2, "Error!\nWrong map config.!", 25), 1);
	while (buffer[index] && buffer[index] == '1' && buffer[index] != '\n')
	{
		if (buffer[index] != '1' && buffer[index] != '\n')
			return (write (2, "Error!\nInvalid Map Configuration!", 34), 1);
		else
			ft_lstadd_back(&map->line, ft_lstnew(buffer[index], sizes->x));
		if (buffer[index] != '\n')
			sizes->x++;
		index++;
	}
	return (index);
}

int	file_to_list(char *buffer, t_sizes *sizes, t_elmnts *ele)
{
	int	i;

	i = 0;
//	printf("%p\n", sizes->x);
//	printf("%p\n", sizes->y);
//	printf("%p\n", sizes->tile);
	i = first_line(buffer, sizes, ele->data.map);
	if (i == 1)
		return (1);
	tile_def(sizes);
	if (map_infor(buffer, i, sizes, ele) == 1)
		return (1);
	return (0);
}

int	parse_map(char *file, t_game *data)
{
	static char	buf[BUFFERSIZE];
	int	fd;
	int32_t bytes_read;

	fd = 0;
	bytes_read = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (write (2, "Error!\nFile didnt open!", 23), 1);
	bytes_read = read(fd, buf, BUFFERSIZE);
	if (bytes_read <= 0)
		return (write (2, "Error!\nEmpty file!", 18), 1);
	if (mllc_strct(data) == 1)
		return (1);
	if (file_to_list(buf, &data->elemnts.sizes, &data->elemnts) == 1)
		return (1);
	close(fd);
	return (0);
}

int	ft_game(t_game *game, char *file)
{
	if (parse_map(file, game) == 1)
		return (1);
	bg_init(game->connect_mlx, &game->elemnts.background);
	objects_start(*game->connect_mlx, &game->elemnts.items);
	put_wall(*game->connect_mlx, game->elemnts.items.wall,
		&game->elemnts.sizes, game->elemnts.data.map);

	return (0);
}
