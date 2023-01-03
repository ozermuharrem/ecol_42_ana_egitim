/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utulis.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozer <mozer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 12:04:17 by mozer             #+#    #+#             */
/*   Updated: 2022/12/21 10:12:56 by mozer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	death(t_data *data)
{
	int	i;

	i = 0;
	pthread_mutex_lock (&data->death);
	while (i < data->philo)
	{
		eat_count (data, i);
		if (data->philos[i].ph_eat_time != 0 && data->die_time \
		< (get_time() - data->philos[i].ph_eat_time))
		{
			if (data->philos->dead == 0)
			{
				message_dead (get_time(), "died", &data->philos[0]);
				data->philos->dead = 1;
				data->one_died = 1;
			}
			pthread_mutex_unlock (&data->death);
			return (1);
		}
		i++;
	}
	pthread_mutex_unlock(&data->death);
	return (0);
}

void	philo_eat(t_philo *p)
{
	if (!death_lock(p))
		return ;
	pthread_mutex_lock (&p->data->forks[p->l_fork]);
	pthread_mutex_lock (&p->data->forks[p->r_fork]);
	if (!death_lock(p))
		return ;
	message_fork (get_time(), "has take a fork", p);
	message_fork (get_time(), "has take a fork", p);
	pthread_mutex_lock (&p->data->death);
	p->eat_count++;
	p->ph_eat_time = get_time();
	pthread_mutex_unlock (&p->data->death);
	if (!death_lock(p))
		return ;
	message_eating (get_time(), "is eating", p);
	go_sleep (p->data->eat_time);
	pthread_mutex_unlock (&p->data->forks[p->l_fork]);
	pthread_mutex_unlock (&p->data->forks[p->r_fork]);
	return ;
}

void	philo_sleep(t_philo *p)
{
	if (!death_lock(p))
		return ;
	message_sleeping (get_time(), "is sleeping", p);
	go_sleep (p->data->sleap_time);
}

void	philo_think(t_philo *p)
{
	if (!death_lock(p))
		return ;
	message_thinkg (get_time(), "is thinking", p);
}
