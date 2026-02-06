CC = cc
CFLAGS = -Wall -Wextra -Werror -Iincludes -g
NAME = philosopher

SRC = main.c \
      $(wildcard */*.c) \
      $(wildcard src/*/*.c)

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

run: $(NAME)
	./$(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re run