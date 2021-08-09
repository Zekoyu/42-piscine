SRCS = bsq.c handle_error.c parse_rules.c parse.c print_map.c str_helper.c validate_dict.c parse_char.c init.c find_fill_bsq.c

OBJS = ${SRCS:.c=.o}

NAME = bsq

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
