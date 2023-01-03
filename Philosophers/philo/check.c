/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozer <mozer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 13:23:56 by mozer             #+#    #+#             */
/*   Updated: 2022/12/20 10:53:43 by mozer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_args_check(int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (ft_atoi (av[i]) <= 0)
			return (0);
		i++;
	}
	return (1);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	res;
	int	sig;

	i = 0;
	sig = 1;
	res = 0;
	while (str[i] <= 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sig *= -1;
		i++;
	}
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res * sig);
}

int	ft_free(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philo)
	{
		pthread_detach (data->threads[i]);
		i++;
	}
	return (1);
}

int	death_lock(t_philo *p)
{
	pthread_mutex_lock(&p->data->death);
	if ((p->data->one_died != 0) || \
		p->data->all_eat == p->data->philo)
	{
		pthread_mutex_unlock (&p->data->death);
		return (0);
	}
	pthread_mutex_unlock (&p->data->death);
	return (1);
}
