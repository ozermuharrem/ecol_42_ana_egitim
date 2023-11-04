/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usd_sign2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozturk <onur_fb_5959@hotmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 14:24:56 by ehazir            #+#    #+#             */
/*   Updated: 2023/02/13 12:37:15 by oozturk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

// env adını döndürür
char	*env_name(char *str)
{
	int		i;
	char	*name;

	i = 0;
	while (str[i] != '=')
		i++;
	name = malloc((sizeof(char *) * i) + 1);
	i = 0;
	while (str[i] != '=')
	{
		name[i] = str[i];
		i++;
	}
	name[i] = '\0';
	return (name);
}
