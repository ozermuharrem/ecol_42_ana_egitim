/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozer <mozer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 10:08:21 by mozer             #+#    #+#             */
/*   Updated: 2022/12/21 10:48:27 by mozer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	message_fork(int time, char *msg, t_philo *p)
{
	pthread_mutex_lock(&p->data->msg);
	time = get_time() - p->start_time;
	printf("\033[1;35m %d %d %s\n", time, p->id, msg);
	pthread_mutex_unlock(&p->data->msg);
}

void	message_thinkg(int time, char *msg, t_philo *p)
{
	pthread_mutex_lock(&p->data->msg);
	time = get_time() - p->start_time;
	printf("\033[1;34m %d %d %s\n", time, p->id, msg);
	pthread_mutex_unlock(&p->data->msg);
}

void	message_eating(int time, char *msg, t_philo *p)
{
	pthread_mutex_lock(&p->data->msg);
	time = get_time() - p->start_time;
	printf("\033[1;33m %d %d %s\n", time, p->id, msg);
	pthread_mutex_unlock(&p->data->msg);
}

void	message_sleeping(int time, char *msg, t_philo *p)
{
	pthread_mutex_lock(&p->data->msg);
	time = get_time() - p->start_time;
	printf("\033[1;32m %d %d %s\n", time, p->id, msg);
	pthread_mutex_unlock(&p->data->msg);
}

void	message_dead(int time, char *msg, t_philo *p)
{
	pthread_mutex_lock(&p->data->msg);
	time = get_time() - p->start_time;
	printf("\033[1;31m %d %d %s\n", time, p->id, msg);
	pthread_mutex_unlock(&p->data->msg);
}
