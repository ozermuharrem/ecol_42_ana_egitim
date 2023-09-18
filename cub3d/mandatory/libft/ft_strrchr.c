/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozturk <oozturk@student.42kocaeli.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 11:41:53 by oozturk           #+#    #+#             */
/*   Updated: 2023/05/02 14:20:15 by oozturk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int x)
{
	char	*last_pos;

	last_pos = (0);
	if (x > 127)
		return ((char *)s);
	while (*s)
	{
		if (*s == x)
			last_pos = (char *)s;
		++s;
	}
	if (last_pos)
		return (last_pos);
	if (x == '\0')
		return ((char *)s);
	return (0);
}
