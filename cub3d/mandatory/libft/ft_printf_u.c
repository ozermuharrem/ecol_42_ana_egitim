/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozturk <oozturk@student.42kocaeli.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 11:49:38 by oozturk           #+#    #+#             */
/*   Updated: 2023/05/02 14:19:29 by oozturk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putchar_vol2(char c)
{
	write(1, &c, 1);
	return (1);
}

int	print_hex(unsigned int n, char c)
{
	int				i;
	int				i1;
	int				len;
	char			*a;
	unsigned int	n1;

	if (c == 'X')
		a = ft_strdup("0123456789ABCDEF");
	else
		a = ft_strdup("0123456789abcdef");
	i = 1;
	n1 = n;
	while (n1 >= 16 && i++)
		n1 = n1 / 16;
	len = i;
	while (--i >= 0)
	{
		n1 = n;
		i1 = i;
		while (--i1 >= 0)
			n1 = n1 / 16;
		ft_putchar_vol2(a[n1 % 16]);
	}
	free(a);
	return (len);
}

int	printer_ptr(unsigned long n)
{
	char	*a;

	a = ft_strdup("0123456789abcdef");
	if (n >= 16)
	{
		printer_ptr(n / 16);
		printer_ptr(n % 16);
	}
	else
		ft_putchar_vol2(a[n]);
	free(a);
	return (0);
}

int	print_ptr(unsigned long n)
{
	int	i;

	i = 1;
	ft_putchar_vol2('0');
	ft_putchar_vol2('x');
	printer_ptr(n);
	while (n >= 16)
	{
		n /= 16;
		i++;
	}
	return (i + 2);
}
