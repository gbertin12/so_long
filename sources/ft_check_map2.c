/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbertin <gbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 16:42:03 by gbertin           #+#    #+#             */
/*   Updated: 2022/06/03 11:22:30 by gbertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_calculate_width(t_map *map)
{
	return (map->nb_column * WIDTH_TILE);
}

int	ft_calculate_height(t_map *map)
{
	return (map->nb_row * HEIGHT_TILE);
}

int	ft_calculate_height_width(t_map *map)
{
	map->height = ft_calculate_height(map);
	map->width = ft_calculate_width(map);
	if (map->height > 1600)
		return (ft_msg_err("Error\nMap too height"));
	if (map->width > 2580)
		return (ft_msg_err("Error\nMap too large"));
	return (1);
}

char	*ft_malloc_line(char *src)
{
	unsigned int	size;
	unsigned int	i;
	char			*new;

	i = 0;
	size = ft_strlen(src);
	new = malloc(size + 1);
	if (!new)
		return (NULL);
	while (src[i] != '\0')
	{
		new[i] = src[i];
		i++;
	}
	new[i] = '\0';
	free(src);
	return (new);
}

int	ft_fill_map(char *path_map, t_map *map)
{
	int		fd;

	fd = open(path_map, O_RDONLY);
	if (fd < 0)
		ft_msg_err("Error\nOpen map 2");
	if (!ft_fill_map2(map, fd))
		return (0);
	close(fd);
	map->map[map->nb_row] = NULL;
	if (!ft_calculate_height_width(map))
		return (0);
	return (1);
}
