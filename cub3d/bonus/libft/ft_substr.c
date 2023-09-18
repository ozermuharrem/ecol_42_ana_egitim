/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozturk <oozturk@student.42kocaeli.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 11:43:18 by oozturk           #+#    #+#             */
/*   Updated: 2023/05/02 14:20:21 by oozturk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	a;
	char	*b;
	int		c;
	size_t	f;

	f = 0;
	c = ((size_t)start);
	if (s == 0)
		return (0);
	while (f < len && s[f + start] != '\0')
		f++;
	b = malloc((f + 1) * sizeof(char));
	if (!b)
		return (0);
	a = 0;
	while (a < len && c < ft_strlen(s))
	{
		b[a++] = s[c++];
	}
	b[a] = '\0';
	return (b);
}
