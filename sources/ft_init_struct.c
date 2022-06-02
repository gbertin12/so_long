/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbertin <gbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 16:01:57 by gbertin           #+#    #+#             */
/*   Updated: 2022/06/02 10:18:51 by gbertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_check_addr_img(t_map *map)
{
	if (!map->img.door)
		return (ft_free_img_msg("Error\nBad Sprite exit", map));
	if (!map->img.floor)
		return (ft_free_img_msg("Error\nBad Sprite floor", map));
	if (!map->img.collect)
		return (ft_free_img_msg("Error\nBad Sprite collectible", map));
	if (!map->img.player)
		return (ft_free_img_msg("Error\nBad Sprite player", map));
	if (!map->img.corner)
		return (ft_free_img_msg("Error\nBad Sprite corner", map));
	return (1);
}

void	ft_init_img(t_map *map)
{
	map->img.door = NULL;
	map->img.floor = NULL;
	map->img.collect = NULL;
	map->img.player = NULL;
	map->img.corner = NULL;
}

int	ft_init_struct_img(t_map *m)
{
	int	w;
	int	h;

	m->img.door = mlx_xpm_file_to_image(m->vars.mlx, \
	"spt/door.xpm", &w, &h);
	m->img.floor = mlx_xpm_file_to_image(m->vars.mlx, \
	"spt/floor.xpm", &w, &h);
	m->img.collect = mlx_xpm_file_to_image(m->vars.mlx, \
	"spt/collect.xpm", &w, &h);
	m->img.player = mlx_xpm_file_to_image(m->vars.mlx, \
	"spt/player.xpm", &w, &h);
	m->img.corner = mlx_xpm_file_to_image(m->vars.mlx, \
	"spt/corner.xpm", &w, &h);
	if (!ft_check_addr_img(m))
		return (0);
	return (1);
}

void	ft_init_player(t_map *map)
{
	map->player.row = 0;
	map->player.col = 0;
}

int	ft_init_struct_map(t_map *map)
{
	map->nb_move = 0;
	map->exit = 0;
	map->items = 0;
	map->start = 0;
	map->nb_column = 0;
	map->map = NULL;
	ft_init_player(map);
	ft_init_img(map);
	if (!ft_init_struct_img(map))
		return (0);
	return (1);
}
