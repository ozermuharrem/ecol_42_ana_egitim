/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozer <mozer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 21:11:38 by mozer             #+#    #+#             */
/*   Updated: 2022/12/24 23:12:00 by mozer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <signal.h>
# include <pthread.h>
# include <semaphore.h>
# include <sys/time.h>
# include <sys/wait.h>
# include <sys/stat.h>

typedef struct s_philos
{
	int				id;
	int				pid;
	int				total_eating;
	long long int	last_eat;
	pthread_t		dead_check;
	struct s_data	*data;
}	t_philos;

typedef struct s_data
{
	int				philo;
	int				die_time;
	int				eat_time;
	int				sleep_time;
	int				one_philo_eat;
	int				died;
	int				all_eat;
	int				all_eaters;
	long long int	start_time;
	t_philos		*philos;
	sem_t			*sem_msg;
	sem_t			*sem_forks;
	sem_t			*sem_eat;
	sem_t			*sem_death;
}	t_data;

//! CHECK_BONUS
int		args_check(int ac, char **av);
int		ft_atoi(char *str);
void	*dead_check(void *pth);
int		lock_check(t_philos *philo);

//! INIT_BONUS
void	assigment(int ac, char **av, t_data *data);
void	sem(t_data *data);
int		s_fork(t_data *data);
void	kill_all(t_data *data);

//! PROCESS_BONUS
void	worker(void *ptr);
void	one_philo(t_philos *philo);
void	eating(t_philos *philo);
void	sleeping(t_philos *philo);
void	thinking(t_philos *philo);

//! UTILS_BONUS
long	get_time(void);
void	messages(long long time, char *str, t_philos *philo);
void	my_sleep(long long time);
int		total_eating(t_data *data, t_philos *philo);

#endif