/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozer <mozer@42.tr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 16:42:50 by mozer             #+#    #+#             */
/*   Updated: 2022/02/04 17:08:58 by mozer            ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void *ft_memmove(void *dst, const void *src, size_t len)
{
	size_t i;

	if (!dst && !src)
		return (0);
	i = 0;
	if ((size_t)dst - (size_t)src < len)
		{
			i = len - 1;
			while (i < len)
			{
				((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
				i--;
			}
		}
	else
	{
		while ( i < len)
		{
			((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
			i++;
		}
	}
	return (dst);
}

int main()
{
	char kaynak_src[] = "veni,vidi,vici";
	char hedef_dst[] = "sonunudusunenkahramanolamaz";

	ft_memmove(hedef_dst, kaynak_src, 15);

	printf("past : %s\n",hedef_dst);
	printf("out put: %s",memmove(hedef_dst, kaynak_src,5));
}
