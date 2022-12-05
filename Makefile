NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC = ./so_long_utils.c ./main.c

all : ${NAME}

OBJS = ${SRC:.c=.o}

${NAME} : ${OBJS}
	make all bonus -C ./Libft
	gcc ${CFLAGS} ${SRC} ./Libft/libft.a -o so_long

clean :
	rm -f ${OBJS} ${OBJS_BONUS}

fclean : clean
	rm -f ./so_long

re : fclean all

.PHONY: .c.o all clean fclean re