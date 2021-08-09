SRCS = srcs/ft_putchar.c srcs/ft_swap.c srcs/ft_putstr.c srcs/ft_strlen.c srcs/ft_strcmp.c

OBJS = ${SRCS:.c=.o}

HEADERS = ./includes/

NAME = libft.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

# $< = first prerequisite (= xxxx.c)
# -I = search for headers in this directory
.c.o:
	${CC} ${CFLAGS} -I ${HEADERS} -c $< -o ${<:.c=.o}

all:		${NAME}

${NAME}:	${OBJS}
	ar rc ${NAME} ${OBJS}

clean:
	rm -f ${OBJS}

fclean:		clean
	rm -f ${NAME}

re:			fclean all

.PHONY:	all clean fclean re