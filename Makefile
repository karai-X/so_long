CFLAGS = -Wall -Wextra -Werror
CC = cc
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
		initialize1.c\
		initialize2.c\

LIBFTPRINTF = libftprintf.a
LIBFTPRINTF_PATH = ./ft_printf
MLX_PATH = ./mlx_linux
LFLAGS = -L./mlx_linux -lmlx -lXext -lX11 -lm -lbsd

OBJ = $(SRC:.c=.o)
NAME = so_long

all: $(NAME)

$(NAME): $(OBJ) $(LIBFTPRINTF_PATH)/$(LIBFTPRINTF)
	$(CC) $(CFLAGS) -o $@ $^ $(LFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -Imlx_linux -O3 -c $< -o $@

$(LIBFTPRINTF_PATH)/$(LIBFTPRINTF):
	make -C $(LIBFTPRINTF_PATH) all
	
mlx:
	make -C $(MLX_PATH) all
	
mlx_clean:
	make -C $(MLX_PATH) clean

clean:
	make -C $(LIBFTPRINTF_PATH) clean
	rm -f $(OBJ)

fclean: clean
		make -C $(LIBFTPRINTF_PATH) fclean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
