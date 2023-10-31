/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozer <mozer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 13:35:22 by mozer             #+#    #+#             */
/*   Updated: 2022/12/21 10:26:43 by mozer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_args(int ac, char **av, t_data *data)
{
	data->philo = ft_atoi (av[1]);
	data->die_time = ft_atoi (av[2]);
	data->eat_time = ft_atoi (av[3]);
	data->sleap_time = ft_atoi (av[4]);
	if (ac == 6)
		data->ph_m_eat = ft_atoi (av[5]);
	else
		data->ph_m_eat = -1;
	data->all_eat = 0;
	data->one_died = 0;
	pthread_mutex_init (&data->msg, NULL);
	pthread_mutex_init (&data->death, NULL);
	forks (data);
	philos (data);
}

int	forks(t_data *data)
{
	int	i;

	i = 0;
	data->forks = malloc(sizeof(pthread_mutex_t) * data->philo);
	if (!data->forks)
	{
		write (2, "Error\nCatallar Icin Bellek Ayrilamadi\n", 38);
		return (0);
	}
	while (i < data->philo)
	{
		if (pthread_mutex_init (&data->forks[i], NULL) != 0)
		{
			write (2, "Error\nFork Hatasi", 17);
			return (0);
		}
		i++;
	}
	return (1);
}

int	philos(t_data *data)
{
	int	i;

	i = -1;
	data->philos = malloc(sizeof(t_philo) * data->philo);
	if (!data->philos)
	{
		write (2, "Error\nPhilosopher Icin Bellek Ayrilamadi\n", 42);
		return (0);
	}
	while (++i <= data->philo)
	{
		data->philos[i].eat_count = 0;
		data->philos[i].data = data;
		data->philos[i].id = i + 1;
		data->philos[i].dead = 0;
		data->philos[i].l_fork = i + 1;
		data->philos[i].r_fork = i;
	}
	data->philos[i].eat_count = 0;
	data->philos[i].data = data;
	data->philos[i].id = i + 1;
	data->philos[i].dead = 0;
	data->philos[i].l_fork = 0;
	data->philos[i].r_fork = i;
	return (1);
}

void	eat_count(t_data *data, int i)
{
	if (data->philos[i].eat_count == data->ph_m_eat)
	{
		data->philos[i].eat_count = 0;
		data->all_eat++;
	}
}
