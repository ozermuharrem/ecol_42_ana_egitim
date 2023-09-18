/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozturk <oozturk@student.42kocaeli.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 13:05:36 by oozturk           #+#    #+#             */
/*   Updated: 2023/05/02 14:19:02 by oozturk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(char *asd, char *sda)
{
	int		i;
	size_t	len;

	len = ft_strlen(sda);
	i = 0;
	while (len)
	{
		if (asd[i] == sda[i])
			i++;
		else
			return (1);
		len--;
	}
	if (asd[i] != '\0')
		return (1);
	return (0);
}

int	check_char(char *asd, char c)
{
	int	i;

	i = 0;
	while (asd[i] != c && asd[i] != '\0')
		i++;
	if (i == ft_strlen(asd) && asd[i] != c)
		return (0);
	else
		return (1);
	return (0);
}
