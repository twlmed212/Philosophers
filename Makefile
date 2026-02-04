CC = cc
CFLAGS = -Wall -Wextra -Werror -Iincludes
NAME = Philosopher

SRC = main.c \
      $(wildcard src/*.c) \
      $(wildcard src/cleaner/*.c) \
      $(wildcard utils/*.c)

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