CC = gcc
FLAGS = -Wall -Wextra -Werror -framework OpenGL -framework AppKit -L./mandatory/minilibx -lmlx
FLAGS_FWIN = -Lmlx -lmlx -L/usr/lib -Imlx -lXext -lX11 -lm -lz
NAME = cub3d
NAME_BONUS = cub3d_bonus
SRCS = mandatory/srcs/*.c mandatory/libft/*.c
SRCS_BONUS = bonus/srcs/*.c bonus/libft/*.c
HEADERS = bonus/srcs/*.h bonus/libft/*.h mandatory/srcs/*.h mandatory/libft/*.h

all: $(NAME)

$(NAME): $(SRCS) $(HEADERS)
	@$(CC) $(SRCS) -o $(NAME) $(FLAGS)

windows: $(SRCS)
	@$(CC) $(SRCS) -o $(NAME) $(FLAGS_FWIN)

clean:
	@rm -rf $(NAME)
	@rm -rf $(NAME_BONUS)

fclean:	clean
	@rm -rf $(NAME)
	@rm -rf $(NAME_BONUS)
	@rm -rf $(NAME).dSYM
	@rm -rf $(NAME_BONUS).dSYM

re: fclean all

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(SRCS_BONUS) $(HEADERS)
	@$(CC) $(SRCS_BONUS) -o $(NAME_BONUS) $(FLAGS)

norm:
	@norminette $(SRCS) $(SRCS_BONUS) $(HEADERS)

.PHONY: all clean fclean norm re bonus
