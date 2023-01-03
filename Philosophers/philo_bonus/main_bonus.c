/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozer <mozer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 21:17:47 by mozer             #+#    #+#             */
/*   Updated: 2022/12/24 23:11:54 by mozer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	main(int ac, char **av)
{
	t_data	*data;

	if (ac == 5 || ac == 6)
	{
		if (!args_check(ac, av))
		{
			write(2, "Error! Invalid Arg\n", 18);
			return (0);
		}
		data = malloc(sizeof(t_data));
		assigment(ac, av, data);
		s_fork(data);
	}
	else
		write(2, "Arg Error!\n", 11);
	return (0);
}
