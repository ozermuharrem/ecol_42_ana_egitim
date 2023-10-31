/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_init_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozer <mozer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 10:53:24 by mozer             #+#    #+#             */
/*   Updated: 2022/10/05 10:53:24 by mozer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/so_long.h"

void	f_init_player(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->map.map[i])
	{
		while (data->map.map[i][j])
		{
			if (data->map.map[i][j] == 'P')
			{
				data->p_i = i;
				data->p_j = j;
			}
			j++;
		}
		j = 0;
		i++;
	}
	new_norm(data);
}

void	new_norm(t_data *data)
{
	if (data->map.map[data->p_i][data->p_j - 1] == '1'
		&& data->map.map[data->p_i][data->p_j + 1] == '1'
		&& data->map.map[data->p_i - 1][data->p_j] == '1'
		&& data->map.map[data->p_i + 1][data->p_j] == '1')
		error_msg("Kapalı Yol P\n", data);
	c_e_check(data);
}

void	c_e_check(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < data->map.line_count && data->map.map[i][j] != '\0')
	{
		while (j <= data->map.line_len)
		{
			if (data->map.map[i][j] == 'C' || data->map.map[i][j] == 'E')
			{
				if (data->map.map[i][j - 1] == '1'
					&& data->map.map[i][j + 1] == '1'
					&& data->map.map[i - 1][j] == '1'
					&& data->map.map[i + 1][j] == '1')
					error_msg ("Kapalı Yol C veya E\n", data);
				j++;
			}
			else
				j++;
		}
		j = 0;
		i++;
	}
}
