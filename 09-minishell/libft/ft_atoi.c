/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozturk <onur_fb_5959@hotmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 17:24:07 by oozturk           #+#    #+#             */
/*   Updated: 2023/02/13 12:39:24 by oozturk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

static	int	ft_isspace(int c)
{
	if (c == ' ' || c == '\r' || c == '\f' || c == '\v'
		|| c == '\n' || c == '\t')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int		sign;
	long	res;

	res = 0;
	sign = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (ft_isdigit(*str))
	{
		res = (res * 10) + (*str - '0');
		str++;
	}
	res = res * sign;
	if (res >= -2147483648 && res <= 2147483647)
		return (res);
	if (sign == -1)
		return (0);
	return (-1);
}

/*
#include <stdio.h>
int main()
{
	char *str;

	str = "\n  -123";
	printf("%d", ft_atoi(str));
}
*/