/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_and_move3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozcan <oozcan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 03:55:26 by oozcan            #+#    #+#             */
/*   Updated: 2023/04/11 03:55:26 by oozcan           ###   ########.fr       */
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
