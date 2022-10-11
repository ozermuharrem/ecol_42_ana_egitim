/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozer <mozer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 10:56:57 by mozer             #+#    #+#             */
/*   Updated: 2022/10/05 10:56:58 by mozer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/so_long_bonus.h"

void	error_msg_bonus(char *str, t_data *data)
{
	ft_putstr_fd(RED, 2);
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(str, 2);
	if (data->map.map)
		ft_free_bonus(data);
	exit(1);
}

void	error_msg2_bonus(char *str)
{
	printf("\033[1;36m%s\n", str);
}
