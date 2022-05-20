/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbertin <gbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 15:23:11 by gbertin           #+#    #+#             */
/*   Updated: 2022/05/20 10:56:31 by gbertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "../libs/libft/libft.h"
#include "../libs/minilibx-linux/mlx.h"
#include "../libs/gnl/get_next_line.h"

typedef	struct	s_vars {
	void *mlx;
	void *win;
}				t_vars;

typedef struct  s_map {
    int size;
	int	exit;
	int items;
	int start;
}				t_map;

int ft_check_map(char *path_map, t_map *map);
int	ft_msg_err(char *msg);
#endif