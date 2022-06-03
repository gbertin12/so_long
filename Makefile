# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gbertin <gbertin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/18 15:27:37 by gbertin           #+#    #+#              #
#    Updated: 2022/06/03 14:00:37 by gbertin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = solong
CC = gcc
FLAGS =	-Wall -Wextra -Werror
MLXFLAGS = -lmlx -lXext -lX11
RM = rm -f
LIBFT_PATH = libs/libft/
MLX_PATH = libs/minilibx-linux/
SRCS_PATH = sources/
SRCS =	so_long.c \
		sources/ft_check_map.c \
		sources/ft_check_map2.c\
		sources/ft_check_map3.c\
		sources/ft_free.c \
		sources/ft_hook_manager.c \
		sources/ft_init_struct.c \
		sources/ft_print_map.c \
		sources/ft_msg.c \
		libs/gnl/get_next_line_utils.c \
		libs/gnl/get_next_line.c 
HEAD = includes/so_long.h

OBJ=$(SRCS:.c=.o)

all: $(NAME)

%.o: %.c
			$(CC) $(FLAGS) -c $< -o ${<:.c=.o}

$(NAME):$(OBJ) $(HEAD)
			$(MAKE) -C $(MLX_PATH)
			$(MAKE) -C $(LIBFT_PATH)
			$(CC) $(FLAGS) -o $(NAME) $(OBJ) -L $(MLX_PATH) $(MLXFLAGS) -lm libs/libft/libft.a


clean: 
			$(RM) $(OBJ)
			$(MAKE) clean -C $(LIBFT_PATH)
			$(MAKE) clean -C $(MLX_PATH)
			$(RM) $(OBJ)

fclean: clean
			$(MAKE) clean -C $(LIBFT_PATH)
			$(MAKE) clean -C $(MLX_PATH)
			$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean all re