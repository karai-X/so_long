CFLAGS = -Wall -Wextra -Werror
CC = gcc
SRCS = main.c\
		get_next_line.c\
		get_next_line_utils.c\
		error_check_playable.c\
		preprocessing.c\
		error_check_map.c\
		error_check_main.c\
		free.c\

LFLAGS = -L./mlx_linux -lmlx -lXext -lX11 -lm -lbsd

OBJ = $(SRCS:.c=.o)
NAME = aa

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) libftprintf.a $(LFLAGS)

%.o: %.c
	$(CC) -Imlx_linux -O3 -c $< -o $@

clean:
	rm -f $(NAME) $(OBJ) *~ core *.core

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

