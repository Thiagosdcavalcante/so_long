/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elements.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsantana <tsantana@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 15:56:15 by tsantana          #+#    #+#             */
/*   Updated: 2024/02/22 20:05:30 by tsantana         ###   ########.fr       */
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
# define BUFFERSIZE 88500
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
	int	line;
	int	column;
	char	content;
	struct s_list	*next;
}	t_list;

typedef struct	s_items
{
	t_image	player;
	t_image	exit;
	t_image	fish;
	t_image	wall;
}	t_items;

typedef struct	s_player
{
	t_list	*p;
	t_list	*w;
	t_list	*s;
	t_list	*a;
	t_list	*d;
}	t_player;

typedef struct	s_game
{
	mlx_t	*connect_mlx;
	t_list	*map;
	t_sizes sizes;
	t_items	items;
	t_player	plr;
	t_background	background;
}	t_game;

int	dotber_checker(char *arch_name);
int	args_verify(int c, char *v);
int	items_checker(char map_char, int *fish, int *player, int *exit);

void	ft_lstclear(t_list **lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstnew(char content, int line, int column);

void	objects_start(mlx_t window_open, t_items *map_obj);
void	bg_init(mlx_t* window_open, t_background *bg_creation);
void	obj_calculator(char value, t_sizes *count);

void	free_game(t_game *to_free);
void	print_wall(mlx_t *win, t_list *node, int tile, t_items item);

#endif
