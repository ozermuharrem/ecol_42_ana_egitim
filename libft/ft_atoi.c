/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozer <mozer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 12:00:24 by mozer             #+#    #+#             */
/*   Updated: 2022/02/22 14:12:22 by mozer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(int c)
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

/*#include <stdio.h>
int main()
{
    char *str;
    str = "\n  -123cs644";
    printf("%d", ft_atoi(str));
} */