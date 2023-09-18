/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozcan <oozcan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 03:55:14 by oozcan            #+#    #+#             */
/*   Updated: 2023/04/12 23:18:08 by oozcan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_draw_small_square(t_cube *cube, int w, int h, int color)
{
	int (temp) = 0;
	int (temp2) = 0;
	while (temp2 < CUBE_H)
	{
		while (temp < CUBE_W)
		{
			cube->map_s.addr[(h + temp2) * cube->map_s.map_width + \
				(temp + w)] = color;
			temp++;
		}
		temp = 0;
		temp2++;
	}
}

void	draw_minimap(t_cube *cube)
{
	int (i) = 0;
	int (j) = 0;
	while (cube->map[i])
	{
		while (cube->map[i][j])
		{
			if (cube->map[i][j] == '0')
				ft_draw_small_square(cube, j * CUBE_W, i * CUBE_H, \
					rgb_to_hex(0, 255, 255, 255));
			else if (cube->map[i][j] == '1')
				ft_draw_small_square(cube, j * CUBE_W, i * CUBE_H, \
					rgb_to_hex(0, 255, 0, 255));
			else
				ft_draw_small_square(cube, j * CUBE_W, i * CUBE_H, \
					rgb_to_hex(255, 0, 0, 0));
			j++;
		}
		i++;
		j = 0;
	}
}

void	draw_trans_map(t_cube *cube)
{
	int (i) = 0;
	int (j) = 0;
	while (cube->map[i])
	{
		while (cube->map[i][j])
		{
			ft_draw_small_square(cube, j * CUBE_W, i * CUBE_H, \
				rgb_to_hex(255, 0, 0, 0));
			j++;
		}
		i++;
		j = 0;
	}
}

void	draw_player(t_cube *cube)
{
	int (k) = 0;
	int (l) = 0;
	while (k < CUBE_H)
	{
		l = -1;
		while (++l < CUBE_W)
		{
			cube->map_s.addr[cube->map_s.map_width * (k + (int)cube->y) + \
				(int)cube->x + l] = rgb_to_hex(0, 0, 255, 255);
		}
		k++;
	}
}
