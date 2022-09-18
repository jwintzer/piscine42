# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ljerinec <ljerinec@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/18 10:08:33 by ljerinec          #+#    #+#              #
#    Updated: 2022/09/18 21:23:27 by ljerinec         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = rush-02

SRC = *.c

all: $(NAME)

$(NAME):
	cc -Wall -Werror -Wextra -o $(NAME) $(SRC)

clean:
	/bin/rm -f *.o

fclean: clean
	/bin/rm -f $(NAME)