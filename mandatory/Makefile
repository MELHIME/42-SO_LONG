# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mel-hime <mel-hime@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/21 08:06:59 by mel-hime          #+#    #+#              #
#    Updated: 2024/05/21 09:37:39 by mel-hime         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRC= ../get_next_line/get_next_line.c ../get_next_line/get_next_line_utils.c \
ft_split.c main.c sl_utils.c map_checker0.c map_checker1.c check_t_ex_tention.c \
draw_map.c moves.c

OBJ= $(SRC:.c=.o)
NAME= so_long
CC= cc -Werror -Wall -Wextra 
MLX= ../MLX42/build/libmlx42.a -I"../../MLX42/include/MLX42/MLX42.h" -lglfw -L"/Users/mel-hime/.brew/opt/glfw/lib/"
RM= rm -rf

.SILENT:

all :$(NAME)

$(NAME): so_long.h ../get_next_line/get_next_line.h $(OBJ)
	@$(CC) $(OBJ) $(MLX) -o $(NAME)
	@echo "\033[1;32mthe Mandatory target has been mad with success\033[0m"

clean:
	@rm -rf $(OBJ)
	@echo "\033[1;33mthe Mandatory part object files had been deleted\033[0m"


fclean: clean
	@rm -rf $(NAME)
	@echo "\033[1;31mthe Mandatory part target has been deleted\033[0m"

re: fclean all