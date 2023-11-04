/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozturk <onur_fb_5959@hotmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 11:07:39 by ehazir            #+#    #+#             */
/*   Updated: 2023/02/13 12:38:31 by oozturk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
Gönderilen değerde len kadar kısmında arama yapar.
İşlem başarılı olursa bulunduğu 'len' den itibaren döndürür.
*/
char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int	size;
	int	i;

	if (!*needle)
		return ((char *)haystack);
	size = ft_strlen(needle);
	while (*haystack && len > 0)
	{
		i = 0;
		while (*haystack && haystack[i] == needle[i] && len - i)
		{
			if (i + 1 == size)
				return ((char *)haystack);
			i++;
		}
		haystack++;
		len--;
	}
	return (0);
}

/*
#include <stdio.h>
#include <string.h>
int main()
{
    char str[] = "Ferdi TAYFUR";
    printf("%s", ft_strnstr(str, " ", 10));
    printf("\n%s", strnstr(str, " ", 10));
}
*/