NAME = libftprintf.a
LIBFT_NAME = libft.a
LIBFT_DIR = ./libft

CFLAGS  = -Wall -Wextra -Werror
CC = cc
AR = ar rcs

SRC =  ft_aux.c ft_handle_integer.c ft_handle_unsigned_int.c ft_printf.c ft_scan_aux.c ft_scan.c main.c

OBJS = $(SRC:.c=.o)

all: $(NAME)

$(LIBFT_DIR)/$(LIBFT_NAME):
	@$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(LIBFT_DIR)/$(LIBFT_NAME) $(OBJS)
	@$(AR) $(NAME) $(OBJS)
	@echo "$(NAME) created!"

clean:
	@rm -rf $(OBJS)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@echo "objects cleanded!!"

fclean:
	@rm -rf $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@echo "$(NAME) $(LIBFT_NAME) and objects cleaned!!"

re: fclean all

.PHONY: all clean fclean re
