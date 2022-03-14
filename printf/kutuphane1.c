/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kutuphane1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozer <mozer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 15:54:11 by mozer             #+#    #+#             */
/*   Updated: 2022/03/08 15:54:11 by mozer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strdup(const char *str)
{
	char	*n;
	int		i;
	size_t	len;

	i = 0;
	len = ft_strlen(str);
	n = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	while (str[i] != '\0')
	{
		n[i] = str[i];
		i++;
	}
	n[i] = '\0';
	return (n);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size > 0)
	{
		while (src[i] && i < (size -1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = 0;
	}
	while (src[i])
		i++;
	return (i);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
