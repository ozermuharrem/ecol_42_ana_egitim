/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ber_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozer <mozer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 10:56:40 by mozer             #+#    #+#             */
/*   Updated: 2022/10/05 10:56:42 by mozer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/so_long_bonus.h"

int	name_check_bonus(char *str)
{
	str = ft_strchr(str, '.');
	if (!str)
		return (FAILURE);
	if (ft_strnstr(str, ".ber", 4))
		return (SUCCESS);
	return (FAILURE);
}
