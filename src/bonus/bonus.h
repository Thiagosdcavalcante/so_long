/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsantana <tsantana@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 21:42:05 by tsantana          #+#    #+#             */
/*   Updated: 2024/03/25 21:58:27 by tsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BONUS_H
# define BONUS_H

# include "MLX42/MLX42.h"
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# define BUFFERSIZE 6915

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

typedef struct s_villain
{
	t_image	below;
}	t_villain;

typedef struct s_items
{
	mlx_image_t	*counter;
	t_image		background;
	t_image		baseboard;
	t_villain	villain;
	t_image		player;
	t_image		exit;
	t_image		collectible;
	t_image		wall;
}	t_items;

typedef struct s_player
{
	char	key;
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
int		plr_exit(t_game *gm);
int		file_list(char *bffr, t_list **map);
int		plr_exit(t_game *gm);
void	file_to_cllct(char *bffr, t_cllct **collect);
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
void	plr_cllct(t_player *p, t_sizes *szs, t_cllct *cllct);
void	def_p_around(int i, int j, t_list *mp_p, t_player *plr);
void	reload_render(t_game *gm);
void	print_moves(mlx_t *mlx, t_sizes *infor, mlx_image_t **counter);
void	plr_cllct(t_player *p, t_sizes *szs, t_cllct *cllct);
void	cllct_work(t_cllct **cllct, int ln, int cl);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_itoa(int n);
void	render_player(void *param);

#endif
