/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_msg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbertin <gbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 09:43:54 by gbertin           #+#    #+#             */
/*   Updated: 2022/06/02 11:09:59 by gbertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_msg_err(char *msg)
{
	ft_putstr_fd(msg, 1);
	return (0);
}

void	ft_win(t_map *map)
{
	ft_close(map);
}
