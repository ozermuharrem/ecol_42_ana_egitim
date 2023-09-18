/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozturk <oozturk@student.42kocaeli.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 03:55:10 by oozturk           #+#    #+#             */
/*   Updated: 2023/05/02 14:01:31 by oozturk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_win(t_cube *cube)
{
	int	k;
	int	i;

	k = 0;
	while (k != cube->win_height)
	{
		i = -1;
		if (k < cube->win_height / 2)
		{
			while (i++ != cube->win_width)
				cube->win_addr[cube->win_width * k + i] = rgb_to_hex(0, \
					cube->c_color[0], cube->c_color[1], cube->c_color[2]);
		}
		else
		{
			while (++i != cube->win_width)
				cube->win_addr[cube->win_width * k + i] = rgb_to_hex(0, \
					cube->f_color[0], cube->f_color[1], cube->f_color[2]);
		}
		k++;
	}
}

void	draw_img(t_cube *cube)
{
	draw_trans_map(cube);
	draw_ray_and_3d(cube);
}
