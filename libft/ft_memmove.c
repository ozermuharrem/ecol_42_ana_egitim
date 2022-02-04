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
	unsigned char *d;
	unsigned char *s;

	d = (unsigned char *)dst;
	s = (unsigned char *)src;

	while (len--)
		*d++ = *s++;
	return (dst);
}

int main()
{
	char kaynak_src[] = "veni,vidi,vici";
	char hedef_dst[] = "sonunudusunenkahramanolamaz";

	ft_memmove(hedef_dst, kaynak_src, 15);

	printf("past : %s",hedef_dst);
	printf("\n out put %s:",memmove(hedef_dst, kaynak_src,5));
}
