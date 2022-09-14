# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mozer <mozer@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/24 02:00:29 by mozer             #+#    #+#              #
#    Updated: 2022/09/14 20:20:55 by mozer            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME :=	push_swap
CC := gcc
FLAGS := -Wall -Wextra -Werror
FILES := $(shell find . -type f -name "*.c")
OBJNAME := $(FILES:%.c=%.o)

all : $(NAME)

$(NAME): $(OBJNAME)
	@$(CC) $(FLAGS) $(OBJNAME) -o $(NAME)

clean:
	@rm -rf *.o

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY : re fclean clean all
