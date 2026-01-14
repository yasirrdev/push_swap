NAME		= push_swap

CC			= cc
CFLAGS		= -Wall -Wextra -Werror -Iincludes

SRC			= main.c \
			  src/parsing/parse.c \
			  src/utils/check_errors.c \
			  src/utils/stack.c \
			  src/moves/moves.c \
			  src/moves/push.c \
			  src/moves/reverse_rotate.c \
			  src/moves/rotate.c \
			  src/moves/swap.c \
			  src/algorithm/indexing.c \
			  src/algorithm/lis.c \
			  src/algorithm/lisutils.c \
			  src/algorithm/push_swap.c \
			  src/algorithm/sorting.c \

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
