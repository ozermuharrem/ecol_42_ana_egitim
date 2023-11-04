/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozturk <onur_fb_5959@hotmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 14:24:56 by oozturk           #+#    #+#             */
/*   Updated: 2023/02/13 12:35:02 by oozturk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	alpha_finder_declared(void)
{
	t_list	*iter;
	t_list	*arg;
	char	*str;

	char *(str2) = NULL;
	int (i) = 0;
	int (j) = 0;
	if (g_data->declare == NULL)
		return ;
	arg = g_data->declare->next;
	iter = g_data->declare;
	while (iter)
	{
		str = iter->content;
		j = babe_finder_declared(i, iter, str, str2);
		iter->index = j;
		iter = iter->next;
		arg = g_data->declare;
		i = 0;
		j = 0;
	}
}

void	alpha_finder(void)
{
	t_list	*iter;
	t_list	*arg;
	char	*str;

	char *(str2) = NULL;
	int (i) = 0;
	int (j) = 0;
	if (g_data->lst_env == NULL)
		return ;
	arg = g_data->lst_env->next;
	iter = g_data->lst_env;
	while (iter)
	{
		str = iter->content;
		j = babe_finder(i, iter, str, str2);
		iter->index = j;
		iter = iter->next;
		arg = g_data->lst_env;
		i = 0;
		j = 0;
	}
}

void	print_alpha2(void)
{
	t_list	*iter;

	int (i) = 0;
	if (g_data->declare == NULL)
		return ;
	iter = g_data->declare;
	while (iter != NULL)
	{
		while (iter && iter->index != i)
			iter = iter->next;
		if (iter == NULL)
			break ;
		if ((char *)iter->content)
			printf("declare -x %s\n", iter->content);
		i++;
		iter = g_data->declare;
		continue ;
	}
}

void	print_alpha(void)
{
	t_list	*iter;

	int (i) = 0;
	iter = g_data->lst_env;
	while (iter != NULL)
	{
		while (iter && iter->index != i)
			iter = iter->next;
		if (iter == NULL)
			break ;
		if ((char *)iter->content)
			printf("declare -x %s\n", iter->content);
		i++;
		iter = g_data->lst_env;
		continue ;
	}
	alpha_finder_declared();
	print_alpha2();
}

void	ft_export(t_list *list)
{
	char	*content;
	char	*content2;

	int (i) = 1;
	content = list_data(list, i);
	if (content != NULL)
		content2 = content;
	else
		content2 = NULL;
	if (content2 == NULL)
		print_alpha();
	exporter(content2, i, list);
	alpha_finder();
	g_data->exit_status = 0;
	return ;
}
