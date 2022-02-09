# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agallipo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/07 10:43:28 by agallipo          #+#    #+#              #
#    Updated: 2022/02/08 16:18:27 by agallipo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = srcs/pipex.c srcs/env.c

OBJS = ${SRCS:.c=.o}

#CFLAGS = -Wall -Wextra -Werror

INCLUDES = includes/

LIBFTDIR = libft/

NAME = pipex

RM = rm -fr

all:	 ${NAME}

${NAME}: ${OBJS}
	make -sC ${LIBFTDIR}
	cp ./libft/libft.a .
	${CC} libft.a ${OBJS} -I ${INCLUDES} -o ${NAME}

%.o: %.c
	${CC} ${CFLAGS} -I ${INCLUDES} -c $< -o $@

clean:
			make -sC ${LIBFTDIR} clean
			${RM} ${OBJS} libft.a

fclean: clean

			make -sC ${LIBFTDIR} fclean
			${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re

