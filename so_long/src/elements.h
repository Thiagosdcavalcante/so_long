/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elements.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsantana <tsantana@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 15:56:15 by tsantana          #+#    #+#             */
/*   Updated: 2024/02/21 14:49:24 by tsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ELEMENTS_H
# define ELEMENTS_H

# include "MLX42/MLX42.h"
# include "size_definition.h"
# include <stdlib.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# define BUFFERSIZE 10000
# define MAP_ITEMS "10PCE"

typedef struct	s_image
{
	mlx_texture_t	*texture;
	mlx_image_t	*img;
}	t_image;

typedef	struct	s_background
{
	t_image	background;
	t_image	baseboard;
	t_image	left;
}	t_background;

typedef struct	s_list
{
	char	content;
	int	position;
	struct s_list	*next;
}	t_list;

typedef struct	s_data
{
	int	position;
	t_list	*line;
	struct s_data	*next;
}	t_data;

typedef struct	s_items
{
	t_image	player;
	t_image	exit;
	t_image	fish;
	t_image	wall;
}	t_items;

typedef struct	s_player
{
	int	line;
	t_list	*p;
	t_list	*w;
	t_list	*s;
	t_list	*a;
	t_list	*d;
}	t_player;

typedef struct	s_eledata
{
	t_data	*map;
	t_player	player;
}	t_eledata;

typedef struct s_elmnts
{
	int	qnt_fish;
	int	qnt_player;
	int	qnt_exit;
	t_sizes sizes;
	t_items	items;
	t_eledata	data;
	t_background	background;
}	t_elmnts;

int	dotber_checker(char *arch_name);
int	args_verify(int c, char *v);
int	items_checker(char map_char, int *fish, int *player, int *exit);

void	ft_columnsadd_back(t_data **lst, t_data *new);
void	ft_columnsclear(t_data **lst);
t_data	*ft_newcolumns(char start, int line, int column);

void	ft_lstclear(t_list **lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstnew(char content, int position);

void	objects_start(mlx_t window_open, t_items *map_obj);
void	bg_init(mlx_t* window_open, t_background *bg_creation);
void	obj_calculator(char value, t_elmnts *game);

void	free_game(t_elmnts *to_free);
void	free_imgs(t_background *bg);
void	ft_free_dt(t_eledata *data);

#endif
