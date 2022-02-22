/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozer <mozer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 21:35:36 by mozer             #+#    #+#             */
/*   Updated: 2022/02/22 23:15:32 by mozer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
 NUL ile sonlandırılan src dizesinden dst'ye -1 karaktere kadar kopyalar
 sonucu NUL ile sonlandırır.
*/
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t			a;
	size_t			b;
	unsigned char	*s;

	a = 0;
	b = 0;
	s = (unsigned char *)src;
	while (s[a] != '\0')
		a++;
	if (dstsize != 0)
	{
		while (s[b] != '\0' && b < dstsize - 1)
		{
			dst[b] = s[b];
			b++;
		}
		dst[b] = '\0';
	}
	return (a);
}
