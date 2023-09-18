/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozturk <oozturk@student.42kocaeli.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 11:48:00 by oozturk           #+#    #+#             */
/*   Updated: 2023/05/02 14:19:33 by oozturk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_bsm_say(unsigned int b)
{
	int	i;

	i = 0;
	while (b >= 10)
	{
		b = b / 10;
		i++;
	}
	return (i + 1);
}

int	ft_uitoa(unsigned int u)
{
	int		len;
	char	*str;

	len = ft_bsm_say(u);
	str = (char *)malloc(sizeof(char) * len + 1);
	str[len] = '\0';
	while (len > 0)
	{
		str[len - 1] = u % 10 + 48;
		u = u / 10;
		len--;
	}
	len = print_arry(str);
	free (str);
	return (len);
}

int	print_arry(char *str)
{
	int	len;

	len = 0;
	if (!str)
		return (print_arry("(null)"));
	while (str[len])
		len += ft_putchar_vol2(str[len]);
	return (len);
}

int	ft_strchecker(va_list arg, int g)
{
	char		*a;
	int			len;

	len = 0;
	if (g == 'c')
		len = len + ft_putchar_vol2(va_arg(arg, int));
	if (g == 's')
		len = len + print_arry(va_arg(arg, char *));
	if (g == 'p')
		len = len + print_ptr(va_arg(arg, unsigned long));
	if (g == 'd' || g == 'i')
	{	
		a = ft_itoa(va_arg(arg, int));
		len = len + print_arry(a);
		free(a);
	}
	if (g == 'u')
		len = len + ft_uitoa(va_arg(arg, unsigned int));
	if (g == 'x' || g == 'X')
		len = len + print_hex(va_arg(arg, unsigned int), g);
	if (g == '%')
		len = len + ft_putchar_vol2('%');
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list	arg;
	int		len;
	int		i;

	va_start(arg, str);
	i = 0;
	len = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			len = len + ft_strchecker(arg, str[i]);
		}
		else
		{
			ft_putchar_vol2(str[i]);
			len++;
		}
		i++;
	}
	va_end(arg);
	return (len);
}
