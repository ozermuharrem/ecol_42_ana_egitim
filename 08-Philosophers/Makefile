NAME		= philo/philo
NAME_BONUS	= philo_bonus/philo_bonus
CC			= gcc
FLAG		= -Wall -Wextra -Werror
DTRCSFLAGS	= -g -fsanitize=thread

all:	$(NAME)
$(NAME): philo/*.c
	$(CC) philo/*.c $(FLAG) -o $(NAME)

bonus:	$(NAME_BONUS)
$(NAME_BONUS): philo_bonus/*.c
	$(CC) philo_bonus/*.c $(FLAG) -o $(NAME_BONUS)

race:
	$(CC) philo/*.c $(FLAG) $(DTRCSFLAGS) -o $(NAME)

clean:
	@echo "\033[1;35m[🧹Cleaning...🧹]"
	@rm -rf philo/*.o
	@rm -rf philo_bonus/*.o

fclean: clean
	@echo "\033[1;36m[🧹Fcleaning...🧹]"
	@rm -rf $(NAME)
	@rm -rf $(NAME_BONUS)
re: fclean all
	@echo "\033[1:31m[fclean-all]]"

re_bonus: fclean bonus

.PHONEY: all bonus race clean fclean re re_bonus
