/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozer <mozer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 15:16:47 by mozer             #+#    #+#             */
/*   Updated: 2022/12/23 10:14:48 by mozer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	creat_threads(t_data *data)
{
	int	i;

	i = 0;
	data->threads = malloc (sizeof(pthread_t) * data->philo);
	while (i < data->philo)
	{
		data->philos[i].start_time = get_time();
		pthread_create (&data->threads[i], NULL, &worker, &data->philos[i]);
		i++;
	}
	while (data->one_died == 0)
	{
		death(data);
		if (data->one_died == 1 || data->philo == 1 \
			|| data->all_eat == data->philo)
			break ;
	}
	i = 0;
	while (i < data->philo)
	{
		pthread_join(data->threads[i], NULL);
		i++;
	}
}

void	*worker(void *th)
{
	t_philo	*pth;

	pth = (t_philo *)th;
	if (pth->data->philo == 1)
		one_philo(th);
	if (pth->id % 2 == 0)
		go_sleep(pth->data->eat_time);
	while (pth->data->philo > 1)
	{
		if (!death_lock(th))
			return (NULL);
		philo_eat(th);
		if (!death_lock(th))
			return (NULL);
		philo_sleep (th);
		if (!death_lock(th))
			return (NULL);
		philo_think (th);
	}
	return (NULL);
}

void	one_philo(t_philo *pth)
{
	pthread_mutex_lock(&pth->data->forks[pth->l_fork]);
	message_fork(get_time(), "Has taken a fork", pth);
	go_sleep (pth->data->die_time);
	message_dead (get_time(), "Died", pth);
	pthread_mutex_unlock(&pth->data->forks[pth->l_fork]);
	return ;
}

void	go_sleep(int num)
{
	long long int	time;

	time = get_time();
	while (num > get_time() - time)
		usleep(60);
}

long long int	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}
