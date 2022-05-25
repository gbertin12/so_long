/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbertin <gbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 15:23:11 by gbertin           #+#    #+#             */
/*   Updated: 2022/05/25 17:56:23 by gbertin          ###   ########.fr       */
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

#  define WIDTH_TILE 64
#  define HEIGHT_TILE 64

typedef	struct	s_vars {
	void *mlx;
	void *win;
}				t_vars;

typedef struct	s_img {
	void	*door;
	void	*floor;
	void	*collect;
	void	*player;
	void	*column;
	void	*row;
	void	*corner;
}				t_img;

typedef struct  s_map {
    int		nb_column;
	int		nb_row;
	int		width;
	int		height;
	int		exit;
	int		items;
	int		start;
	char 	**map;
	t_img	img;
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
int	ft_fill_map(char *path_map, t_map *map, int nb_row);

//init struct
int		ft_check_addr_img(t_map *map);
int		ft_init_struct_img(t_map *m, t_vars *v);
int		ft_init_struct_map(t_map *map, t_vars *vars);


int	ft_msg_err(char *msg);
#endif