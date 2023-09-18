/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozturk <oozturk@student.42kocaeli.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 03:55:45 by oozturk           #+#    #+#             */
/*   Updated: 2023/05/02 14:00:24 by oozturk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	fill_g(t_cube *cube)
{
	int (i) = 0;
	int (j) = 0;
	while (cube->map[i])
	{
		while (cube->map[i][j] != '\0')
		{
			if (cube->map[i][j] != '1' && cube->map[i][j] != '0' \
				&& cube->map[i][j] <= 32)
				cube->map[i][j] = 'G';
			j++;
		}
		j = 0;
		i++;
	}
}

void	fill_map_spaces(t_cube *cube)
{
	int		index;
	char	*new_str;

	int (i) = 0;
	while (cube->map[i])
	{
		if (ft_strlen(cube->map[i]) < cube->map_s.map_width)
		{
			new_str = malloc(sizeof(char) * cube->map_s.map_width + 100);
			index = ft_strlen(cube->map[i]);
			ft_strlcpy(new_str, cube->map[i], ft_strlen(cube->map[i]));
			index--;
			while (index < cube->map_long - 1)
				new_str[index++] = 'G';
			new_str[index] = '\0';
			free(cube->map[i]);
			cube->map[i] = new_str;
		}
		i++;
	}
	fill_g(cube);
}

void	find_map_size(t_cube *cube)
{
	int	len;

	int (i) = 0;
	int (longest) = 0;
	while (cube->map[i] != NULL)
	{
		len = ft_strlen(cube->map[i]);
		if (len > longest)
			longest = len;
		i++;
	}
	cube->map_height = i - 1;
	cube->map_long = longest;
	cube->map_s.map_width = (longest - 1) * CUBE_W;
	cube->win_height = i * (CUBE_H * WM);
	cube->win_width = (longest) * (CUBE_W * WM);
	cube->map_s.map_height = i * CUBE_H;
}

void	check_map_size(t_cube *cube)
{
	find_map_size(cube);
	fill_map_spaces(cube);
	if (!map_check(cube))
	{
		ft_putstr_fd("Map Error !\n", 2);
		exit (0);
	}
	cube->x = cube->player_x * CUBE_W;
	cube->y = cube->player_y * CUBE_H;
}
