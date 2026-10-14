CC = cc
CFLAGS = -Wall -Werror -Wextra
SRC = manager.c my_algo.c push_swap.c sort.c \
      sort_move.c splite.c string.c tool.c linked_list_tools.c \
      help.c
OBJ = $(SRC:.c=.o)

NAME = push_swap

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@
	
clean:
	rm -rf $(OBJ)
fclean: clean
	rm -f $(NAME)
re: fclean all

