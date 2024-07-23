NAME = push_swap
BONUS_NAME = checker

CC = clang

CFLAGS = -Wall -Wextra -Werror -I libft -I includes

LIBFT = libft/libft.a

SRC = src/check_if_dup.c \
      src/fill_stack.c \
      src/finders.c \
      src/min_on_top.c \
      src/moves_nodes_from_stack.c \
      src/push_swap.c \
      src/rotate.c \
      src/push.c \
      src/rev_rotate.c \
      src/set_stack.c \
      src/sort_stack.c \
      src/swap_it_up.c

BONUS_SRC = src_bonus/checker.c

OBJ = $(SRC:.c=.o)
BONUS_OBJ = $(BONUS_SRC:.c=.o)

all: $(LIBFT) $(NAME)

$(LIBFT):
	@make -C libft

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -Llibft -lft -o $(NAME)

bonus: $(LIBFT) $(BONUS_OBJ) $(OBJ)
	@$(CC) $(CFLAGS) $(BONUS_OBJ) $(filter-out src/push_swap.o,$(OBJ)) -Llibft -lft -o $(BONUS_NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ) $(BONUS_OBJ)

fclean: clean
	@rm -f $(NAME) $(BONUS_NAME)
	@make -C libft fclean

re: fclean all