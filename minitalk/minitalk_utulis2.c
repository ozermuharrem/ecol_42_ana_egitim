/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_utulis2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozer <mozer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 13:56:40 by mozer             #+#    #+#             */
/*   Updated: 2022/05/20 21:27:33 by mozer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(const char *str)
{
	int				i;
	int				j;
	unsigned int	res;

	i = 0;
	j = 1;
	res = 0;
	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			j = -j;
		i++;
	}
	while (str[i] > 47 && str[i] < 58)
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res * j);
}

static char	*set_str(int n, int *bas) //19008
{
	char	*str;

	*bas = 1;
	if (n < 0) // fales
	{
		n *= -1;
		(*bas)++;
	}
	while (n >= 10) // true
	{
		n /= 10; // 19008 / 10 = 1900 
		(*bas)++; // 2 
	}
	str = (char *)malloc(sizeof(char) * (*bas + 1)); // str ye bellekte yer ayrıldı
	if (!str) // str boş ise Null dön boş değil yer ayrıldı
		return (NULL);
	str[0] = '-'; // 0.indix e - atandı
	str[(*bas)] = '\0';// str 2.indexsine \0 atandı
	return (str); // -\0 döndü
}

char	*ft_itoa(int n) // 19008
{
	char	*str;
	int		bas;

	if (n == -2147483648) // false
		return (ft_strdup("-2147483648"));
	str = set_str(n, &bas); // -\0
	if (n < 0) // false
		n *= -1;
	if (!str) // FALSE
		return (NULL);
	while (n >= 10) // TRUE
	{
		str[--bas] = n % 10 + '0';
		n = n / 10;
	}
	str[--bas] = n % 10 + '0';
	return (str);
}

char	*ft_strjoin(char *s1, char const s2)
{
	size_t	i;
	size_t	j;
	char	*s3;

	j = 0;
	i = 0;
	if (!s1 || !s2)
		return (NULL);
	s3 = (char *)malloc(sizeof(*s1) * (ft_strlen(s1) + 2));
	if (!s3)
		return (NULL);
	while (s1[i] != 0)
	{
		s3[j++] = s1[i];
		i++;
	}
	s3[j++] = s2;
	s3[j] = 0;
	return (s3);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		ft_putchar_fd('-', fd);
		ft_putchar_fd('2', fd);
		ft_putnbr_fd(147483648, fd);
	}
	else if (n < 0)
	{
		ft_putchar_fd('-', fd);
		ft_putnbr_fd(-n, fd);
	}
	else if (n < 10)
		ft_putchar_fd(n + '0', fd);
	else
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
}
