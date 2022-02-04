/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozer <mozer@42.tr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 15:15:51 by mozer             #+#    #+#             */
/*   Updated: 2022/02/04 15:39:31 by mozer            ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>

void *ft_memset(void *str, int c, size_t len)
{
	unsigned char *string;

	string = (unsigned char *)str;
	while ( len -- > 0)
		*(string++) = (unsigned char)c;
	return (str);
}


void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 'x', n);
}

int main()
{
	char ulke[]="Turkiye";

	ft_bzero(ulke,3);

	printf("%s", ulke);

}


