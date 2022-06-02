/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbertin <gbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 15:23:11 by gbertin           #+#    #+#             */
/*   Updated: 2022/06/02 11:11:19 by gbertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "../libs/libft/libft.h"
#include "../libs/minilibx-linux/mlx.h"
#include "../libs/gnl/get_next_line.h"

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

#  define WIDTH_TILE			64
#  define HEIGHT_TILE			64

#  define L_ARW					65361
#  define R_ARW					65363
#  define UP_ARW				65362
#  define DOWN_ARW				65364
#  define A_KEY					97
#  define W_KEY					119
#  define S_KEY					115
#  define D_KEY					100
#  define ESC					65307

typedef	struct	s_vars {
	void *mlx;
	void *win;
}				t_vars;

typedef struct	s_img {
	void	*door;
	void	*floor;
	void	*collect;
	void	*player;
	void	*corner;
}				t_img;

typedef struct	s_player {
	int	row;
	int col;
}				t_player;

typedef struct  s_map {
	int			nb_move;
    int			nb_column;
	int			nb_row;
	int			width;
	int			height;
	int			exit;
	int			items;
	int			start;
	char 		**map;
	t_vars		vars;
	t_player 	player;
	t_img		img;
}				t_map;

//check map
int	ft_fill_struct_map(char *line, t_map *map);
int ft_check_items(t_map *map);
int	ft_is_close(t_map *map, int end);
int	ft_check_namefile(char *name);
int ft_check_map(char *path_map, t_map *map);

//check map 2
int	ft_calculate_width(t_map *map);
int	ft_calculate_height(t_map *map);
int ft_calculate_height_width(t_map *map);
int	ft_fill_map(char *path_map, t_map *map);

//init struct
int		ft_check_addr_img(t_map *map);
void	ft_init_player(t_map *map);
int		ft_init_struct_img(t_map *m);
int		ft_init_struct_map(t_map *map);

//print map
int	ft_print_tile(char tile, t_map *map, int x, int y);
int ft_print_map(t_map *map);

//hook manager
int		ft_hook_manager(int keycode, t_map *map);
void	ft_move_left(t_map *map);
void	ft_move_down(t_map *map);
void	ft_move_up(t_map *map);
void	ft_move_right(t_map *map);

// free
int		ft_close(t_map *map);
char	ft_free_img_msg(char *err, t_map *map);

//msg
int		ft_msg_err(char *msg);
void	ft_win(t_map *map);
#endif