# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gbertin <gbertin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/18 15:27:37 by gbertin           #+#    #+#              #
#    Updated: 2022/03/18 16:42:02 by gbertin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= solong.a
CC=gcc
FLAGS= -Wall -Wextra -Werror
MLXFLAGS= -lmlx -lXext -lX11
RM= rm -f
LIB_PATH = libft/
SRCS= 

OBJ=$(SRCS:.c=.o)
all: $(NAME)

$(NAME): $(OBJ)

%.o: %.c
		