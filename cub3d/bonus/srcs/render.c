/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozcan <oozcan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 03:55:48 by oozcan            #+#    #+#             */
/*   Updated: 2023/04/13 04:57:33 by oozcan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//0x_00_00_ff
unsigned long	rgb_to_hex(int transparent, int r, int g, int b)
{
	return ((transparent << 24) + (r << 16) + (g << 8) + (b));
}

int	render(t_cube *cube)
{
	handle_keypress(cube);
	draw_win(cube);
	draw_img(cube);
	mlx_put_image_to_window(cube->mlx, cube->win, cube->win_img_ptr, 0, 0);
	mlx_put_image_to_window(cube->mlx, cube->win, cube->map_s.img_ptr, 0, 0);
	return (1);
}
