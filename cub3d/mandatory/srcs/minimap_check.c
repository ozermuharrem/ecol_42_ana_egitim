/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozturk <oozturk@student.42kocaeli.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 03:55:42 by oozturk           #+#    #+#             */
/*   Updated: 2023/05/02 14:00:20 by oozturk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	map_check_part1(t_cube *cube)
{
	int (i) = 0;
	int (j) = 0;
	while (cube->map[i])
	{
		while (cube->map[i][j])
		{
			if (i == 0 && cube->map[i][j] == '0')
				cube->map_status = false;
			if (j == 0 && cube->map[i][0] == '0')
				cube->map_status = false;
			if (i != 0 && cube->map[i - 1][j] == 'G' && cube->map[i][j] == '0')
				cube->map_status = false;
			if (i != 0 && cube->map[i + 1] != NULL \
				&& cube->map[i + 1][j] == 'G' && cube->map[i][j] == '0')
				cube->map_status = false;
			if ((cube->map[i][j + 1] == 'G' || cube->map[i][j + 1] == '\n' \
				|| cube->map[i][j + 1] == '\0') && cube->map[i][j] == '0')
				cube->map_status = false;
			if (cube->map[cube->map_height][j] == '0')
				cube->map_status = false;
			j++;
		}
		i++;
		j = 0;
	}
}

void	map_check_part2(t_cube *cube)
{
	int (i) = 0;
	int (j) = 0;
	while (cube->map[i])
	{
		while (cube->map[i][j])
		{
			if (i != 0 && cube->map[i][j] == '1' && cube->map[i - 1][j] == '0' \
				&& cube->map[i][j - 1] == '0' && cube->map[i - 1][j - 1] == '1')
				cube->map_status = false;
			if (i != 0 && cube->map[i][j] == '0' && cube->map[i - 1][j] == '1' \
				&& cube->map[i - 1][j - 1] == 'G')
				cube->map_status = false;
			if (i != 0 && cube->map[i][j] == '0' \
				&& cube->map[i - 1][j + 1] == 'G')
				cube->map_status = false;
			if (i != 0 && cube->map[i][j] == '0' &&
				(cube->map[i + 1][j - 1] == 'G'
					|| cube->map[i + 1][j + 1] == 'G')
					&& i <= cube->map_height)
				cube->map_status = false;
			j++;
		}
		i++;
		j = 0;
	}
}

void	map_check_part3(t_cube *cube)
{
	unsigned int (player) = 0;
	int (i) = 0;
	int (j) = 0;
	while (cube->map[i])
	{
		while (cube->map[i][j])
		{
			if (cube->map[i][j] == 'N' || cube->map[i][j] == 'E' || \
				cube->map[i][j] == 'W' || cube->map[i][j] == 'S')
				player++;
			else if (cube->map[i][j] != '0' && cube->map[i][j] != '1' && \
				cube->map[i][j] != 'G')
				cube->map_status = false;
			j++;
		}
		j = 0;
		i++;
	}
	if (player > 0)
		cube->map_status = false;
}

int	map_check(t_cube *cube)
{
	map_check_part1(cube);
	if (cube->map_status != false)
		map_check_part2(cube);
	if (cube->map_status != false)
		map_check_part3(cube);
	if (cube->map_status == false)
		return (0);
	return (1);
}
