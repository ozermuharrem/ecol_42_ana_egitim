/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozer <mozer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 13:56:31 by mozer             #+#    #+#             */
/*   Updated: 2022/02/10 20:41:41 by mozer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

int	ft_isalpha(char str)
{
	if (str >= 'a' && str <= 'z')
	{
		return (1);
	}
	else if (str >= 'Z' && str <= 'Z')
	{
		return (1);
	}
	else
		return (0);
}
