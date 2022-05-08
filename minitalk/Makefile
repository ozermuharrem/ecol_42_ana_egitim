SRC_SERVER = server.c minitalk_utulis.c minitalk_utulis2.c
SRC_CLIENT = client.c minitalk_utulis.c minitalk_utulis2.c

NAME_SERVER = server
NAME_CLIENT = client

OBJ_SERVER = server.o minitalk_utulis.o minitalk_utulis2.o
OBJ_CLIENT = client.o minitalk_utulis.o minitalk_utulis2.o

CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME_CLIENT) $(NAME_SERVER)

$(NAME_SERVER): $(OBJ_SERVER)
		$(CC) $(CFLAGS) $(SRC_SERVER) -o server

$(NAME_CLIENT): $(OBJ_CLIENT)
		$(CC) $(CFLAGS) $(SRC_CLIENT) -o client

clean:
		rm -f $(OBJ_SERVER) $(OBJ_CLIENT)

fclean: clean
		rm -f $(NAME_SERVER) $(NAME_CLIENT)

re: fclean all

.PHONY: server client all re fclean cleans