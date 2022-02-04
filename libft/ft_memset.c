/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozer <mozer@42.tr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 14:34:19 by mozer             #+#    #+#             */
/*   Updated: 2022/02/04 14:41:32 by mozer            ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>


void *ft_memset(void *str, int c, size_t len)
{
	unsigned char *string;

	string = (unsigned char*)str;
	while (len -- > 0)
		*(string++) = (unsigned char)c;
	return (str);
}

int main()
{

	char sehir[] = "Kocaeli";

	ft_memset(sehir, '&', 3);

	printf("%s",sehir);

	return 0;
}

