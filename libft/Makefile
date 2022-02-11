NAME = libft.a

HEADER = libft.h

GCC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
CC = $(GCC) $(CFLAGS)

SRCS = $(wildcard *.c)
OBJECTS = $(SRCS:.c=.o)

all			: $(NAME)

$(NAME)		: $(SRCS) $(HEADER)
	@$(CC) -c $(SRCS)
	@ar rc $(NAME) $(OBJECTS)
	@ranlib $(NAME)

ob 			: $(SRCS)
	@$(CC) -c  $(SRCS)

run			:
	@$(CC) $(SRCS) && ./a.out

clean		: $(OBJECTS)
	@$(RM) $(OBJECTS)

fclean		: clean
	@rm -f $(NAME)

re			: fclean all
