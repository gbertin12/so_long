/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbertin <gbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:05:28 by gbertin           #+#    #+#             */
/*   Updated: 2022/04/09 12:51:40 by gbertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx-linux/mlx.h" 
//gcc so_long.c -L minilibx-linux -lmlx -lXext -lX11  

//ne pas utiliser window_put_pixel
int main()
{
    void *mlx;
    void *win_mlx;

    mlx = mlx_init();
    win_mlx = mlx_new_window(mlx, 1000, 600, "Hellllo");
    mlx_loop(mlx);
}