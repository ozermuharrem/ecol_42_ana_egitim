/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozturk <onur_fb_5959@hotmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 11:32:11 by ehazir            #+#    #+#             */
/*   Updated: 2023/02/13 12:37:33 by oozturk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalnum(int str)
{
	if ((str >= 65 && str <= 90)
		|| (str >= 97 && str <= 122)
		|| (str >= 48 && str <= 57))
		return (str);
	return (0);
}
