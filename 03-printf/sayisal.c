/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sayısal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozer <mozer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 15:54:51 by mozer             #+#    #+#             */
/*   Updated: 2022/03/08 15:54:51 by mozer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	hex_system(unsigned int n, char c)
{
	int				i;
	int				f;
	int				len;
	char			*a;
	unsigned int	j;

	if (c == 'x')
		a = ft_strdup("0123456789abcdef");
	else
		a = ft_strdup("0123456789ABCDEF");
	i = 1;
	j = n;
	while (j >= 16 && i++)
		j = j / 16;
	len = i;
	while (--i >= 0)
	{
		j = n;
		f = i;
		while (--f >= 0)
			j = j / 16;
		ekranayaz(a[j % 16]);
	}
	free(a);
	return (len);
}

int	ptr_(unsigned long n)
{
	int	i;

	i = 1;
	ekranayaz('0');
	ekranayaz('x');
	ptryaz(n);
	while (n >= 16)
	{
		n /= 16;
		i++;
	}
	return (i + 2);
}

int	ptryaz(unsigned long n)
{
	char	*a;

	a = ft_strdup("0123456789abcdef");
	if (n >= 16)
	{
		ptryaz(n / 16);
		ptryaz(n % 16);
	}
	else
		ekranayaz(a[n]);
	free(a);
	return (0);
}
