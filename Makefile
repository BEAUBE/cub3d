# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: slepetit <slepetit@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/10 16:27:12 by slepetit          #+#    #+#              #
#    Updated: 2023/10/14 22:01:25 by slepetit         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

SRC = main.c \
	parsing/ft_parsing.c \
	parsing/ft_utils.c \
	parsing/ft_free.c \
	parsing/ft_identifiers.c \
	parsing/ft_identifiers_utils.c \
	parsing/ft_map.c \
	parsing/ft_map_utils.c \
	parsing/ft_get_map.c \
	parsing/ft_error.c \
	parsing/ft_fill_game.c \
	game/game.c \
	game/rays.c \
	game/rays_utils.c \
	game/keys.c \
	game/ft_keys_rotate.c \
	game/draw.c \
	game/mlx_utils.c \
	game/textures.c

LIBDIR = lib
LIBLIB = lib/libft.a
MLXDIR = MLX42/build
MLXLIB = MLX42/build/libmlx42.a

OBJ = $(SRC:%.c=%.o)

CC = clang

CFLAGS = -Wall -Wextra -Werror -I. -g3

MLXFLAGS = -lglfw -pthread -lm -ldl -Lmlx

all: $(NAME)

$(LIBLIB):
	make -sC $(LIBDIR)

$(MLXLIB):
	cmake MLX42 -B $(MLXDIR) && make -C $(MLXDIR) -j4

$(NAME): $(OBJ) $(LIBLIB) $(MLXLIB)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBLIB) $(MLXLIB) $(MLXFLAGS)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)
	make -sC $(LIBDIR) clean
	make -sC $(MLXDIR) clean

fclean: clean
	rm -rf $(NAME)
	make -sC $(LIBDIR) fclean
	rm -rf $(MLXLIB)

re: fclean $(NAME)

.PHONY: all clean fclean re