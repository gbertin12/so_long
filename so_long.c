/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbertin <gbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:05:28 by gbertin           #+#    #+#             */
/*   Updated: 2022/05/31 10:11:32 by gbertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"
//gcc so_long.c sources/*.c libs/gnl/*.c libs/libft/*.c -L libs/minilibx-linux -lmlx -lXext -lX11

int	main(int argc, char **argv)
{
    t_map   map;
	t_vars	vars;

	map.vars = vars;
    map.vars.mlx = mlx_init();
	if (!map.vars.mlx)
		return (ft_msg_err("Error\nInit mlx"));
	if (!ft_init_struct_map(&map))
		return (ft_msg_err("Error\nInit struct error"));
    if (argc == 2 && ft_check_map(argv[1], &map))
    {
		map.vars.win = mlx_new_window(map.vars.mlx, map.width, map.height, "./so_long");
		if(!ft_print_map(&map))
			printf("\nError print");
		mlx_key_hook(map.vars.win, ft_hook_manager, &map);
		mlx_hook(map.vars.win, 17, 0, &ft_close, &map);
		mlx_loop(map.vars.mlx);
    }
    //ft_global_free(vars, map);
}
