# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kchetty <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/07 14:11:28 by kchetty           #+#    #+#              #
#    Updated: 2016/11/28 08:34:39 by kchetty          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=gomoku

CC=g++

CFLAGS= -Wall -Wextra -Werror -g

RM=rm -f

PATH_SRC= ./src/

PATH_HD= -I includes/

SRC = $(PATH_SRC)main.cpp

OBJ = main.o

$(NAME):
	@echo "Compiling binaries..."	
	@$(CC) -std=c++11 $(CFLAGS) $(PATH_HD) -c $(SRC)
	@$(CC) -std=c++11 -o $(NAME) $(OBJ)
	@echo "Compilation was successful!"

all: $(NAME)

clean:
	@echo "Cleaning object files..."
	@$(RM) $(OBJ)
	@echo "Cleaning libft object files..."
	@echo "Done cleaning!"
fclean:
	@echo "Cleaning object files..."
	@$(RM) $(OBJ)
	@echo "Cleaning libft object & binary files..."
	@echo "Cleaning binaries..."
	@$(RM) $(NAME)
	@echo "Done cleaning!"

norme:
	@clear
	@norminette $(SRC)

re: fclean all
