# **************************************************************************** #
#                            Makefile para ft_printf                           #
# **************************************************************************** #

NAME        = libftprintf.a
LIBFT       = ./libft/libft.a
AR          = ar rcs  # Cambié a 'rcs' (estándar, crea índice para la biblioteca)
# Archivos del proyecto
SRC         = ft_convert_int.c ft_convert_string.c ft_printf.c utils.c
OBJ_MANDATORY = $(SRC:.c=.o)

# Comandos y flags
CC          = cc
CFLAGS      = -Wall -Wextra -Werror
INCLUDES    = -I. -I./libft  # Incluye directorio actual y libft para encabezados

# Default
all: $(NAME)

$(LIBFT):
	$(MAKE) bonus -C libft

$(NAME): $(LIBFT) $(OBJ_MANDATORY)  # Usar OBJ_MANDATORY en lugar de OBJ
	cp $(LIBFT) $(NAME)
	$(AR) $(NAME) $(OBJ_MANDATORY)

bonus: $(NAME)  # Si quieres, aquí puedes adaptar para usar ft_printf_bonus.c

clean:
	$(MAKE) clean -C libft
	rm -f $(OBJ_MANDATORY)  # Eliminé $(OBJ) porque no está definido

fclean: clean
	$(MAKE) fclean -C libft
	rm -f $(NAME)

re: fclean all

%.o: %.c ft_printf.h  # Añadí ft_printf.h como dependencia (ajusta si usas otro encabezado)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

.PHONY: all bonus clean fclean re
