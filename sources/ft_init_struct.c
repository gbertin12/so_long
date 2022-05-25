/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbertin <gbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 16:01:57 by gbertin           #+#    #+#             */
/*   Updated: 2022/05/25 17:49:17 by gbertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int		ft_check_addr_img(t_map *map)
{
	if (!map->img.door)
		return (ft_msg_err("Error\nBad Sprite exit"));
	if (!map->img.floor)
		return (ft_msg_err("Error\nBad Sprite floor"));
	if (!map->img.collect)
		return (ft_msg_err("Error\nBad Sprite collectible"));
	if (!map->img.player)
		return (ft_msg_err("Error\nBad Sprite player"));
	if (!map->img.column)
		return (ft_msg_err("Error\nBad Sprite column"));
	if (!map->img.row)
		return (ft_msg_err("Error\nBad Sprite row"));
	if (!map->img.corner)
		return (ft_msg_err("Error\nBad Sprite corner"));
	return (1);
}

int    ft_init_struct_img(t_map *m, t_vars *v)
{
    int	w;
	int	h;
	
	m->img.door = mlx_xpm_file_to_image(v->mlx, "spt/door.xpm", &w, &h);
	m->img.floor = mlx_xpm_file_to_image(v->mlx, "spt/floor.xpm", &w, &h);
	m->img.collect = mlx_xpm_file_to_image(v->mlx, "spt/collect.xpm", &w, &h);
	m->img.player = mlx_xpm_file_to_image(v->mlx, "spt/player.xpm", &w, &h);
	m->img.column = mlx_xpm_file_to_image(v->mlx, "spt/column.xpm", &w, &h);
	m->img.row = mlx_xpm_file_to_image(v->mlx, "spt/row.xpm", &w, &h);
	m->img.corner = mlx_xpm_file_to_image(v->mlx, "spt/corner.xpm", &w, &h);
	if (!ft_check_addr_img(m))
		return (0);
	return (1);
}

int	ft_init_struct_map(t_map *map, t_vars *vars)
{
	map->exit = 0;
	map->items = 0;
	map->start = 0;
	map->nb_column = 0;
    if(!ft_init_struct_img(map, vars))
        return(0);
    return(1);
}
