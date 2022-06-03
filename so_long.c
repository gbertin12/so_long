/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbertin <gbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:05:28 by gbertin           #+#    #+#             */
/*   Updated: 2022/06/03 13:52:25 by gbertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

int	main(int argc, char **argv)
{
	t_map	map;

	ft_memset(&map, 0, sizeof(t_map));
	map.vars.mlx = mlx_init();
	if (!map.vars.mlx)
		ft_msg_err("Error\nInit mlx");
	if (!ft_init_struct_map(&map))
		return (0);
	if (argc == 2 && ft_check_map(argv[1], &map))
	{
		map.vars.win = mlx_new_window(map.vars.mlx, map.width, \
		map.height, "./so_long");
		if (!map.vars.win)
			ft_msg_err("Error\nInit window");
		if (!ft_print_map(&map))
			printf("\nError print");
		mlx_key_hook(map.vars.win, ft_hook_manager, &map);
		mlx_hook(map.vars.win, 17, 0, &ft_close, &map);
		mlx_loop(map.vars.mlx);
	}
	else
		ft_close(&map);
}
