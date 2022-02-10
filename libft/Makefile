NAME = libft.a

CC = gcc

CFLAGS = -Wall-Wextra-Werror

HEADER = libft.h

SRCS = ft_bzero.c 		\
	   ft_isalnum.c 	\
	   ft_isalpha.c 	\
	   ft_isascii.c 	\
	   ft_isdigit.c 	\
	   ft_isprint.c 	\
	   ft_memcmp.c 		\
	   ft_memcpy.c 		\
	   ft_memmove.c 	\
	   ft_memset.c 		\
	   ft_strchr.c 		\
	   ft_strlcat.c		\
	   ft_strlen.c		\

OBJECTS = $(SRCS:.c=.o)
all: $(NAME)
$(NAME): $(SRCS) $(HEADER)
	@$(CC) $(CFLAGS) -c $(SRCS)
	@ar rc $(NAME) $(OBJECTS)
	@ranlib $(NAME)
clean:
	@rm -f $(OBJECTS)
fclean: clean
	@rm -f $(NAME)
re: fclean all
