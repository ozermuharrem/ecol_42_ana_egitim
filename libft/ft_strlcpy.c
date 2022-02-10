/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozer <mozer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 21:35:36 by mozer             #+#    #+#             */
/*   Updated: 2022/02/10 21:14:51 by mozer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

size_t	ft_strlcpy(char *hedef, const char *kaynak, size_t hedefsayi)
{
	size_t	kaynaksayi;
	size_t	i;

	if (!hedef || !kaynak)
		return (0);
	kaynaksayi = ft_strlen(kaynak);
	i = 0;
	if (hedefsayi != 0)
	{
		while (kaynak[i] != '\0' && i < (hedefsayi - 1))
		{
			hedef[i] = kaynak[i];
			i ++;
		}
		hedef[i] = '\0';
	}
	return (kaynaksayi);
}
