# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ltesha <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/22 18:06:16 by ltesha            #+#    #+#              #
#    Updated: 2019/07/25 07:20:19 by ltesha           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ./src/
INC = ./inc/

FILES = $(SRC)main.c $(SRC)utils.c $(SRC)creator.c $(SRC)valid_test.c

OBJ = main.o utils.o creator.o valid_test.o
EXE = bsq

FLAGS = -Wall -Wextra -Werror

all:
	gcc $(FILES) -c -I $(INC)
	gcc $(OBJ) $(FLAGS) -o $(EXE)

clean:
	rm -f *.o

fclean: clean
	rm -f $(EXE)

re: fclean all
