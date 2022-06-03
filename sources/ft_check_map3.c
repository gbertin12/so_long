/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbertin <gbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 10:26:49 by gbertin           #+#    #+#             */
/*   Updated: 2022/06/03 13:49:28 by gbertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_fill_map2(t_map *map, int fd)
{
	int		i;
	char	*line;

	i = 0;
	line = get_next_line(fd);
	map->map = malloc(sizeof(char *) * (map->nb_row + 1));
	if (!map->map)
		ft_msg_err("Error\nMalloc error");
	while (line)
	{
		if (!ft_fill_struct_map(line, map))
			ft_fill_struct_err(line, fd, map, i);
		map->map[i++] = ft_malloc_line(line);
		if (!map->map[i - 1])
			return (0);
		line = get_next_line(fd);
	}
	free(line);
	return (1);
}

int	ft_count_type_tile(char *line, t_map *map, int i)
{
	if (line[i] == '1' || line[i] == '0' || line[i] == 'P'
		|| line[i] == 'C' || line[i] == 'E')
	{
		if (line[i] == 'E')
			map->exit += 1;
		else if (line[i] == 'C')
			map->items += 1;
		else if (line[i] == 'P' && map->start == 0)
			map->start += 1;
		else if (line[i] == 'P' && map->start != 0)
			line[i] = '0';
		return (1);
	}
	return (0);
}
