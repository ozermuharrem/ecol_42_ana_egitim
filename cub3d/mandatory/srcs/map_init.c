/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozturk <oozturk@student.42kocaeli.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 14:07:58 by oozturk           #+#    #+#             */
/*   Updated: 2023/05/02 14:00:47 by oozturk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	find_angle(int way, t_cube *cube)
{
	cube->map[(int)cube->player_y][(int)cube->player_x] = '0';
	if (!way)
		return (0);
	else
	{
		if (way == 'N')
			cube->player_angle = 90.0;
		if (way == 'S')
			cube->player_angle = 270.0;
		if (way == 'E')
			cube->player_angle = 0.0;
		if (way == 'W')
			cube->player_angle = 180.0;
	}
	return (1);
}

int	find_player(t_cube *cube)
{
	int (i) = 0;
	int (j) = 0;
	while (cube->map[i])
	{
		while (cube->map[i][j])
		{
			if (cube->map[i][j] == 'N' || cube->map[i][j] == 'E' || \
				cube->map[i][j] == 'W' || cube->map[i][j] == 'S')
			{
				cube->player_x = j;
				cube->player_y = i;
				return (cube->map[i][j]);
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

void	take_map(t_cube *cube)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (cube->map_file[i][0] != '1' && cube->map_file[i][0] != '0' && \
		cube->map_file[i][0] != 32)
		i++;
	cube->map = malloc(sizeof(char **) * 10000);
	cube->map[j] = cube->map_file[i];
	while (cube->map_file[i] != NULL)
	{
		cube->map[j] = ft_strdup(cube->map_file[i]);
		free(cube->map_file[i]);
		j++;
		i++;
	}
	cube->map[j] = ft_strdup("\n");
}

void	open_and_take(t_cube *cube, char **av)
{
	char	*str;

	int (i) = 0;
	int (fd) = open(av[1], O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("Map File Error !\n", 2);
		exit (1);
	}
	cube->map_file = malloc(sizeof(char **) * 10000);
	while (1)
	{
		str = get_next_line(fd);
		if (str != NULL)
			cube->map_file[i] = str;
		else
			break ;
		i++;
	}
}

int	map_init(char **av, t_cube *cube)
{
	open_and_take(cube, av);
	take_texture(cube);
	take_color(cube);
	take_map(cube);
	if (!find_angle(find_player(cube), cube))
	{
		ft_putstr_fd("Player Error !\n", 2);
		exit (0);
	}
	return (1);
}
