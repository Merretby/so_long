NAME = so_long
CC = cc
CFLAGS = -Wall -Werror -Wextra #-g3 -fsanitize=address
MLX_FLAG = -lmlx_Linux -includes_mlx/Lminilibx-linux  -lXext -lX11 -lm -lz
BFILES = so_long_bonus.c get_next_line_bonus.c get_next_line_utilis_bonus.c \
utiles_bonus.c error_bonus.c parsing_bonus.c moves_bonus.c \
parsing1_bonus.c textu_bonus.c
BOFILSE = $(BFILES:.c=.o)
PRINTF = printf/libftprintf.a

all: $(NAME)

$(NAME): $(PRINTF) $(BOFILSE)
	$(CC) $(CFLAGS) $(BOFILSE) $(PRINTF) $(MLX_FLAG) -o $(NAME)

$(PRINTF) :
	make -C printf

clean:
	rm -f $(BOFILSE)
	make clean -C printf

fclean: clean
	rm -f $(NAME)
	make fclean -C printf

re: fclean all