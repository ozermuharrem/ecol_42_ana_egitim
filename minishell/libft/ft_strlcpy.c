/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozturk <onur_fb_5959@hotmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 15:21:05 by ehazir            #+#    #+#             */
/*   Updated: 2023/02/13 12:38:26 by oozturk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t			i;
	size_t			a;
	unsigned char	*s;

	i = 0;
	a = 0;
	s = (unsigned char *)src;
	while (s[a] != '\0')
		a++;
	if (dstsize != 0)
	{
		while (s[i] != '\0' && i < dstsize - 1)
		{
			dst[i] = s[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (a);
}

/*
int main()
{
    char src[] = "eglendiremediklerimizdenmisiniz";
    char dst[] = " ";
    
    printf("%zu\n", ft_strlcpy(dst, src, 5));
	printf("%zu", strlcpy(dst, src, 1));
}
*/