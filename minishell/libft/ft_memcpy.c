/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozturk <onur_fb_5959@hotmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 11:32:37 by ehazir            #+#    #+#             */
/*   Updated: 2023/02/13 12:38:04 by oozturk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
src'yi dest'e n kadar kopyalar.
*/

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*d;
	char	*s;
	size_t	i;

	i = 0;
	d = (char *)dst;
	s = (char *)src;
	if (!d && !s)
		return (0);
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (d);
}

/*
int main(void)
{
    char str[] = "eglendiremediklerimizdenmisiniz";
    char dest[40];

    ft_memcpy(dest, str, 8);
    printf("O: %s\n", dest);
	printf("O: %s", memcpy(dest,str,8));
}
*/