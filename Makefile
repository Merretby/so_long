NAME = so_long
CC = cc
CFLAGS = -Wall -Werror -Wextra #-g3 -fsanitize=address 
CFILES = test.c get_next_line.c get_next_line_utilis.c utiles.c
OFILSE = $(CFILES:.c=.o)


all: $(NAME)


$(NAME): $(OFILSE)
	$(CC) $(CFLAGS) $(OFILSE) -o $(NAME)

clean:
	rm -f $(OFILSE)

fclean: clean
	rm -f $(NAME) 

re: fclean all