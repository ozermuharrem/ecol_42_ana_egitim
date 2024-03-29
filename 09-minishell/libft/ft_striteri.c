/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozturk <onur_fb_5959@hotmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 10:24:52 by ehazir            #+#    #+#             */
/*   Updated: 2023/02/13 12:38:21 by oozturk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Gönderilen stringi, *f ile başka fonksiyona gönderip işlem yaptırır.
*/

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		(*f)(i, &s[i]);
		i++;
	}
}

/*
void	upper(unsigned int i, char* d)
{
	int	a;
	a = 0;
	i = 0;
	if (*d)
	{
		d[a] = d[a] - 32;
	}
}
int	main()
{
	char test[] = "enes";
	ft_striteri(test,upper);
	printf("%s",test);
}
*/