/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook_manager.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbertin <gbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 11:34:10 by gbertin           #+#    #+#             */
/*   Updated: 2022/06/03 11:15:41 by gbertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_move_left(t_map *map)
{
	char	*move;

	if (map->map[map->player.row][map->player.col - 1] != '1')
	{
		if (map->map[map->player.row][map->player.col - 1] == 'E'
			&& map->items == 0)
			ft_win(map);
		else if (map->map[map->player.row][map->player.col - 1] != 'E')
		{
			if (map->map[map->player.row][map->player.col - 1] == 'C')
				map->items--;
			map->map[map->player.row][map->player.col - 1] = 'P';
			map->map[map->player.row][map->player.col] = '0';
			map->nb_move++;
			move = ft_itoa(map->nb_move);
			ft_putstr_fd(move, 1);
			ft_putstr_fd("\n", 1);
			free(move);
		}
	}
	ft_memset(&(map->player), 0, sizeof(t_plyr));
}

void	ft_move_right(t_map *map)
{
	char	*move;

	if (map->map[map->player.row][map->player.col + 1] != '1')
	{
		if (map->map[map->player.row][map->player.col + 1] == 'E'
			&& map->items == 0)
			ft_win(map);
		else if (map->map[map->player.row][map->player.col + 1] != 'E')
		{
			if (map->map[map->player.row][map->player.col + 1] == 'C')
				map->items--;
			map->map[map->player.row][map->player.col + 1] = 'P';
			map->map[map->player.row][map->player.col] = '0';
			map->nb_move++;
			move = ft_itoa(map->nb_move);
			ft_putstr_fd(move, 1);
			ft_putstr_fd("\n", 1);
			free(move);
		}
	}
	ft_memset(&(map->player), 0, sizeof(t_plyr));
}

void	ft_move_up(t_map *map)
{
	char	*move;

	if (map->map[map->player.row - 1][map->player.col] != '1')
	{
		if (map->map[map->player.row - 1][map->player.col] == 'E'
			&& map->items == 0)
			ft_win(map);
		else if (map->map[map->player.row - 1][map->player.col] != 'E')
		{
			if (map->map[map->player.row - 1][map->player.col] == 'C')
				map->items--;
			map->map[map->player.row - 1][map->player.col] = 'P';
			map->map[map->player.row][map->player.col] = '0';
			map->nb_move++;
			move = ft_itoa(map->nb_move);
			ft_putstr_fd(move, 1);
			ft_putstr_fd("\n", 1);
			free(move);
		}
	}
	ft_memset(&(map->player), 0, sizeof(t_plyr));
}

void	ft_move_down(t_map *map)
{
	char	*move;

	if (map->map[map->player.row + 1][map->player.col] != '1')
	{
		if (map->map[map->player.row + 1][map->player.col] == 'E'
			&& map->items == 0)
			ft_win(map);
		else if (map->map[map->player.row + 1][map->player.col] != 'E')
		{
			if (map->map[map->player.row + 1][map->player.col] == 'C')
				map->items--;
			map->map[map->player.row + 1][map->player.col] = 'P';
			map->map[map->player.row][map->player.col] = '0';
			map->nb_move++;
			move = ft_itoa(map->nb_move);
			ft_putstr_fd(move, 1);
			ft_putstr_fd("\n", 1);
			free(move);
		}
	}
	ft_memset(&(map->player), 0, sizeof(t_plyr));
}

int	ft_hook_manager(int keycode, t_map *map)
{
	if (keycode == L_ARW || keycode == A_KEY)
		ft_move_left(map);
	else if (keycode == R_ARW || keycode == D_KEY)
		ft_move_right(map);
	else if (keycode == UP_ARW || keycode == W_KEY)
		ft_move_up(map);
	else if (keycode == DOWN_ARW || keycode == S_KEY)
		ft_move_down(map);
	else if (keycode == ESC)
		ft_close(map);
	if (!ft_print_map(map))
		return (0);
	return (0);
}
