CC = cc
CFLAGS = -Wall -Wextra -Werror -Iincludes -g -pthread
NAME = philo

SRC = main.c \
      src/cleaner/cleanup.c \
      src/forks/grap_forks.c \
      src/forks/init_forks.c \
      src/logic/gameloop.c \
      src/mutex/init_mutex.c \
      src/parsing/parsing.c \
      src/parsing/validation.c \
      src/philosophers/init_philos.c \
      src/philosophers/is_philo_dead.c \
      utils/ft_funcs.c \
      utils/logs.c \
      utils/time.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re