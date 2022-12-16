NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC = ./so_long_utils.c ./main.c ./So_long_errors2.c

all : ${NAME}

OBJS = ${SRC:.c=.o}

${NAME} : ${OBJS}
	make all bonus -C ./Libft
	${CC} ${CFLAGS} ${SRC} ./Libft/libft.a -o $(NAME)

clean :
	rm -f ${OBJS}

fclean : clean
	rm -f ./so_long
	make fclean -C ./Libft 

re : fclean all

.PHONY: .c.o all clean fclean re
