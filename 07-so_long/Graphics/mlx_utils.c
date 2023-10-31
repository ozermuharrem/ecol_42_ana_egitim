/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozer <mozer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 10:54:46 by mozer             #+#    #+#             */
/*   Updated: 2022/10/09 16:46:34 by mozer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/so_long.h"

int	init_window(t_data *data)
{
	data->mlx = mlx_init();
	if (data->mlx == NULL)
		return (ERROR);
	data->win = mlx_new_window(data->mlx, data->win_width,
			data->win_height, "S0_LONG");
	if (data->win == NULL)
	{
		free(data->win);
		return (ERROR);
	}
	return (SUCCESS);
}

void	init_images(t_data *data)
{
	data->img.wall = mlx_xpm_file_to_image(data->mlx, IMG_WALL,
			&data->img.width, &data->img.height);
	data->img.ground = mlx_xpm_file_to_image(data->mlx, IMG_GROUND,
			&data->img.width, &data->img.height);
	data->img.player = mlx_xpm_file_to_image(data->mlx, IMG_PLAYER,
			&data->img.width, &data->img.height);
	data->img.exit = mlx_xpm_file_to_image(data->mlx, IMG_EXIT,
			&data->img.width, &data->img.height);
	data->img.coin = mlx_xpm_file_to_image(data->mlx, IMG_COIN,
			&data->img.width, &data->img.height);
}

void	loop_images(t_data data)
{
	mlx_loop_hook(data.mlx, &render, &data);
	mlx_hook(data.win, 2, 1L << 0, &handle_keypress, &data);
	mlx_hook(data.win, 17, 0L, &handle_btnx, &data);
	mlx_loop(data.mlx);
}

void	destroy_images(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img.wall);
	mlx_destroy_image(data->mlx, data->img.ground);
	mlx_destroy_image(data->mlx, data->img.player);
	mlx_destroy_image(data->mlx, data->img.exit);
	mlx_destroy_image(data->mlx, data->img.coin);
}
