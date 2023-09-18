/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozturk <oozturk@student.42kocaeli.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 11:31:20 by oozturk           #+#    #+#             */
/*   Updated: 2023/05/02 14:19:28 by oozturk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *w, int val, size_t n)
{
	unsigned char	*x;

	x = (unsigned char *)w;
	while (n-- > 0)
		*x++ = val;
	return (w);
}
