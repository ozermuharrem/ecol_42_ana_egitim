/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozer <mozer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 21:55:37 by mozer             #+#    #+#             */
/*   Updated: 2022/02/22 14:09:21 by mozer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	int		i;
	int		j;
	size_t	length;

	length = ft_strlen(dst);
	if (size > 0 && size > length)
	{
		i = length;
		j = 0;
		while (src[j] && i < (int)size - 1)
		{
			dst[i] = src[j];
			i++;
			j++;
		}
		dst[i] = '\0';
		return (length + ft_strlen(src));
	}
	return (size + ft_strlen(src));
}
