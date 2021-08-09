SRCS = do_op.c do_op_functions.c ft_atoi.c put_things.c

OBJS = ${SRCS:.c=.o}

NAME = do-op

.c.o:
	gcc -Wall -Wextra -Werror -c $< -o ${<:.c=.o}

all: ${NAME}

${NAME}: ${OBJS}
	gcc ${OBJS} -o ${NAME}

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

.PHONY: clean fclean
