/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozer <mozer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 22:07:54 by mozer             #+#    #+#             */
/*   Updated: 2022/05/20 22:07:56 by mozer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_talk.h"

void	last(int *array, int *i, siginfo_t *siginfo)
{
	int	num;

	if (*i == 8)
	{
		kill(siginfo->si_pid, SIGUSR2);
		num = convert_decimal(array);
		*i = 0;
		ft_putchar(num);
	}
}

void	sig_handler(int signum, siginfo_t *siginfo, void *unused)
{
	static int	i = 0;
	static int	array[8];

	if (signum == SIGUSR2)
	{
		array[i++] = 1;
		last(array, &i, siginfo);
	}
	else if (signum == SIGUSR1)
	{
		array[i++] = 0;
		last(array, &i, siginfo);
	}
	(void)unused;
}

int	main(void)
{
	int					pid;
	struct sigaction	act;

	pid = getpid();
	ft_bzero(&act, sizeof(act));
	act.sa_flags = SA_SIGINFO;
	act.sa_sigaction = sig_handler;
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	ft_putstr("PID => ");
	ft_putnbr(pid);
	ft_putstr("\n");
	while (1)
		pause();
	ft_putstr("\n");
}
