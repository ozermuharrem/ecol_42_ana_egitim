/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozcan <oozcan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 14:40:43 by osarihan          #+#    #+#             */
/*   Updated: 2023/04/16 23:11:58 by oozcan           ###   ########.fr       */
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

int	mouse_a(int x, int y, t_cube *cube)
{
	(void)y;
	if (x > 123)
		cube->player_angle -= MS;
	if (x < 123)
		cube->player_angle += MS;
	mlx_mouse_move(cube->win, 123, 123);
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
		mlx_mouse_move(cube.win, 123, 123);
		mlx_mouse_hide(cube.win);
		mlx_hook(cube.win, 3, 1L << 1, &key_release, &cube);
		mlx_hook(cube.win, 2, 1L << 0, &key_press, &cube);
		mlx_hook(cube.win, 17, (0L), ft_close, NULL);
		mlx_hook(cube.win, 6, 0L, &mouse_a, &cube);
		mlx_loop_hook(cube.mlx, &render, &cube);
		mlx_loop(cube.mlx);
	}
	else
		write (2, "Error\n", 6);
}
