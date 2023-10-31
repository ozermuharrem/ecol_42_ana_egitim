/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozer <mozer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 12:37:30 by mozer             #+#    #+#             */
/*   Updated: 2022/12/21 12:04:48 by mozer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc == 5 || argc == 6)
	{
		if (!init_args_check (argc, argv))
		{
			write (2, "Error\nArgumanlar Hatali\n", 24);
		}
		init_args (argc, argv, &data);
		creat_threads (&data);
		ft_free (&data);
	}
	else
		write(2, "Error\nArguman Hatali\n", 22);
	return (0);
}
