CC = gcc
FLAGS = -framework OpenGL -framework AppKit -L./minilibx -lmlx -glldb
NAME = so_long
SRCS = get_next_line/*.c libft/*.c Errors/*.c Events/*.c Graphics/*.c Init/*.c main.c
INCLUDES = Includes/*.h
BONUSSRCS = get_next_line/*.c libft/*.c bonus/Errors/*.c bonus/Events/*.c bonus/Graphics/*.c bonus/Init/*.c bonus/main_bonus.c


all:
	@echo "\033[1;36m - Compiling..."
	# @make -C libft
	@$(CC) $(SRCS) -o $(NAME) $(FLAGS)
	@echo "\033[1;32m     [OK]"

%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx
	$(FLAGS)

clean:
	@echo "\033[1;35m[🧹Cleaning...🧹]"
	@rm -rf $(NAME)
	@rm -rf $(NAME).dSYM
	# @make clean -C libft

fclean: clean
	@echo "\033[1;35m[🧹FCleaning...🧹]"
	@rm -rf $(NAME)
	@rm -rf $(NAME).dSYM
	# @make fclean -C libft

re: fclean all

norm:
	@norminette $(SRCS)
	@norminette $(INCLUDES)

normBonus:
	@norminette $(BONUSSRCS)

.PHONY: all clean fclean norm re