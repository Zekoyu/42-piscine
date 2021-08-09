SRCS = ${wildcard *.c}

OBJS = ${SRCS:.c=.o}

NAME = rush-02

.c.o:
	gcc -Wall -Wextra -Werror -c $< -o ${<:.c=.o}

all: ${NAME}

${NAME}: ${OBJS}
	gcc ${OBJS} -o ${NAME}

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: clean fclean
