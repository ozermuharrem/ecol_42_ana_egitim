/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozturk <onur_fb_5959@hotmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 14:24:56 by oozturk           #+#    #+#             */
/*   Updated: 2023/02/13 12:35:43 by oozturk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	arg_check(void)
{
	int	status;

	status = 0;
	if (g_data->arg == NULL)
		return (0);
	if (ft_strcmp(g_data->arg->content, ">") || \
		ft_strcmp(g_data->arg->content, ">>") || \
		ft_strcmp(g_data->arg->content, "<") || \
		ft_strcmp(g_data->arg->content, "<<"))
	{
		status = which_redirect(g_data->arg->content);
		return (status);
	}
	return (0);
}

void	status_decider(int status, int index)
{
	int (i) = index;
	int (redirect) = 0;
	t_list *(iter) = g_data->arg;
	if (ft_strcmp(list_data(g_data->arg, index), ">") || \
		ft_strcmp(list_data(g_data->arg, index), ">>") || \
		ft_strcmp(list_data(g_data->arg, index), "<") || \
		ft_strcmp(list_data(g_data->arg, index), "<<"))
	{
		while (!ft_strcmp(list_data(iter, index), "|"))
		{
			if (ft_strcmp(list_data(iter, index), ">") || \
				ft_strcmp(list_data(iter, index), ">>") || \
				ft_strcmp(list_data(iter, index), ">") || \
				ft_strcmp(list_data(iter, index), ">"))
			{
				redirect++;
				index++;
			}
			else
				index++;
		}
		redirect_decider(status, i, redirect - 1);
	}
}

void	pwd_update(int i, t_list *list)
{
	char	road[256];
	char	*pwd_old;
	char	*content;
	t_list	*tmp;

	pwd_old = ft_strjoin3(ft_strdup("OLDPWD="), check_env(ft_strdup("PWD")));
	tmp = list_last_data(list, i);
	free(tmp->content);
	tmp->content = pwd_old;
	ft_export(list);
	free(pwd_old);
	getcwd(road, sizeof(road));
	content = ft_strjoin("PWD=", road);
	tmp = list_last_data(list, i);
	tmp->content = content;
	ft_export(list);
}

void	command_echo(t_list *list, int i)
{
	if (list_data(list, i) == NULL)
		return ;
	while (ft_strcmp(list_data(list, i), "-n"))
	{
		if (list_data(list, i) != NULL)
			i++;
		if (list_data(list, i) == NULL)
			return ;
	}
	while (list_data(list, i) != NULL)
	{
		if (list_data(list, i + 1) == NULL)
			printf("%s", list_data(list, i));
		else
			printf("%s ", list_data(list, i));
		i++;
	}
}
