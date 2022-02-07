/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozer <mozer@42.tr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 21:35:36 by mozer             #+#    #+#             */
/*   Updated: 2022/02/07 21:49:40 by mozer            ###   ########.tr       */
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
		len ++;
	}
	return (len);
}
// yıkarıda ki fonksiyon libft.h oluşturulduktan sonra silinecek 

size_t ft_strlcpy(char *hedef, const char *kaynak, size_t hedefsayi)
{
	size_t kaynaksayi;
	size_t i;

	if(!hedef || !kaynak)
		return (0);
	kaynaksayi = ft_strlen(kaynak);
	i = 0;
	if(hedefsayi != 0)
	{
		while (kaynak[i] != '\0' && i < (hedefsayi - 1 ))
		{
			hedef[i] = kaynak[i];
			i ++;
		}
		hedef[i] = '\0';
	}
	return (kaynaksayi);
}


int main()
{
	char dst[] = "elma";
	char src[] = "armut";

	ft_strlcpy(dst, src, 4);
//	strlcpy(dst, src, 4);

	printf("%s",dst);

	return (0);
}

