NAME        = libftprintf.a
LIBFT       = libft/libft.a
AR          = ar rcs

# project's files
SRC         = ft_convert_int.c ft_convert_string.c ft_printf.c utils.c
OBJ_MANDATORY = $(SRC:.c=.o)

# Commands and flgs
CC          = cc
CFLAGS      = -Wall -Wextra -Werror
INCLUDES    = -I. -I./libft

define LOADING_BAR_COMP
	@printf "\033[0;32mCompiling ftprint: ["
	@for i in `seq 1 20`; do \
		printf "█"; \
		sleep 0.05; \
	done; \
	printf "] ✔️\033[0m\n"
endef

# Default
all: $(NAME)

#compile the libft's makefile
$(LIBFT):
	@$(MAKE) -C libft --silent

$(NAME): $(LIBFT) $(OBJ_MANDATORY)
	@cp $(LIBFT) $(NAME)
	$(call LOADING_BAR_COMP)
	@$(AR) $(NAME) $(OBJ_MANDATORY)

clean:
	@$(MAKE) clean -C libft
	@rm -f $(OBJ_MANDATORY)

fclean: clean
	@$(MAKE) fclean -C libft
	@rm -f $(NAME)

re: fclean all

%.o: %.c ft_printf.h
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

.PHONY: all bonus clean fclean re
