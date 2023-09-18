/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozturk <onur_fb_5959@hotmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 16:15:43 by ehazir            #+#    #+#             */
/*   Updated: 2023/02/13 12:38:23 by oozturk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
- Gönderilen değerlerin uzunluğunun toplamı kadar ve sizeof(char) karşılığı kadar
bellekte yer ayır.
- Gönderilen değerleri birleştirir ve döndürür.
*/

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*string;
	int		i;
	int		end_s1;

	if (!s1 || !s2)
		return (NULL);
	string = malloc(((ft_strlen(s1)) + (ft_strlen(s2)) + 1));
	if (string == NULL)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		string[i] = s1[i];
		i++;
	}
	end_s1 = i;
	i = 0;
	while (s2[i] != '\0')
	{
		string[end_s1 + i] = s2[i];
		i++;
	}
	string[end_s1 + i] = '\0';
	return (string);
}

/*
#include <stdio.h>
#include <string.h>
int main()
{
    char str[] = "Leyla";
    char str2[] = "& Mecnun";
    printf("%lu\n", sizeof(int) * 11 + 1);
    printf("%s\n", ft_strjoin(str, str2));
}
*/