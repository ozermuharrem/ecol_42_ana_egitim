/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_xy2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozcan <oozcan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 23:25:48 by oozcan            #+#    #+#             */
/*   Updated: 2023/04/12 23:26:08 by oozcan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	check_ax(t_cube *cube)
{
	if (cube->player_angle > 180 && cube->player_angle < 360)
	{
		return (CUBE_H / 2.0);
	}
	return (0);
}

double	check_ay(t_cube *cube)
{
	if (cube->player_angle < 90 || cube->player_angle > 270)
	{
		return (0);
	}
	return (CUBE_H / 2.0);
}

double	check_dx(t_cube *cube)
{
	if (cube->player_angle < 180)
	{
		return (CUBE_H / 2.0);
	}
	return (0);
}

double	check_dy(t_cube *cube)
{
	if (cube->player_angle > 90 && cube->player_angle < 270)
	{
		return (0);
	}
	return (CUBE_H / 2.0);
}
