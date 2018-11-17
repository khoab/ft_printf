NAME		= libft.a
CFLAGS		= -Wall -Werror -Wextra -I. -c
FILES		= ft_memset.c \
				ft_strchr.c \
				ft_atoi.c \
				ft_strlen.c \
				ft_strncmp.c \
				ft_inline_helper.c \
				ft_strnew.c \
				ft_pow.c \
				ft_strcat.c \
				ft_memalloc.c \
				ft_strdup.c \
				ft_strdel.c \
				ft_memdel.c

OBJ			= $(FILES:%.c=%.o)

RESET = \033[0m
GREEN = \033[1;32m
RED = \033[1;31m

all: $(NAME)

# This won't run if the .o files don't exist or are not modified
$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)
	@printf "\n$(GREEN)[✓] $(RESET)\x1B[32m$(NAME) ready!\n\x1b[37m"

# This won't run if the source files don't exist or are not modified
$(OBJ): $(FILES)
	@printf "\n\x1B[38;5;208mCompiling $(NAME)...\n\x1b[37m"
	@gcc $(CFLAGS) $(FILES)

clean:
	@rm -f $(OBJ)
	@printf "$(RED)[x] $(RESET)\x1B[31m$(NAME) object files deleted\n"

fclean: clean
	@rm -f $(NAME)
	@printf "$(RED)[x] $(RESET)\x1B[31m$(NAME) deleted\n"

re: fclean all

# I use .PHONY to make sure that gnu make will still run even if files called
# clean / fclean / all and re already exist in the directory
.PHONY: clean fclean all re