/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsantana <tsantana@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 21:42:05 by tsantana          #+#    #+#             */
/*   Updated: 2024/03/20 21:46:43 by tsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BONUS_H
# define BONUS_H

# include "MLX42/MLX42.h"
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# define BUFFERSIZE 6915
# define WIDTH 1920
# define HEIGHT 1050
# define PTOP01 "assets/pigtop01.png"
# define PTOP02 "assets/pigtop02.png"
# define PTOP03 "assets/pigtop03.png"
# define PTOP04 "assets/pigtop04.png"
# define PTOP05 "assets/pigtop05.png"
# define PB01 "assets/pigb01.png"
# define PB02 "assets/pigb02.png"
# define PB03 "assets/pigb03.png"
# define PB04 "assets/pigb04.png"
# define PB05 "assets/pigb05.png"
# define PLEFT01 "assets/pigleft01.png"
# define PLEFT02 "assets/pigleft02.png"
# define PLEFT03 "assets/pigleft03.png"
# define PLEFT04 "assets/pigleft04.png"
# define PLEFT05 "assets/pigleft05.png"
# define PRIGHT01 "assets/pigright01.png"
# define PRIGHT02 "assets/pigright02.png"
# define PRIGHT03 "assets/pigright03.png"
# define PRIGHT04 "assets/pigright04.png"
# define PRIGHT05 "assets/pigright05.png"

typedef struct s_sizes
{
	int	collect;
	int	moves;
	int	qnt_f;
	int	qnt_v;
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

typedef struct s_sprites
{
	t_image				img;
	struct s_sprites	*next;
	struct s_sprites	*previous;
}	t_sprites;

typedef struct s_imgplr
{
	t_sprites	*top;
	t_sprites	*below;
	t_sprites	*right;
	t_sprites	*left;
}	t_imgplr;

typedef struct s_villain
{
	t_image	top;
	t_image	right;
	t_image	left;
	t_image	below;
}	t_villain;

typedef struct s_items
{
	t_image		background;
	t_image		baseboard;
	t_villain	villain;
	t_imgplr	player;
	t_image		exit;
	t_image		collectible;
	t_image		wall;
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
int		ft_game(t_game *game, char *file);
int		read_map(int fd, char *buf);
int		flood_fill(t_list *plr, t_list *map);
int		start_items(t_game *gm);
int		validations_lines(t_game *gm, char *bfr);
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
void	print_objcts(mlx_t *mlx, t_list *gm, t_items *item, t_sizes szs);
void	def_size(char *buf, t_sizes *sz);
void	init_gm(t_game *game);
void	render_game(void *game);
void	ft_putnumb(int n);
void	init_villain(mlx_t *window, t_sizes szs, t_items *obj);
void	init_sprite(mlx_t *wind, t_sizes szs, t_items *obj);

#endif
