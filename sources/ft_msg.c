/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_msg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbertin <gbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 09:43:54 by gbertin           #+#    #+#             */
/*   Updated: 2022/06/02 12:56:58 by gbertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_msg_err_exit(t_map *map, char *msg)
{
	ft_putstr_fd(msg, 1);
	ft_close(map);
}

void	ft_win(t_map *map)
{
	ft_putstr_fd("Congratulation ! You won !\n", 1);
	ft_close(map);
}

int		ft_msg_err(char *msg)
{
	ft_putstr_fd(msg, 1);
	return (0);
}
