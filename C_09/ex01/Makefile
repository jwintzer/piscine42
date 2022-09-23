# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jwintzer <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/19 12:49:50 by jwintzer          #+#    #+#              #
#    Updated: 2022/09/22 13:13:18 by jwintzer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = srcs/ft_putchar.c srcs/ft_putstr.c srcs/ft_strcmp.c srcs/ft_strlen.c srcs/ft_swap.c

OBJ = ${SRC:.c=.o}

HEADER = includes

all: ${NAME}

${NAME}: ${OBJ}
	ar rc ${NAME} ${OBJ}

clean:
	rm -f ${OBJ}

fclean: clean
	rm -f ${NAME}

re: fclean all

srcs/ft_putchar.o: srcs/ft_putchar.c
	gcc -Wall -Wextra -Werror -I${HEADER} -c srcs/ft_putchar.c -o srcs/ft_putchar.o

srcs/ft_putstr.o: srcs/ft_putstr.c
	gcc -Wall -Wextra -Werror -I${HEADER} -c srcs/ft_putstr.c -o srcs/ft_putstr.o

srcs/ft_strcmp.o: srcs/ft_strcmp.c
	gcc -Wall -Wextra -Werror -I${HEADER} -c srcs/ft_strcmp.c -o srcs/ft_strcmp.o
	
srcs/ft_strlen.o: srcs/ft_strlen.c
	gcc -Wall -Wextra -Werror -I${HEADER} -c srcs/ft_strlen.c -o srcs/ft_strlen.o

srcs/ft_swap.o: srcs/ft_swap.c
	gcc -Wall -Wextra -Werror -I${HEADER} -c srcs/ft_swap.c -o srcs/ft_swap.o
