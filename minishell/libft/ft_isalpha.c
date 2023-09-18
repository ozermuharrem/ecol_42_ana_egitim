/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozturk <onur_fb_5959@hotmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 13:02:57 by ehazir            #+#    #+#             */
/*   Updated: 2023/02/13 12:37:35 by oozturk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int str)
{
	if ((str < 'A' || str > 'Z')
		&& (str < 'a' || str > 'z'))
		return (0);
	return (1);
}
