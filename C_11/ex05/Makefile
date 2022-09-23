# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jwintzer <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/20 14:26:53 by jwintzer          #+#    #+#              #
#    Updated: 2022/09/20 14:38:01 by jwintzer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = do-op

SRC = main.c ft_atoi.c

all:
	gcc -Wall -Wextra -Werror -o do-op *.c

${NAME}: all

clean:
	rm -f *.o

fclean: clean
	rm -f ${NAME}

re: fclean all
