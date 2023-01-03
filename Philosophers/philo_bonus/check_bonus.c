/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozer <mozer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 21:20:07 by mozer             #+#    #+#             */
/*   Updated: 2022/12/24 23:11:37 by mozer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	lock_check(t_philos *philo)
{
	if (philo->data->all_eaters == 1)
	{
		my_sleep(philo->data->die_time);
		return (0);
	}
	return (1);
}

void	*dead_check(void *pth)
{
	t_philos	*philo;

	philo = (t_philos *)pth;
	while (1)
	{
		sem_wait(philo->data->sem_eat);
		if ((get_time() - philo->last_eat) > philo->data->die_time && \
				philo->last_eat != 0)
		{
			sem_wait(philo->data->sem_death);
			my_sleep(3);
			messages(get_time(), "Died", philo);
			exit(1);
		}
		sem_post(philo->data->sem_eat);
		if (philo->data->died)
			break ;
		if (total_eating(philo->data, philo) == 1)
			break ;
	}
	return (NULL);
}

int	ft_atoi(char *str)
{
	int	i;
	int	n;
	int	res;

	i = 0;
	n = 1;
	res = 0;
	while (str[i] <= 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			n *= -1;
		i++;
	}
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10) + str[i] - '0';
		i++;
	}
	return (res * n);
}

int	args_check(int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (ft_atoi(av[i]) <= 0)
			return (0);
		i++;
	}
	return (1);
}
