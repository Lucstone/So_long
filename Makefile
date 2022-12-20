NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g
SRC = ./so_long_utils.c ./main.c ./So_long_errors2.c

all : ${NAME}

OBJS = ${SRC:.c=.o}

%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

$(NAME): $(OBJS)
	make all bonus -C ./Libft
	$(CC) $(OBJS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME) ./Libft/libft.a

clean :
	rm -f ${OBJS}

fclean : clean
	rm -f ./so_long
	make fclean -C ./Libft
	

re : fclean all

.PHONY: .c.o all clean fclean bonus re
