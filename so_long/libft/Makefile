# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mozer <mozer@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/22 16:15:22 by mozer             #+#    #+#              #
#    Updated: 2022/02/23 11:36:18 by mozer            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

HEADER = libft.h

GCC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
CC = $(GCC) $(CFLAGS)

SRCS        = $(shell find . -type f ! -name "ft_lst*.c" -name "ft_*.c")
BNS_SRCS    = ft_lst*.c
OBJS        = $(SRCS:.c=.o)
BNS_OBJS    = $(BNS_SRCS:.c=.o)

all			: $(NAME)

$(NAME)		: $(SRCS) $(HEADER) $(OBJS)
	@$(CC) -c $(SRCS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

bonus		: $(HEADER) $(BNS_SRCS)
	@$(CC) -c $(BNS_SRCS)
	@ar rc $(NAME) $(BNS_OBJS)
	@ranlib $(NAME)

clean		: $(OBJS)
	@$(RM) *.o *.out *.gch

fclean		: clean
	@$(RM) $(NAME)

re			: fclean all

.PHONY		: all clean fclean re bonus