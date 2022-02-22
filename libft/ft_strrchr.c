/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozer <mozer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 22:02:22 by mozer             #+#    #+#             */
/*   Updated: 2022/02/22 14:06:47 by mozer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int			i;
	const char	*muh;

	muh = str;
	i = ft_strlen(str);
	str = (str + i);
	while (*str != *muh && c != *str)
		str--;
	if (c == *str)
		return ((char *)str);
	return (0);
}
