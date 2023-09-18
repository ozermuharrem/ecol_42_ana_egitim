/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_xy1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozturk <oozturk@student.42kocaeli.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 13:51:38 by oozturk           #+#    #+#             */
/*   Updated: 2023/05/02 13:51:38 by oozturk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	check_wy(t_cube *cube)
{
	if (cube->player_angle > 180)
		return (CUBE_H / 2.0);
	return (0);
}

double	check_wx(t_cube *cube)
{
	if (cube->player_angle < 90 || cube->player_angle > 270)
		return (CUBE_W / 2.0);
	return (0);
}

double	check_sy(t_cube *cube)
{
	if (cube->player_angle < 180 && cube->player_angle > 0)
		return (CUBE_H / 2.0);
	return (0);
}

double	check_sx(t_cube *cube)
{
	if (cube->player_angle < 90 || cube->player_angle > 270)
		return (0);
	if (cube->player_angle > 90 || cube->player_angle < 270)
		return (CUBE_H / 2.0);
	return (0);
}
