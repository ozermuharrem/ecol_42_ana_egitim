# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mozer <mozer@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/22 16:15:22 by mozer             #+#    #+#              #
#    Updated: 2022/02/22 21:50:05 by mozer            ###   ########.fr        #
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

$(NAME)		: $(SRCS) $(HEADER)
	@$(CC) -c $(SRCS) $(BNS_SRCS)
	@ar rc $(NAME) $(OBJS) $(BNS_OBJS)
	@ranlib $(NAME)

ob 			: $(SRCS) $(BNS_SRCS)
	@$(CC) -c  $(SRCS) $(BNS_SRCS)

run			:
	@$(CC) $(SRCS) $(BNS_SRCS) && ./a.out

clean		: $(OBJS)
	@$(RM) $(OBJS) $(BNS_OBJS)

fclean		: clean
	@rm -f $(NAME)

re			: fclean all