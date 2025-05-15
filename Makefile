NAME = libftprintf.a
LIBFT_NAME = libft.a
LIBFT_DIR = ./libft

SRC_MANDATORY = ft_convert_int.c ft_convert_string.c ft_printf.c utils.c
SRC_BONUS =

OBJ_MANDATORY = $(SRC_MANDATORY:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ_MANDATORY)
	ar rcs $(NAME) $(OBJ_MANDATORY)

bonus: $(OBJ_MANDATORY) $(OBJ_BONUS)
	ar rcs $(NAME) $(OBJ_MANDATORY) $(OBJ_BONUS)

clean:
	rm -f $(OBJ_MANDATORY) $(OBJ_BONUS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
