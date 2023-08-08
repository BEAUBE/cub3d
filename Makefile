# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: axcallet <axcallet@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/07 10:04:45 by axcallet          #+#    #+#              #
#    Updated: 2023/08/08 17:53:29 by ajoliet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d
SRC_DIR = src
OBJ_DIR = obj
LIBX_DIR = MLX42/
LIBFT_DIR	= lib/
CC = clang
CFLAGS = -g3
INC = -Iinclude -Iinc
OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
MAKE_LIBFT = $(LIBFT_DIR)/libft.a
MAKE_LIBX = $(LIBX_DIR)/build/libmlx42.a
LIB =  $(MAKE_LIBFT) $(MAKE_LIBX) -ldl -lglfw -pthread -lm

################## SRC ###################
SRC = main.c \
	parsing/ft_parsing.c \
	parsing/ft_utils.c 


##########################################

all: $(NAME)

$(NAME): $(MAKE_LIBX) $(MAKE_LIBFT) $(OBJ_DIR) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $@ $(LIB)

$(MAKE_LIBX):
	cmake $(LIBX_DIR) -B $(LIBX_DIR)/build && make -C $(LIBX_DIR)/build -j4

$(MAKE_LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(OBJ_DIR):
	mkdir -p $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(@D)
	$(CC) -o $@ -c $< $(CFLAGS) $(INC)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)
	rm -rf $(LIBX_DIR)/build

re: fclean all

.PHONY: all fclean clean re
