/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozcan <oozcan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 03:55:05 by oozcan            #+#    #+#             */
/*   Updated: 2023/04/11 03:55:05 by oozcan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	new_c3d_2(t_cube *cube, t_xpm xpm, double l_end, int raycount)
{
	int	color;

	int (l_begin) = 0;
	int (img_loc) = (xpm.width * (xpm.height / 2)) + cube->find_pixel;
	while (l_begin < l_end && l_begin <= (int)(cube->win_height / 2.0))
	{
		if (img_loc + xpm.width * (int)((double)l_begin
			* ((double)xpm.width / (double)(l_end * 2))) < 64 * 64)
			color = xpm.img.addr[img_loc + xpm.width * (int)((double)l_begin
					* ((double)xpm.width / (double)(l_end * 2)))];
		if (((cube->win_height / 2) * cube->win_width + raycount)
			+ (cube->win_width * l_begin) < cube->win_height * cube->win_width)
		cube->win_addr[((cube->win_height / 2) * cube->win_width + raycount)
				+ (cube->win_width * l_begin)] = color;
		if (img_loc - xpm.width * (int)
			((double)l_begin * ((double)xpm.width / (double)(l_end * 2))) >= 0)
			color = xpm.img.addr[img_loc - xpm.width * (int)
				((double)l_begin * ((double)xpm.width / (double)(l_end * 2)))];
		if (((cube->win_height / 2) * cube->win_width + raycount)
			- (cube->win_width * l_begin) >= 0)
		cube->win_addr[((cube->win_height / 2) * cube->win_width + raycount)
				- (cube->win_width * l_begin)] = color;
		l_begin++;
	}
}

void	new_c3d(t_cube *cube, double dist, int raycount, t_xpm xpm)
{
	double (l_end) = (((double)cube->win_height / 2.0) / dist) * (double)CUBE_H;
	dist = (dist * (double)CUBE_H * ((double)cube->win_height / 2.0)
			/ (double)cube->win_width);
	if (cube->hit_h)
		cube->find_pixel = (cube->ray_x - floor(cube->ray_x)) * xpm.width;
	else if (cube->hit_v)
		cube->find_pixel = (cube->ray_y - floor(cube->ray_y)) * xpm.width;
	new_c3d_2(cube, xpm, l_end, raycount);
}

void	ray(t_cube *cube, int i)
{
	if (cube->hit_h)
	{
		cube->ray_x = cube->ray_x_h;
		cube->ray_y = cube->ray_y_h;
		if (cube->ray_dir_y == 1)
			cube->xpm_number = 1;
		else
			cube->xpm_number = 0;
	}
	else if (cube->hit_v)
	{
		cube->ray_x = cube->ray_x_v;
		cube->ray_y = cube->ray_y_v;
		if (cube->ray_dir_x == 1)
			cube->xpm_number = 2;
		else
			cube->xpm_number = 3;
	}
	new_c3d(cube, cube->distance, i, cube->xpm[cube->xpm_number]);
}

void	distance(t_cube *cube, double angle)
{
	cube->hit_h = false;
	cube->hit_v = false;
	double (v_dis) = vertical(cube, angle);
	double (h_dis) = horizontal(cube, angle);
	if (v_dis < h_dis)
	{
		cube->distance = v_dis;
		cube->hit_h = false;
		cube->hit_v = true;
	}
	else
	{
		cube->distance = h_dis;
		cube->hit_v = false;
		cube->hit_h = true;
	}
}

void	ray_dda(t_cube *cube, double angle, int i)
{
	cube->p_x = cube->x / (double)CUBE_W;
	cube->p_y = cube->y / (double)CUBE_H;
	if (cos(angle * (M_PI / 180)) > 0)
		cube->ray_dir_x = 1.0;
	else
		cube->ray_dir_x = -1.0;
	if (sin(angle * (M_PI / 180)) > 0)
		cube->ray_dir_y = -1.0;
	else
		cube->ray_dir_y = 1.0;
	distance(cube, angle);
	ray(cube, i);
}
