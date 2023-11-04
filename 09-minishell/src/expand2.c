/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozturk <onur_fb_5959@hotmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 14:24:56 by ehazir            #+#    #+#             */
/*   Updated: 2023/02/13 12:36:22 by oozturk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	expand2(int index)
{
	int (i) = 0;
	size_t (j) = 0;
	char *(tmp) = ft_calloc(10000, sizeof(char));
	char *(content) = list_data(g_data->arg, index);
	while (content[i])
	{
		if (content[i] == '$')
		{
			tmp = ft_strjoin3(tmp, usd_sign(ft_strdup(content), ++i));
			while (content[i] != 32 && content[i] != '$' && content[i] != '\0')
				i++;
			while (j < ft_strlen(tmp))
				++j;
		}
		if (content[i] == '$')
			continue ;
		tmp[j] = content[i];
		j++;
		i++;
	}
	tmp[j] = '\0';
	list_last_data(g_data->arg, index)->content = ft_strdup(tmp);
	free(content);
	free(tmp);
}
