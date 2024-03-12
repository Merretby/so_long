NAME = so_long
CC = cc
CFLAGS = -Wall -Werror -Wextra #-g3 -fsanitize=address
MLX_FLAG = -lmlx_Linux -includes_mlx/Lminilibx-linux  -lXext -lX11 -lm -lz
CFILES = so_long.c get_next_line.c get_next_line_utilis.c utiles.c error.c parcing.c\
	moves.c parcing1.c textu.c
OFILSE = $(CFILES:.c=.o)


all: $(NAME)

$(NAME): $(OFILSE)
	$(CC) $(CFLAGS) $(OFILSE) $(MLX_FLAG) -o $(NAME)

clean:
	rm -f $(OFILSE)

fclean: clean
	rm -f $(NAME) 

re: fclean all