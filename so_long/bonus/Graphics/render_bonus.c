/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozer <mozer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 10:58:10 by mozer             #+#    #+#             */
/*   Updated: 2022/10/05 10:58:12 by mozer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/so_long_bonus.h"

void	map_char_bonus(t_data *data, int i, int j, int k)
{
	static int	l;

	if (data->map.map[i][j] == '1')
		mlx_put_image_to_window(data->mlx, data->win, data->img.wall,
			j * IMG_SIZE, i * IMG_SIZE);
	else if (data->map.map[i][j] == '0')
		mlx_put_image_to_window(data->mlx, data->win, data->img.ground,
			j * IMG_SIZE, i * IMG_SIZE);
	else if (data->map.map[i][j] == 'P')
		mlx_put_image_to_window(data->mlx, data->win, data->img.player,
			j * IMG_SIZE, i * IMG_SIZE);
	else if (data->map.map[i][j] == 'F')
	{
		mlx_put_image_to_window(data->mlx, data->win, data->img.foe,
			j * IMG_SIZE, i * IMG_SIZE);
		if (data->d > 30)
			foe(data, i, j);
		data->d++;
	}
	else if (data->map.map[i][j] == 'C' && !(l % 5))
		coin_sprite_bonus(data, i, j, k);
	if (data->map.map[i][j] == 'E')
		exit_sprite_bonus(data, i, j);
	l++;
}

void	display_counter_window(t_data *data)
{
	char	*steps_count;

	steps_count = ft_itoa(data->steps_count);
	mlx_string_put(data->mlx, data->win, 45, 20, 0x00FF0000, "Toplam Hareket:");
	mlx_string_put(data->mlx, data->win, 180, 20, 0x0000FF00, steps_count);
	if (steps_count)
		free(steps_count);
}

int	render_bonus(t_data *data)
{
	int			i;
	int			j;
	static int	k;

	i = 0;
	j = 0;
	while (data->map.map[i])
	{
		while (data->map.map[i][j] && data->map.map[i][j] != '\n')
		{
			map_char_bonus(data, i, j, k);
			j++;
			display_counter_window(data);
		}
		j = 0;
		i++;
	}
	k++;
	return (SUCCESS);
}
