/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozturk <onur_fb_5959@hotmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 14:24:56 by ehazir            #+#    #+#             */
/*   Updated: 2023/02/13 12:36:39 by oozturk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

t_list	*list_last_data(t_list *root, int index)
{
	t_list	*list;
	int		i;

	list = root;
	i = 0;
	while (i++ != index)
		list = list->next;
	return (list);
}

char	*list_data(t_list *root, int index)
{
	t_list	*iter;
	int		i;

	iter = root;
	i = 0;
	while (i++ != index)
		iter = iter->next;
	if (iter == NULL)
		return (NULL);
	return (iter->content);
}

void	ft_lstremove(t_list *list, int i)
{
	char *(tmp) = NULL;
	int (c) = 1;
	t_list *(tmplist) = NULL;
	char *(content);
	while (list_data(list, i))
	{
		content = list_data(list, i);
		tmplist = g_data->lst_env->next;
		while (tmplist)
		{
			tmp = (char *)tmplist->content;
			if (tmplist == NULL || content == NULL)
				break ;
			if (ft_strcmp2(tmp, content))
			{
				destroy_node(c);
				break ;
			}
			tmplist = tmplist->next;
			c++;
		}
		i++;
		c = 1;
	}
}

char	**list_to_char(t_list *list)
{
	t_list	*iter;
	char	**str;
	int		i;

	i = 0;
	iter = list;
	str = malloc(sizeof(char **) * ft_lstsize(list) + 1);
	while (iter != NULL)
	{
		str[i] = ft_strdup(iter->content);
		i++;
		iter = iter->next;
	}
	str[i] = NULL;
	return (str);
}
