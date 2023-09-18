NAME = minishell
CC = gcc
FLAGS = -Wall -Werror -Wextra
RED = \e[31m
RED2 = e[31m
BLUE = "\e[34m"
GREEN = "\e[32m"
END = "\e[0m"

all: $(NAME)

$(NAME): $(SRC)
	@$(CC) src/*.c libft/*.c  -fcommon -I /goinfre/homebrew/opt/readline/include -L /goinfre/homebrew/opt/readline/lib -lreadline -o $(NAME)
	@echo "\033[31mOluşturuldu ✓\033[0m"
re: fclean all

fclean:
	@rm -rf $(NAME)
	@echo "\033[31mTemizlendi ✓\033[0m"
