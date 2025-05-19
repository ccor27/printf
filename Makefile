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

# NAME = libftprintf.a
# LIBFT_DIR = ./libft

# SRC_MANDATORY = ft_convert_int.c ft_convert_string.c ft_printf.c utils.c
# OBJ_MANDATORY = $(SRC_MANDATORY:.c=.o)

# LIBFT_SRCS_NEEDED = $(LIBFT_DIR)/ft_putchar_fd.c \
#                     $(LIBFT_DIR)/ft_putstr_fd.c \
#                     $(LIBFT_DIR)/ft_strlen.c \
#                     $(LIBFT_DIR)/ft_strdup.c \
#                     $(LIBFT_DIR)/ft_lstnew_bonus.c \
#                     $(LIBFT_DIR)/ft_lstadd_back_bonus.c \
#                     $(LIBFT_DIR)/ft_itoa.c \
#                     $(LIBFT_DIR)/ft_utoa.c \
#                     $(LIBFT_DIR)/ft_tolower.c \
#                     $(LIBFT_DIR)/ft_itoa_base.c \
#                     $(LIBFT_DIR)/ft_strjoin.c \
#                     $(LIBFT_DIR)/ft_isprint.c \
#                     $(LIBFT_DIR)/ft_substr.c \
#                     $(LIBFT_DIR)/ft_memcpy.c \
#                     $(LIBFT_DIR)/ft_bzero.c \
#                     $(LIBFT_DIR)/ft_calloc.c

# LIBFT_OBJS_NEEDED = $(LIBFT_SRCS_NEEDED:.c=.o)

# CC = gcc
# CFLAGS = -Wall -Wextra -Werror
# INCLUDES = -I include -I $(LIBFT_DIR)

# all: $(NAME)

# $(NAME): $(OBJ_MANDATORY) $(LIBFT_OBJS_NEEDED)
# 		$(CC) $(CFLAGS) -c $(LIBFT_SRCS_NEEDED) $(INCLUDES) # Compila los .c de libft
# 		ar rcs $(NAME) $(OBJ_MANDATORY) $(LIBFT_OBJS_NEEDED)

# bonus: $(OBJ_MANDATORY) $(LIBFT_OBJS_NEEDED)
# 		$(CC) $(CFLAGS) -c $(LIBFT_SRCS_NEEDED) $(INCLUDES) # Compila los .c de libft
# 		ar rcs $(NAME) $(OBJ_MANDATORY) $(LIBFT_OBJS_NEEDED)

# clean:
# 		rm -f $(OBJ_MANDATORY) $(LIBFT_OBJS_NEEDED)
# 		make -C $(LIBFT_DIR) clean # Opcional: limpiar toda libft

# fclean: clean
# 		rm -f $(NAME)
# 		make -C $(LIBFT_DIR) fclean # Opcional: limpiar toda libft

# re: fclean all

# .PHONY: all clean fclean re bonus
