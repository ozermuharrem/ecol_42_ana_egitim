# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    MAKEFILE                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mozer <mozer@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/24 02:00:29 by mozer             #+#    #+#              #
#    Updated: 2022/06/24 02:19:33 by mozer            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAMEFILE = pushswap
NAME =	./*.c
CC = gcc
FLAGS = -Wall -Wextra -Werror
OBJNAME = $(NAME:.c=.o)

all :
	$(CC) $(FLAGS) $(NAME) -o $(NAMEFILE)

clean:
	rm -rf $(OBJNAME)

fclean: clean
	rm -rf $(NAMEFILE)

norm:
	norminette *.[ch]

re:
	fclean all

.PHONY : re fclean clean all  norm