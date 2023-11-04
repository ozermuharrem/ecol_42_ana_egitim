/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozturk <onur_fb_5959@hotmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 14:24:56 by ehazir            #+#    #+#             */
/*   Updated: 2023/02/13 12:37:18 by oozturk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	lstcmp(char *str)
{
	t_list	*temp;

	g_data->cmp = 1;
	temp = g_data->lst_env;
	temp = temp->next;
	while (temp != NULL)
	{
		if (ft_strcmp3(temp->content, str))
			return (0);
		temp = temp->next;
		g_data->cmp++;
	}
	return (1);
}

int	ft_strcmp3(char *asd, char *sda)
{
	int		i;

	i = 0;
	while (asd[i] != '\0')
	{
		if (asd[i] == '=' && sda[i] == '=')
			return (1);
		if (asd[i] == sda[i])
			i++;
		else
			return (0);
	}
	return (1);
}

int	ft_strcmp(char *dst, char *src)
{
	int		i;
	size_t	len;

	len = ft_strlen(src);
	i = 0;
	while (len)
	{
		if (dst[i] == src[i])
			i++;
		else
			return (0);
		len--;
	}
	if (dst[i] != '\0')
		return (0);
	return (1);
}
