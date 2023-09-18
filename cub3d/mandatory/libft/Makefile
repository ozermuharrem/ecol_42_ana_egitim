NAME := libft.a

CC := gcc

CFLAGS := -Wall -Wextra -Werror

HEADER := libft.h

SRCS := *.c

OBJECTS := $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(SRCS) $(HEADER)
	@$(CC) $(CFLAGS) -c $(SRCS)
	@ar -rcs $(NAME) $(OBJECTS)

clean:
	@rm -rf $(OBJECTS)

fclean: clean
	@rm -rf $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
