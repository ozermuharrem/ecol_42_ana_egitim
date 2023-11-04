/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozturk <onur_fb_5959@hotmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 14:24:56 by oozturk           #+#    #+#             */
/*   Updated: 2023/02/13 12:36:16 by oozturk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

// çift tırnak içi kontrol
char	*double_34_loop(char *content, char *tmp, char *usd, char *iter)
{
	int (i) = 0;
	int (j) = 0;
	while (content[i])
	{
		if (content[i] == 34)
			i++;
		if (content[i] == '$')
		{
			usd = usd_sign(ft_strdup(content), ++i);
			iter = usd;
			while (content[i] != 32 && content[i] != '$' && content[i] != '\0' \
					&& content[i] != 34 && content[i] != 39)
				i++;
			while (*usd)
				tmp[j++] = *(usd++);
			tmp[j] = '\0';
		}
		else
			tmp[j++] = content[i++];
	}
	if (iter != NULL)
		free(iter);
	free(content);
	return (tmp);
}

// çift tırnak içindekileri işler
void	double_34(int index)
{
	char	*content;
	char	*tmp;

	char *(usd) = NULL;
	char *(iter) = NULL;
	tmp = malloc(10000);
	ft_bzero(tmp, 10000);
	content = list_data(g_data->arg, index);
	tmp = double_34_loop(content, tmp, usd, iter);
	list_last_data(g_data->arg, index)->content = ft_strdup(tmp);
	free(tmp);
}

// tek tırnak içindekileri işler.
void	single_39(int index)
{
	char	*content;
	char	*tmp;

	int (i) = 0;
	int (j) = 0;
	tmp = malloc(10000);
	content = list_data(g_data->arg, index);
	while (content[i])
	{
		if (content[i] == 39)
			i++;
		tmp[j] = content[i];
		j++;
		i++;
	}
	list_last_data(g_data->arg, index)->content = ft_strdup(tmp);
	free(tmp);
	free(content);
}

// çift tırnak veya tek tırnak'ta dönülecek değer.
int	check_status(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == 39)
			return (39);
		else if (str[i] == 34)
			return (34);
		i++;
	}
	return (0);
}

// çift tırnak veya tek tırnak durumunda yapılacak işlemler
void	expand(void)
{
	t_list	*iter;
	char	*content;
	int		status;
	int		index;

	index = 0;
	iter = g_data->arg;
	while (iter != NULL)
	{
		content = ft_strdup(iter->content);
		status = check_status(content);
		if (status == 39)
			single_39(index);
		else if (status == 34)
			double_34(index);
		else
			expand2(index);
		iter = iter->next;
		index++;
		free(content);
	}
}
