/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbertin <gbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 15:34:08 by gbertin           #+#    #+#             */
/*   Updated: 2022/06/02 10:38:16 by gbertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	ft_free_img_msg(char *err, t_map *map)
{
	if (map->img.door != NULL)
		mlx_destroy_image(map->vars.mlx, map->img.door);
	if (map->img.floor != NULL)
		mlx_destroy_image(map->vars.mlx, map->img.floor);
	if (map->img.collect != NULL)
		mlx_destroy_image(map->vars.mlx, map->img.collect);
	if (map->img.player != NULL)
		mlx_destroy_image(map->vars.mlx, map->img.player);
	if (map->img.corner != NULL)
		mlx_destroy_image(map->vars.mlx, map->img.corner);
	mlx_destroy_display(map->vars.mlx);
	return (ft_msg_err(err));
}

int	ft_close(t_map *map)
{
	int	i;

	i = 0;
	ft_free_img_msg("", map);
	if (map->vars.win)
		mlx_destroy_window(map->vars.mlx, map->vars.win);
	while (map->map[i])
	{
		free(map->map[i]);
		i++;
	}
	free(map->map);
	exit (0);
}
