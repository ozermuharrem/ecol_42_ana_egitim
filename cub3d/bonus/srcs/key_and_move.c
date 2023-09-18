/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_and_move.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozcan <oozcan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 03:55:19 by oozcan            #+#    #+#             */
/*   Updated: 2023/04/12 23:22:21 by oozcan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move(t_cube *cube)
{
	double (x) = cube->x;
	double (y) = cube->y;
	if (cube->w)
	{
		x += cos(cube->player_angle * (M_PI / 180.0));
		y += sin(cube->player_angle * (M_PI / 180.0) * -1);
		if (!is_wall((x + check_wx(cube)), (cube->y + check_wy(cube)), cube))
			cube->x = x;
		if (!is_wall((cube->x + check_wx(cube)), (y + check_wy(cube)), cube))
			cube->y = y;
	}
	if (cube->s)
	{
		x += cos(cube->player_angle * (M_PI / 180.0)) * -1;
		y += sin(cube->player_angle * (M_PI / 180.0));
		if (!is_wall((x + check_sx(cube)), (cube->y + check_sy(cube)), cube))
			cube->x = x;
		if (!is_wall((cube->x + check_sx(cube)), (y + check_sy(cube)), cube))
			cube->y = y;
	}
}

void	move2(t_cube *cube)
{
	double (x) = cube->x;
	double (y) = cube->y;
	if (cube->a)
	{
		x += sin(cube->player_angle * (M_PI / 180.0)) * -1;
		y += cos(cube->player_angle * (M_PI / 180.0)) * -1;
		if (!is_wall(x + check_ax(cube), cube->y + check_ay(cube), cube))
			cube->x = x;
		if (!is_wall(cube->x + check_ax(cube), y + check_ay(cube), cube))
			cube->y = y;
	}
	if (cube->d)
	{
		x += sin(cube->player_angle * (M_PI / 180.0));
		y += cos(cube->player_angle * (M_PI / 180.0));
		if (!is_wall(x + check_dx(cube), cube->y + check_dy(cube), cube))
			cube->x = x;
		if (!is_wall(cube->x + check_dx(cube), y + check_dy(cube), cube))
			cube->y = y;
	}
}

void	pov_angle(t_cube *cube)
{
	if (cube->ra)
	{
		cube->player_angle -= AN;
		while (cube->player_angle < 0)
			cube->player_angle += 360;
	}
	if (cube->la)
	{
		cube->player_angle += AN;
		while (cube->player_angle >= 360)
			cube->player_angle -= 360;
	}
}

void	handle_keypress(t_cube *cube)
{
	move(cube);
	move2(cube);
	pov_angle(cube);
}
