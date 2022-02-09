/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozer <mozer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 00:04:02 by mozer             #+#    #+#             */
/*   Updated: 2022/02/10 00:17:25 by mozer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char *ft_strnstr(const char *haystack, const char *needle, size_t len)
{
    size_t h;
    size_t n;

    h = 0;
    if (needle[0] == '\0')
        return ((char *)haystack);
    while (haystack[h] != '\0')
	{
		n = 0;
		while (haystack[h + n] == needle[n] && (h + n) < len)
		{
			if (haystack[h + n] == '\0' && needle[n] == '\0')
				return ((char *)&haystack[h]);
			n++;
		}
		if (needle[n] == '\0')
			return ((char *)haystack + h);
		h++;
	}
	return (0);
} 

// bu nu anlamadım suan 

int main(){
    
    char *cp1 = "bilgisayar";
    char *cp2 = "sayar";

    printf("d",ft_strnstr(cp1,cp2,5));

    return (0);

}