CFLAGS = -Wall -Wextra -Werror
CC = gcc
SRC = main.c\
		get_next_line.c\
		get_next_line_utils.c\
		error_check_playable.c\
		preprocessing.c\
		error_check_map.c\
		error_check_main.c\
		error_check_file_name.c\
		free.c\
		move.c\
		utility_mlx.c\

LFLAGS = -L./mlx_linux -lmlx -lXext -lX11 -lm -lbsd

OBJ = $(SRC:.c=.o)
NAME = so_long

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) libftprintf.a $(LFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -Imlx_linux -O3 -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

