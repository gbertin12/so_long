/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbertin <gbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 10:00:49 by gbertin           #+#    #+#             */
/*   Updated: 2022/05/30 17:50:17 by gbertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_print_tile(char tile, t_map *map, int x, int y)
{
	if (tile == '1')
		mlx_put_image_to_window(map->vars.mlx, map->vars.win, map->img.corner, x, y);
	else if (tile == '0')
		mlx_put_image_to_window(map->vars.mlx, map->vars.win, map->img.floor, x, y);
	else if (tile == 'P')
	{
		if (map->player.col == 0 && map->player.row == 0)
		{
			map->player.col = x / HEIGHT_TILE;
			map->player.row = y / WIDTH_TILE;
			mlx_put_image_to_window(map->vars.mlx, map->vars.win, map->img.floor, x, y);
			mlx_put_image_to_window(map->vars.mlx, map->vars.win, map->img.player, x, y);
		}
	}
	else if (tile == 'C')
	{
		x += HEIGHT_TILE / 2 - 6;
		y += WIDTH_TILE / 2 - 6;
		mlx_put_image_to_window(map->vars.mlx, map->vars.win, map->img.floor, x, y);
		mlx_put_image_to_window(map->vars.mlx, map->vars.win, map->img.collect, x, y);
	}
	else if (tile == 'E')
	{
		mlx_put_image_to_window(map->vars.mlx, map->vars.win, map->img.floor, x, y);
		mlx_put_image_to_window(map->vars.mlx, map->vars.win, map->img.door, x, y);
	}
	return (1);
}

int ft_print_map(t_map *map)
{
	int row;
    int	col;
	int x;
	int y;

	x = 0;
	y = 0;
	row = 0;
	while (map->map[row])
	{
		col = 0;
		x = 0;
		while (map->map[row][col])
		{
			if (!ft_print_tile(map->map[row][col], map, x, y))
				return (ft_msg_err("Error\nPrint tile"));
			col++;
			x += WIDTH_TILE;
		}
		y+= HEIGHT_TILE;
		row++;
	}
	return (1);
}