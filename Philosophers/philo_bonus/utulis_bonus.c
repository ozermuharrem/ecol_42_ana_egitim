/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utulis_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozer <mozer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 21:23:31 by mozer             #+#    #+#             */
/*   Updated: 2022/12/24 23:12:13 by mozer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	total_eating(t_data *data, t_philos *philo)
{
	sem_wait(philo->data->sem_eat);
	if (philo->total_eating == data->one_philo_eat && data->one_philo_eat > 0)
	{
		data->all_eat++;
		if (data->all_eat == data->philo)
		{
			philo->data->all_eaters = 1;
			sem_post(philo->data->sem_eat);
			return (1);
		}
		sem_post(philo->data->sem_eat);
		return (0);
	}
	sem_post(philo->data->sem_eat);
	return (0);
}

void	my_sleep(long long time)
{
	long long	now;

	now = get_time();
	while (get_time() - now < time)
		usleep(60);
}

void	messages(long long time, char *str, t_philos *philo)
{
	sem_wait(philo->data->sem_msg);
	if (philo->data->died == 0)
		printf("%lld %d %s\n", \
				time - philo->data->start_time, philo->id, str);
	sem_post(philo->data->sem_msg);
}

long	get_time(void)
{
	struct timeval	tv;
	long			time;

	gettimeofday(&tv, NULL);
	time = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	return (time);
}
