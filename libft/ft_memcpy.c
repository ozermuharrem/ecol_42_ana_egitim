/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozer <mozer@42.tr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 15:40:49 by mozer             #+#    #+#             */
/*   Updated: 2022/02/04 17:00:02 by mozer            ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>


void *ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char *d;
	unsigned char *s;

	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	while (n--)
		*d++ = *s++;
	return (dst);
}

int main()
{
	char str[] = "sendesevamasevilme&askacisicekbegibi";
	char dest[40];

	ft_memcpy(dest, str, 7);
	printf(" %s",dest);
}



