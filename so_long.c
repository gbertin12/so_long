/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbertin <gbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:05:28 by gbertin           #+#    #+#             */
/*   Updated: 2022/05/23 16:01:54 by gbertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"
//gcc so_long.c sources/*.c libs/gnl/*.c libs/libft/*.c -L libs/minilibx-linux -lmlx -lXext -lX11

//ne pas utiliser window_put_pixel

void	ft_init_struct_map(t_map *map)
{
	map->exit = 0;
	map->items = 0;
	map->start = 0;
	map->size = 0;
}

int	main(int argc, char **argv)
{
    t_vars  vars;
    t_map   map;

    ft_init_struct_map(&map);
    if (argc == 2 && ft_check_map(argv[1], &map))
    {
        printf("good\n");
        // vars.mlx = mlx_init();
        // vars.win = mlx_new_window(vars.mlx, 1000, 600, "Hellllo");
        // mlx_loop(vars.mlx);
    }
    //ft_free();
    return (0);
}