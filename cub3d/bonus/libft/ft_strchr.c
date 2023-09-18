/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozturk <oozturk@student.42kocaeli.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 11:35:17 by oozturk           #+#    #+#             */
/*   Updated: 2023/05/02 14:19:47 by oozturk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int x)
{
	if (x > 127)
		return ((char *)s);
	while (*s)
	{
		if (*s == x)
			return ((char *)s);
		++s;
	}
	if (x == '\0')
		return ((char *)s);
	return (0);
}
