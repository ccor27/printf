NAME = libftprintf.a
LIBFT_DIR = ./libft
LIBFT_NAME = $(LIBFT_DIR)/libft.a

SRC_MANDATORY = ft_convert_int.c ft_convert_string.c ft_printf.c utils.c
OBJ_MANDATORY = $(SRC_MANDATORY:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I include -I $(LIBFT_DIR)

all: $(NAME)

$(NAME): $(OBJ_MANDATORY)
	make -C $(LIBFT_DIR)
	ar rcs $(NAME) $(OBJ_MANDATORY)

bonus: $(OBJ_MANDATORY)
	make -C $(LIBFT_DIR)
	ar rcs $(NAME) $(OBJ_MANDATORY)

clean:
	rm -f $(OBJ_MANDATORY)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re bonus
