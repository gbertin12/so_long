/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbertin <gbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 16:42:03 by gbertin           #+#    #+#             */
/*   Updated: 2022/05/31 16:40:02 by gbertin          ###   ########.fr       */
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
	char	*line;
	int		i;

	i = 0;
	fd = open(path_map, O_RDONLY);
	if (fd < 0)
		return (ft_msg_err("Error\nOpen map 2"));
	line = get_next_line(fd);
	map->map = malloc(sizeof(char *) * (map->nb_row + 1));
	if (!map->map)
		return (ft_msg_err("Error\nMalloc error"));
	while (line)
	{
		if (!ft_fill_struct_map(line, map))
			return (0);
		map->map[i++] = ft_malloc_line(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	if (!ft_calculate_height_width(map))
		return (0);
	map->map[map->nb_row] = NULL;
	return (1);
}
