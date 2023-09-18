/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_and_move2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozturk <oozturk@student.42kocaeli.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 13:53:14 by oozturk           #+#    #+#             */
/*   Updated: 2023/05/02 13:53:14 by oozturk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_wall(unsigned int x, unsigned int y, t_cube *cube)
{
	if (cube->map[y / CUBE_H][x / CUBE_W] == '1' || \
		cube->map[y / CUBE_H][x / CUBE_W] == 'G')
	{
		return (1);
	}
	return (0);
}

int	is_wall2(double x, double y, t_cube *cube)
{
	if ((int)y < cube->map_height && (int)x < cube->map_long)
		if (cube->map[(int)y][(int)x] == '1' || \
			cube->map[(int)y][(int)x] == 'G')
			return (1);
	return (0);
}
