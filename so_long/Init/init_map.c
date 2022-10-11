/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozer <mozer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 10:53:35 by mozer             #+#    #+#             */
/*   Updated: 2022/10/05 10:53:35 by mozer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/so_long.h"

void	init_map(t_data *data)
{
	data->i = 0;
	data->j = 0;
	data->map.count_p = 0;
	data->map.count_e = 0;
	data->map.count_c = 0;
	data->map.collected = 0;
	data->map.can_exit = 0;
	data->steps_count = 0;
	data->win_height = data->map.line_count * IMG_SIZE;
	data->win_width = (ft_strlen(data->map.map[0]) - 1) * IMG_SIZE;
	data->img.height = IMG_SIZE;
	data->img.width = IMG_SIZE;
}
