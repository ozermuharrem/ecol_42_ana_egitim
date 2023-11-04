/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozturk <onur_fb_5959@hotmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 14:24:56 by ehazir            #+#    #+#             */
/*   Updated: 2023/02/13 12:37:05 by oozturk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	which_redirect(char *content)
{
	if (ft_strcmp(content, ">"))
		return (1);
	else if (ft_strcmp(content, ">>"))
		return (2);
	else if (ft_strcmp(content, "<"))
		return (3);
	else if (ft_strcmp(content, "<<"))
		return (4);
	return (0);
}

void	ft_dstry_node_for_red(t_list *iter, int c)
{
	t_list	*tmp;
	t_list	*tmp2;

	tmp = iter;
	tmp2 = iter;
	if (c == 0)
		iter = NULL;
	while (c > 1 && tmp != NULL)
	{
		if (tmp->next != NULL)
			tmp = tmp->next;
		c--;
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

int	redirect_cntr(void)
{
	t_list	*iter;

	int (redc) = 0;
	int (index) = 0;
	iter = g_data->arg;
	while (iter != NULL)
	{
		if (ft_strcmp(list_data(g_data->arg, index), ">") || \
			ft_strcmp(list_data(g_data->arg, index), ">>") || \
				ft_strcmp(list_data(g_data->arg, index), "<") || \
					ft_strcmp(list_data(g_data->arg, index), "<<"))
		{
			redc++;
			index++;
		}
		else
			index++;
		iter = iter->next;
	}
	return (redc - 1);
}
