/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbertin <gbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:05:28 by gbertin           #+#    #+#             */
/*   Updated: 2022/05/25 18:00:43 by gbertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"
//gcc so_long.c sources/*.c libs/gnl/*.c libs/libft/*.c -L libs/minilibx-linux -lmlx -lXext -lX11

//ne pas utiliser window_put_pixel


int	main(int argc, char **argv)
{
    t_vars  vars;
    t_map   map;

    vars.mlx = mlx_init();
	if (!vars.mlx)
		return ( ft_msg_err("Error\nInit mlx"));
	if (!ft_init_struct_map(&map, &vars))
		return (ft_msg_err("init struct error"));
    if (argc == 2 && ft_check_map(argv[1], &map))
    {
		printf("height : %d\nwidth %d\n", map.height, map.width);
		vars.win = mlx_new_window(vars.mlx, map.width, map.height, "so_long");
		mlx_loop(vars.mlx);
    }
	else {
		printf("\nerror");
	}
    //ft_free(vars, map);
}
