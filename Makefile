# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: slepetit <slepetit@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/10 16:27:12 by slepetit          #+#    #+#              #
#    Updated: 2023/09/25 17:34:54 by ajoliet          ###   ########.fr        #
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
	game/mlx_utils.c

LIBDIR = lib
LIBLIB = lib/libft.a
MLXDIR = MLX42/build
MLXLIB = MLX42/build/libmlx42.a

OBJ = $(SRC:%.c=%.o)

CC = clang

CFLAGS = -Wall -Wextra -Werror -I. -g3

MLXFLAGS = -ldl -lglfw -pthread -lm

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


# NAME = cub3d
# SRC_DIR = src
# OBJ_DIR = obj
# LIBX_DIR = MLX42/
# LIBFT_DIR	= lib/
# CC = clang
# CFLAGS = -g3
# INC = -Iinclude -Iinc
# OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
# MAKE_LIBFT = $(LIBFT_DIR)/libft.a
# MAKE_LIBX = $(LIBX_DIR)/build/libmlx42.a
# LIB =  $(MAKE_LIBFT) $(MAKE_LIBX) -ldl -lglfw -pthread -lm

# ################## SRC ###################
# SRC = main.c \
# 	parsing/ft_parsing.c \
# 	parsing/ft_utils.c \
# 	parsing/ft_free.c \
# 	parsing/ft_map.c


# ##########################################

# all: $(NAME)

# $(NAME): $(MAKE_LIBX) $(MAKE_LIBFT) $(OBJ_DIR) $(OBJ)
# 	$(CC) $(CFLAGS) $(OBJ) -o $@ $(LIB)

# $(MAKE_LIBX):
# 	cmake $(LIBX_DIR) -B $(LIBX_DIR)/build && make -C $(LIBX_DIR)/build -j4

# $(MAKE_LIBFT):
# 	$(MAKE) -C $(LIBFT_DIR)

# $(OBJ_DIR):
# 	mkdir -p $@

# $(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
# 	mkdir -p $(@D)
# 	$(CC) -o $@ -c $< $(CFLAGS) $(INC)

# clean:
# 	rm -rf $(OBJ_DIR)

# fclean: clean
# 	rm -f $(NAME)
# 	rm -rf $(LIBX_DIR)/build

# re: fclean all

# .PHONY: all fclean clean re
