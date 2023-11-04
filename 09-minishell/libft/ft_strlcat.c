/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozturk <onur_fb_5959@hotmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 16:39:22 by ehazir            #+#    #+#             */
/*   Updated: 2023/02/13 12:38:24 by oozturk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Src ve dstnin toplam uzunluğunu döndürür.
*/
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	size_l;

	size_l = 0;
	while (dst[size_l] != '\0' && size_l < dstsize)
		size_l++;
	i = size_l;
	while (src[size_l - i] && size_l + 1 < dstsize)
	{
		dst[size_l] = src[size_l - i];
		size_l++;
	}
	if (i < dstsize)
		dst[size_l] = '\0';
	return (i + ft_strlen(src));
}
/*
int main()
{
    const char src[] = "eglen";
    char dst[] = "aaaaa";
    
    printf("%lu\n", ft_strlcat(dst, src, 10));
   // printf("%s", dst);
    printf("\n%lu", strlcat(dst, src, 5));
}
*/