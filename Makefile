# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gbertin <gbertin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/18 15:27:37 by gbertin           #+#    #+#              #
#    Updated: 2022/05/25 11:26:23 by gbertin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = solong.a
CC = gcc
FLAGS =	-Wall -Wextra -Werror
MLXFLAGS = -lmlx -lXext -lX11
RM = rm -f
LIBFT_PATH = libs/libft/
GNL_PATH = libs/gnl/
MLX_PATH = libs/minilibx-linux/
SRCS_PATH = sources/
SRCS =	so_long.c \
		sources/ft_check_map.c \
		sources/ft_msg.c 

OBJ=$(SRCS:.c=.o)

all: $(NAME)

$(NAME): 	$(OBJ)
			$(MAKE) -C $(LIBFT_PATH)
			cp $(LIBFT_PATH) libft.a $(NAME)

%.o: %.c
			$(CC) $(FLAGS) -L $(MLX_PATH) $(MLXFLAGS)

clean: 
			$(RM) $(OBJ)
			$(MAKE) clean -C $(LIBFT_PATH)
			$(MAKE) clean -C $(MLX_PATH)

fclean: 
			$(RM) $(NAME)
			$(MAKE) fclean -C $(LIBFT_PATH)
			$(MAKE) fclean -C $(MLX_PATH)

re: fclean all

.PHONY: clean fclean all re