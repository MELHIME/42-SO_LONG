# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mel-hime <mel-hime@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/21 08:06:59 by mel-hime          #+#    #+#              #
#    Updated: 2024/05/26 18:19:15 by mel-hime         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRC= ../get_next_line/get_next_line.c ../get_next_line/get_next_line_utils.c \
ft_split_bonus.c main_bonus.c sl_utils_bonus.c map_checker0_bonus.c map_checker1_bonus.c check_t_ex_tention_bonus.c \
draw_map_bonus.c moves_bonus.c enm_bite_bonus.c sl_utils1_bonus.c coin_flip_bonus.c

OBJ= $(SRC:.c=.o)
NAME= so_long_bonus
CC= cc -Werror -Wall -Wextra
MLX= ../MLX42/build/libmlx42.a -I"../../MLX42/include/MLX42/MLX42.h" -lglfw -L"/Users/mel-hime/.brew/opt/glfw/lib/"

.SILENT:

all :$(NAME)

$(NAME): so_long_bonus.h ../get_next_line/get_next_line.h $(OBJ)
	$(CC) $(OBJ) $(MLX) -o $(NAME)
	echo "\033[1;32mthe Mandatory target has been mad with success\033[0m"

clean:
	rm -rf $(OBJ)
	echo "\033[1;33mthe Mandatory part object files had been deleted\033[0m"

fclean: clean
	rm -rf $(NAME)
	echo "\033[1;31mthe Mandatory part target has been deleted\033[0m"

re: fclean all