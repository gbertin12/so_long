/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbertin <gbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:05:28 by gbertin           #+#    #+#             */
/*   Updated: 2022/05/20 09:35:49 by gbertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"
//gcc so_long.c -L minilibx-linux -lmlx -lXext -lX11  

//ne pas utiliser window_put_pixel
int main(int argc, char **argv)
{
    t_vars  vars;
    t_map   map;

    if (argc == 2 && ft_check_map(argv[1], &map))
    {
        vars.mlx = mlx_init();
        vars.win = mlx_new_window(vars.mlx, 1000, 600, "Hellllo");
        mlx_loop(vars.mlx);
    }
    
}