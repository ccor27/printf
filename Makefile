NAME        = libftprintf.a
LIBFT       = libft/libft.a
AR          = ar rcs

# project's files
SRC         = ft_convert_int.c ft_convert_string.c ft_printf.c utils.c
OBJ_MANDATORY = $(SRC:.c=.o)

# NEW: Variables for the test executable
TEST_EXEC   = test_ft_printf
TEST_SRC    = main.c

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

# NEW: Rule to run the tests
test: $(NAME) $(TEST_EXEC)
	@echo "\n--- Running ft_printf tests ---"
	@./$(TEST_EXEC)
	@echo "--- Tests finished ---"

# NEW: Rule to compile the test executable
$(TEST_EXEC): $(TEST_SRC) $(NAME)
	@$(CC) $(CFLAGS) $(INCLUDES) $(TEST_SRC) $(NAME) -o $@

clean:
	@$(MAKE) clean -C libft
	@rm -f $(OBJ_MANDATORY) $(TEST_EXEC) # Added $(TEST_EXEC) to clean

fclean: clean
	@$(MAKE) fclean -C libft
	@rm -f $(NAME) $(TEST_EXEC) # Added $(TEST_EXEC) to fclean

re: fclean all

%.o: %.c ft_printf.h
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

.PHONY: all bonus clean fclean re test # Added 'test' to .PHONY
# NAME        = libftprintf.a
# LIBFT       = libft/libft.a
# AR          = ar rcs

# # project's files
# SRC         = ft_convert_int.c ft_convert_string.c ft_printf.c utils.c
# OBJ_MANDATORY = $(SRC:.c=.o)

# # Commands and flgs
# CC          = cc
# CFLAGS      = -Wall -Wextra -Werror
# INCLUDES    = -I. -I./libft

# define LOADING_BAR_COMP
# 	@printf "\033[0;32mCompiling ftprint: ["
# 	@for i in `seq 1 20`; do \
# 		printf "█"; \
# 		sleep 0.05; \
# 	done; \
# 	printf "] ✔️\033[0m\n"
# endef

# # Default
# all: $(NAME)

# #compile the libft's makefile
# $(LIBFT):
# 	@$(MAKE) -C libft --silent

# $(NAME): $(LIBFT) $(OBJ_MANDATORY)
# 	@cp $(LIBFT) $(NAME)
# 	$(call LOADING_BAR_COMP)
# 	@$(AR) $(NAME) $(OBJ_MANDATORY)

# clean:
# 	@$(MAKE) clean -C libft
# 	@rm -f $(OBJ_MANDATORY)

# fclean: clean
# 	@$(MAKE) fclean -C libft
# 	@rm -f $(NAME)

# re: fclean all

# %.o: %.c ft_printf.h
# 	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# .PHONY: all bonus clean fclean re
