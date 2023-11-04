/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd2.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozturk <onur_fb_5959@hotmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 14:24:56 by oozturk           #+#    #+#             */
/*   Updated: 2023/02/13 12:35:06 by oozturk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	babe_finder_declared(int i, t_list *iter, char *str, char *str2)
{
	int (j) = 0;
	while (iter != NULL)
	{
		if (i == 0)
			str2 = iter->content;
		if (ft_strcmp(str, str2) == 1)
		{
			iter = iter->next;
			continue ;
		}
		if (str[i] > str2[i])
			j++;
		else if (str[i] == str2[i])
		{
			i++;
			continue ;
		}
		iter = iter->next;
		i = 0;
	}
	return (j);
}

int	babe_finder(int i, t_list *iter, char *str, char *str2)
{
	int (j) = 0;
	while (iter != NULL)
	{
		if (i == 0)
			str2 = iter->content;
		if (ft_strcmp(str, str2) == 1)
		{
			iter = iter->next;
			continue ;
		}
		if (str[i] > str2[i])
			j++;
		else if (str[i] == str2[i])
		{
			i++;
			continue ;
		}
		iter = iter->next;
		i = 0;
	}
	return (j);
}

void	just_cd(int i, t_list *list)
{
	char	*str;
	char	*old_pwd;
	char	*content;
	t_list	*tmp;

	old_pwd = ft_strjoin3(ft_strdup("OLDPWD="), check_env(ft_strdup("PWD")));
	ft_lstadd_back(&list, ft_lstnew(old_pwd));
	ft_export(list);
	str = ft_strjoin(getenv("HOME"), "/");
	chdir(str);
	content = ft_strjoin("PWD=", str);
	tmp = list_last_data(list, i + 1);
	free(tmp->content);
	tmp->content = content;
	ft_export(list);
	free(str);
}

// ft_dstry_node31
void	destroy_node(int i)
{
	t_list	*cleaner;

	t_list *(tmp) = g_data->lst_env;
	t_list *(tmp2) = g_data->lst_env;
	while (i > 1 && tmp != NULL)
	{
		if (tmp->next != NULL)
			tmp = tmp->next;
		i--;
	}
	cleaner = tmp->next;
	free(cleaner->content);
	free(cleaner);
	if (tmp->next->next != NULL)
		tmp2 = tmp->next->next;
	else
		tmp2 = NULL;
	if (tmp2 != NULL)
		tmp->next = tmp2;
	else
		tmp->next = NULL;
}

// ft_dstry_node2
void	destroy2(t_list *iter, int c)
{
	t_list *(cleaner);
	t_list *(tmp) = iter;
	t_list *(tmp2) = iter;
	if (c == 0)
		iter = NULL;
	while (c > 1 && tmp != NULL)
	{
		if (tmp->next != NULL)
			tmp = tmp->next;
		c--;
	}
	cleaner = tmp->next;
	if (cleaner)
	{
		free(cleaner->content);
		free(cleaner);
	}
	if (tmp->next->next != NULL)
		tmp2 = tmp->next->next;
	else
		tmp2 = NULL;
	if (tmp2 != NULL)
		tmp->next = tmp2;
	else
		tmp->next = NULL;
}
