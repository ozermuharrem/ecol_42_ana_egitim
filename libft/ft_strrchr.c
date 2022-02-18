/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozer <mozer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 22:02:22 by mozer             #+#    #+#             */
/*   Updated: 2022/02/18 14:42:22 by mozer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int			i;
	const char	*muh;

	muh = str;
	i = ft_strlen(str);
	str = (str + i);
	while (*str != *muh && c != *str)
		str--;
	if (c == *str)
		return ((char *)str);
	return (0);
}

/*
#include <stdio.h>

int main()
{
	char zalim[] = "oyunbozan";

	printf("%s",ft_strrchr(zalim, 'o'));

	return (0);
}
*/