/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_sprites_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozer <mozer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 10:58:02 by mozer             #+#    #+#             */
/*   Updated: 2022/10/05 10:58:02 by mozer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/so_long_bonus.h"

void	coin_sprite_bonus(t_data *data, int i, int j, int k)
{
	if (!k % 4)
		mlx_put_image_to_window(data->mlx, data->win, data->img.coin1,
			j * IMG_SIZE, i * IMG_SIZE);
	else if (k % 4 == 1)
		mlx_put_image_to_window(data->mlx, data->win, data->img.coin2,
			j * IMG_SIZE, i * IMG_SIZE);
	else if (k % 4 == 2)
		mlx_put_image_to_window(data->mlx, data->win, data->img.coin3,
			j * IMG_SIZE, i * IMG_SIZE);
	else if (k % 4 == 3)
		mlx_put_image_to_window(data->mlx, data->win, data->img.coin4,
			j * IMG_SIZE, i * IMG_SIZE);
	else
		mlx_put_image_to_window(data->mlx, data->win, data->img.coin5,
			j * IMG_SIZE, i * IMG_SIZE);
}
