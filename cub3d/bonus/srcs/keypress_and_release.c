/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress_and_release.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozcan <oozcan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 03:55:28 by oozcan            #+#    #+#             */
/*   Updated: 2023/04/11 03:55:28 by oozcan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_press(int key, t_cube *cube)
{
	if (key == ESC)
		exit (0);
	if (key == W)
		cube->w = true;
	if (key == S)
		cube->s = true;
	if (key == D)
		cube->d = true;
	if (key == A)
		cube->a = true;
	if (key == RA)
		cube->ra = true;
	if (key == LA)
		cube->la = true;
	if (key == M && cube->m == false)
		cube->m = true;
	else if (key == M && cube->m == true)
		cube->m = false;
	return (1);
}

int	key_release(int key, t_cube *cube)
{
	if (key == W)
		cube->w = false;
	if (key == S)
		cube->s = false;
	if (key == D)
		cube->d = false;
	if (key == A)
		cube->a = false;
	if (key == RA)
		cube->ra = false;
	if (key == LA)
		cube->la = false;
	return (1);
}
