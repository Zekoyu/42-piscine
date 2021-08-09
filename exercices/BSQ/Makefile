# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mframbou <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/28 15:18:37 by mframbou          #+#    #+#              #
#    Updated: 2021/07/28 15:18:58 by mframbou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = bsq.c handle_error.c parse_rules.c parse.c print_map.c str_helper.c validate_map.c parse_char.c init.c find_fill_bsq.c

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
