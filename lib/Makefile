NAME = libft.a

SRC = ft_atoi.c \
      ft_isalnum.c \
      ft_isdigit.c \
      ft_memcmp.c \
      ft_strchr.c \
      ft_strcmp.c \
      ft_strncmp.c \
      ft_toupper.c \
      ft_bzero.c \
      ft_isalpha.c \
      ft_isprint.c \
      ft_memcpy.c \
      ft_strdup.c \
      ft_strrchr.c \
      ft_calloc.c \
      ft_isascii.c \
      ft_memchr.c \
      ft_memset.c \
      ft_strlen.c \
      ft_tolower.c \
      ft_strlcpy.c \
      ft_strlcat.c \
      ft_memmove.c \
      ft_strnstr.c \
      ft_putchar_fd.c \
      ft_putstr_fd.c \
      ft_putnbr_fd.c \
      ft_putendl_fd.c \
      ft_strjoin.c \
      ft_strmapi.c \
      ft_striteri.c \
      ft_substr.c \
      ft_itoa.c \
      ft_strtrim.c \
      ft_split.c \
      ft_putchar.c \
      ft_putstr.c \
	ft_puthexa.c \
	ft_putptr.c \
	ft_putu.c \
	ft_printf.c \
	ft_type.c \
      get_next_line.c \
      ft_putnbr.c

OBJ = $(SRC:%.c=%.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror -I. -g

all : $(NAME)

$(NAME) : $(OBJ) 
	ar -rcs $(NAME) $(OBJ)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
