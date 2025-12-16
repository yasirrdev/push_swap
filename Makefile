NAME		= push_swap

CC			= cc
CFLAGS		= -Wall -Wextra -Werror -Iincludes

SRC			= push_swap.c \
			  src/parsing/parse.c \
			  src/parsing/check_errors.c \
			  src/parsing/indexing.c \
			  src/stack/list.c \
			  src/stack/stack_ops.c \
			  src/stack/stack_utils.c \
			  src/moves/moves_internal.c \
			  src/moves/swap.c \
			  src/moves/push.c \
			  src/moves/rotate.c \
			  src/moves/reverse_rotate.c \
			  src/algorithm/lis.c \
			  src/algorithm/push_non_lis.c \
			  src/algorithm/insert_back.c \
			  src/algorithm/final_rotate.c \
			  src/utils/errors.c \
			  src/utils/free.c

OBJ			= $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
# Si NO usas libft:
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
clean:
	rm -f $(OBJ)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
