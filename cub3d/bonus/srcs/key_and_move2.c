/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_and_move2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozcan <oozcan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 03:55:22 by oozcan            #+#    #+#             */
/*   Updated: 2023/04/11 03:55:22 by oozcan           ###   ########.fr       */
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
