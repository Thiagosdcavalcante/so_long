/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elements.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsantana <tsantana@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 15:56:15 by tsantana          #+#    #+#             */
/*   Updated: 2024/03/16 21:45:09 by tsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ELEMENTS_H
# define ELEMENTS_H

# include "MLX42/MLX42.h"
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# define BUFFERSIZE 6915
# define WIDTH 1920
# define HEIGHT 1050

typedef struct s_sizes
{
	int	collect;
	int	moves;
	int	qnt_f;
	int	qnt_p;
	int	qnt_e;
	int	x;
	int	y;
	int	tile;
}	t_sizes;

typedef struct s_image
{
	mlx_texture_t	*texture;
	mlx_image_t		*img;
}	t_image;

typedef struct s_list
{
	int				line;
	int				column;
	char			content;
	struct s_list	*next;
}	t_list;

typedef struct s_cllct
{
	int				active;
	int				line;
	int				column;
	char			content;
	struct s_cllct	*next;
}	t_cllct;

typedef struct s_items
{
	t_image	background;
	t_image	player;
	t_image	exit;
	t_image	collectible;
	t_image	wall;
}	t_items;

typedef struct s_player
{
	t_list	*p;
	t_list	*w;
	t_list	*s;
	t_list	*a;
	t_list	*d;
}	t_player;

typedef struct s_game
{
	mlx_t		*connect_mlx;
	t_list		*check;
	t_list		*map;
	t_cllct		*cllct;
	t_sizes		sizes;
	t_items		items;
	t_player	plr;
}	t_game;

t_list	*ft_lstnew(char content, int line, int column);
t_cllct	*ft_cllctnew(char content, int line, int column);
int		args_verify(int c, char *v);
int		items_checker(char map_char, int *fish, int *player, int *exit);
int		wall_check(char ch, int c, int l, t_sizes *size);
int		check_char(char c);
void	ft_lstclear(t_list **lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_cllctadd_back(t_cllct **lst, t_cllct *new);
void	ft_cllctclear(t_cllct **lst);
void	objects_start(mlx_t *window_open, t_items *map_obj, t_sizes szs);
void	obj_calculator(char value, t_sizes **count);
void	free_game(t_game *to_free);
void	print_wall_exit(mlx_t *win, int tile, t_items *item, t_list *node);
void	make_player(t_list *mp_to_p, t_player *plr);
void	plr_remake(t_game *gm, char move);
void	print_exit(mlx_t *win, t_list *node, int tile, t_items *item);

#endif
