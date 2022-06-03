/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbertin <gbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 09:20:34 by gbertin           #+#    #+#             */
/*   Updated: 2022/06/03 14:26:33 by gbertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_fill_struct_map(char *line, t_map *map)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != '\n')
	{
		if (!ft_count_type_tile(line, map, i))
			return (ft_msg_err("Error\nUnknown item"));
		i++;
	}
	if (map->nb_column == 0)
		map->nb_column = i;
	else if (map->nb_column != i)
		return (ft_msg_err("Error\nMap is not rectangle"));
	return (1);
}

int	ft_check_items(t_map *map)
{
	if (map->items == 0)
		return (ft_msg_err("Error\nThere is no collectibles"));
	if (map->exit == 0)
		return (ft_msg_err("Error\nThere is no exit"));
	if (map->start == 0)
		return (ft_msg_err("Error\nThere is no player"));
	return (1);
}

int	ft_is_close(t_map *map, int end)
{
	int	i;
	int	y;

	i = 0;
	y = 0;
	while (map->map[i][y] && map->map[end][y]
		&& map->map[end][y] != '\n' && map->map[i][y] != '\n')
	{
		printf("%s\n %d\n", map->map[i], end);
		if (map->map[i][y] != '1' || map->map[end][y] != '1')
			return (ft_msg_err("Error\nMap not close1"));
		y++;
	}
	i = 1;
	while (map->map[i] && i < end)
	{
		if (map->map[i][0] != '1' || map->map[i][map->nb_column - 1] != '1')
			return (ft_msg_err("Error\nMap not close2"));
		i++;
	}
	return (1);
}

int	ft_check_namefile(char *name)
{
	int		i;
	char	*ber;

	i = 0;
	ber = ".ber";
	while (name[i])
		i++;
	while (name[i] != '.' && i > 0)
		i--;
	if (ft_strncmp(&name[i], ber, 4))
		return (0);
	if (name[i + 4] != '\0')
		return (0);
	return (1);
}

int	ft_check_map(char *path_map, t_map *map)
{
	int		fd;
	char	*line;

	if (!ft_check_namefile(path_map))
		return (ft_msg_err("Error\nIt's not a .ber file"));
	fd = open(path_map, O_RDONLY);
	if (fd < 0)
		return (ft_msg_err("Error\nOpen map"));
	line = get_next_line(fd);
	if (!line)
		return (ft_msg_err("Error\nEmpty map"));
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		map->nb_row++;
	}
	close(fd);
	if (!ft_fill_map(path_map, map))
		return (0);
	if (!ft_check_items(map) || !ft_is_close(map, map->nb_row - 1))
		return (0);
	return (1);
}
