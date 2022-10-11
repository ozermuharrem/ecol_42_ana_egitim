/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_msg_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozer <mozer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 10:57:24 by mozer             #+#    #+#             */
/*   Updated: 2022/10/05 10:57:24 by mozer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/so_long_bonus.h"

void	move_msg_bonus(t_data *data)
{
	ft_putstr_fd("\e[1;1H\e[2J", 1);
	ft_putstr_fd("\033[38;5;217m", 1);
	printf("Hareket Sayaci : %d\n", data->steps_count);
}
