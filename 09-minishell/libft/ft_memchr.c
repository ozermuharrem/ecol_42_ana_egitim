/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozturk <onur_fb_5959@hotmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 14:05:59 by ehazir            #+#    #+#             */
/*   Updated: 2023/02/13 12:38:01 by oozturk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Bir karakter dizisi içinde verilen karakteri bulduğu yerden
itibaren geri döndürür.
*/
void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	size_t			i;
	int				k;

	str = (unsigned char *)s;
	i = 0;
	k = 0;
	if (n == i)
		return (NULL);
	while (i < n)
	{
		if (str[i] == (unsigned char)c)
			return (&str[i]);
		else
			k = 1;
		i++;
	}
	if (k == 1)
		return (0);
	else
		return (&str[i]);
}

/*
#include <stdio.h>
#include <string.h>
int main()
{
    const char *str = "armut";

    printf("%s", ft_memchr(str, 'm', 3));
    printf("\n%s", memchr(str, 'm', 3));
}
*/
