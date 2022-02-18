/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozer <mozer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 21:55:37 by mozer             #+#    #+#             */
/*   Updated: 2022/02/18 11:55:06 by mozer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	int		i;
	int		j;
	size_t	length;

	length = ft_strlen(dst);
	if (size > 0 && size > length)
	{
		i = length;
		j = 0;
		while (src[j] && i < (int)size - 1)
		{
			dst[i] = src[j];
			i++;
			j++;
		}
		dst[i] = '\0';
		return (length + ft_strlen(src));
	}
	return (size + ft_strlen(src));
}

/*
#include <stdio.h>

int main()
{
	char hayat[] = "biriki";
	char dunya[] = "gecici";
	printf("%zu\n",ft_strlcat(hayat,dunya, 5)); 

//	int toplam = ft_strlen(hayat) + ft_strlen(dunya);


//	printf("%d",toplam);

	

	for(int s = 0; s < 6 ; s++)
	{
		printf("yalan dünya\n");
	}

	return (0);
}
*/
