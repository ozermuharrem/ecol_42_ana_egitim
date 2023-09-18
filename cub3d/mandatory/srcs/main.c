/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozturk <oozturk@student.42kocaeli.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 14:40:43 by oozturk           #+#    #+#             */
/*   Updated: 2023/05/02 14:00:51 by oozturk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_close(void)
{
	exit (0);
	return (0);
}

int	name_chck(char **av)
{
	int (i) = 0;
	while (check_char(&av[1][i], '.'))
		i++;
	if (!ft_strcmp(&av[1][i], "cub"))
		return (1);
	return (0);
}

int	main(int ac, char **av)
{
	t_cube	cube;

	cube.map_status = true;
	if (ac == 2 && name_chck(av) && map_init(av, &cube))
	{
		check_map_size(&cube);
		init(&cube);
		mlx_hook(cube.win, 3, 1L << 1, &key_release, &cube);
		mlx_hook(cube.win, 2, 1L << 0, &key_press, &cube);
		mlx_hook(cube.win, 17, (0L), ft_close, NULL);
		mlx_loop_hook(cube.mlx, &render, &cube);
		mlx_loop(cube.mlx);
	}
	else
		write (2, "Error\n", 6);
}
