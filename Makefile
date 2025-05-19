# **************************************************************************** #
#                            Makefile para ft_printf                           #
# **************************************************************************** #

NAME        = libftprintf.a
LIBFT_DIR   = ./libft
LIBFT_A     = $(LIBFT_DIR)/libft.a

# Archivos del proyecto
SRC_MANDATORY = ft_convert_int.c ft_convert_string.c ft_printf.c utils.c
OBJ_MANDATORY = $(SRC_MANDATORY:.c=.o)

# Comandos y flags
CC          = cc
CFLAGS      = -Wall -Wextra -Werror
INCLUDES    = -I include -I $(LIBFT_DIR)

# Default
all: $(NAME)

$(NAME): $(OBJ_MANDATORY)
	@$(MAKE) -C $(LIBFT_DIR)
	@cp $(LIBFT_A) .
	@ar x libft.a                                  # Extrae los .o
	@ar rcs $(NAME) $(OBJ_MANDATORY) *.o           # Combina todo
	@rm -f libft.a *.o                             # Limpia .o sueltos

bonus: $(NAME)  # Si quieres, aquí puedes adaptar para usar ft_printf_bonus.c

clean:
	@rm -f $(OBJ_MANDATORY)
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
