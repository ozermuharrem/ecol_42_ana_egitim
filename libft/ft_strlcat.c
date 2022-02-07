/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozer <mozer@42.tr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 21:55:37 by mozer             #+#    #+#             */
/*   Updated: 2022/02/07 23:23:50 by mozer            ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

size_t ft_strlen(const char *s)
{
	size_t len;

	len = 0;

	while(s[len] != 0)
	{
		len ++ ;
	}
	return (len);
}

size_t ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t c;
	size_t d;

	if (dstsize <= ft_strlen(dst))
		return (dstsize + ft_strlen(src));
	c = ft_strlen(dst);
	d = 0;

	while (src[d] != '\0' && c + 1 < dstsize)
	{
		dst[c] = src[d];
		c++;
		d++;
	}
	dst[c] = '\0';
	return (ft_strlen(dst) + ft_strlen(&src[d]));
}

int main()
{
	char hedef[] = "bombosguluslerin";
	char kaynak[] = "duseraklima";


	printf("hedef:%s\n",hedef);
	printf("kaynak:%s\n",kaynak);



//	ft_strlcat(bir,iki,5);
	strlcat(hedef,kaynak,9);

	printf("new hedef : %s\n",hedef);
	printf("new kaynak : %s",kaynak);

return (0);

}

