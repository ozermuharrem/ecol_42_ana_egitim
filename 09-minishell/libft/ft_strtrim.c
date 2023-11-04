/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozturk <onur_fb_5959@hotmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 11:06:47 by ehazir            #+#    #+#             */
/*   Updated: 2023/02/13 12:38:39 by oozturk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Stringin içinde gönderilen karakterleri atlar, kalan karakterleri verir.
*/

#include	"libft.h"

static int	setkontrol(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		i;
	int		len;
	int		a;

	i = 0;
	a = 0;
	if (!s1 || !set)
		return (NULL);
	len = ft_strlen(s1);
	while (s1[i] != '\0' && setkontrol(s1[i], set))
		i++;
	while (i < len && setkontrol(s1[len -1], set))
		len--;
	str = (char *)malloc(sizeof(char) * ((len - i) + 1));
	if (str == NULL)
		return (NULL);
	while (i < len)
		str[a++] = s1[i++];
	str[a] = '\0';
	return (str);
}

/*
int main()
{
	printf("%s\n", ft_strtrim("...yazilimfuryasi...", "."));
}
*/
