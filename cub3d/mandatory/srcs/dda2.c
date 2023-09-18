/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozturk <oozturk@student.42kocaeli.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 04:59:21 by oozturk           #+#    #+#             */
/*   Updated: 2023/05/02 14:01:33 by oozturk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	horizontal_while(t_cube *cube, double angle)
{
	while (cube->p_x + cube->hdx * cube->ray_dir_x >= 0 && cube->p_x + cube->hdx
		* cube->ray_dir_x <= (cube->map_s.map_width - 1)
		&& cube->p_y + cube->hdy * cube->ray_dir_y - 0.0001 >= 0
		&& cube->p_y + cube->hdy * cube->ray_dir_y - 0.0001 \
		<= cube->map_s.map_height)
	{
		cube->hdy = cube->hdy + 0.0001;
		if (is_wall2(cube->p_x + cube->hdx * cube->ray_dir_x,
				cube->p_y + cube->hdy * cube->ray_dir_y, cube))
		{
			cube->hit_h = true;
			cube->tmp2_x = cube->hdx * cube->ray_dir_x;
			cube->tmp2_y = cube->hdy * cube->ray_dir_y;
			cube->ray_x_h = cube->p_x + cube->tmp2_x;
			cube->ray_y_h = cube->p_y + cube->tmp2_y;
			break ;
		}
		cube->hdy = cube->hdy + 1.0 - 0.0001;
		cube->hdx = fabs(cube->hdy / tan(angle * (M_PI / 180)));
	}
}

double	horizontal(t_cube *cube, double angle)
{
	double	distance;

	distance = 10000;
	if (cube->ray_dir_y == -1)
		cube->hdy = cube->p_y - floor(cube->p_y);
	else
		cube->hdy = ceil(cube->p_y) - cube->p_y;
	cube->hdx = fabs(cube->hdy / tan(angle * (M_PI / 180)));
	cube->tmp2_x = cube->hdx * cube->ray_dir_x;
	cube->tmp2_y = cube->hdy * cube->ray_dir_x;
	horizontal_while(cube, angle);
	if (cube->hit_h == true)
		distance = sqrt((cube->tmp2_x * cube->tmp2_x) \
			+ (cube->tmp2_y * cube->tmp2_y));
	return (distance);
}

void	vertical_while(t_cube *cube, double angle)
{
	while (cube->p_x + cube->vdx * cube->ray_dir_x - 0.0001 >= 0
		&& cube->p_x + cube->vdx * cube->ray_dir_x - 0.0001 <= \
			(cube->map_s.map_width - 1)
		&& cube->p_y + cube->vdy * cube->ray_dir_y >= 0
		&& cube->p_y + cube->vdy * cube->ray_dir_y <= cube->map_s.map_height)
	{
		cube->vdx = cube->vdx + 0.0001;
		if (is_wall2(cube->p_x + (cube->vdx
					* cube->ray_dir_x), cube->p_y
				+ (cube->vdy * cube->ray_dir_y), cube))
		{
			cube->hit_v = true;
			cube->tmp_x = cube->vdx * cube->ray_dir_x;
			cube->tmp_y = cube->vdy * cube->ray_dir_y;
			cube->ray_x_v = cube->p_x + cube->tmp_x;
			cube->ray_y_v = cube->p_y + cube->tmp_y;
			break ;
		}
		cube->vdx = cube->vdx + 1.0 - 0.0001;
		cube->vdy = fabs(tan(angle * (M_PI / 180)) * cube->vdx);
	}
}

double	vertical(t_cube *cube, double angle)
{
	double	distance;

	distance = 10000;
	if (cube->ray_dir_x == -1)
		cube->vdx = cube->p_x - floor(cube->p_x);
	else
		cube->vdx = ceil(cube->p_x) - cube->p_x;
	cube->vdy = fabs(tan(angle * (M_PI / 180)) * cube->vdx);
	cube->tmp_x = cube->vdx * cube->ray_dir_x;
	cube->tmp_y = cube->vdy * cube->ray_dir_y;
	vertical_while(cube, angle);
	if (cube->hit_v == true)
		distance = sqrt((cube->tmp_x * cube->tmp_x) + \
			(cube->tmp_y * cube->tmp_y));
	return (distance);
}
