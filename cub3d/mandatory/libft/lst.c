/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozturk <oozturk@student.42kocaeli.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 12:55:22 by oozturk           #+#    #+#             */
/*   Updated: 2023/05/02 14:20:46 by oozturk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	lstcmp2(t_list *iter, char *str)
{
	t_list	*temp;

	temp = iter;
	while (temp != NULL)
	{
		if (ft_strcmp(temp->content, str))
			return (0);
		temp = temp->next;
	}
	return (1);
}

void	ft_dstry_node(t_list *iter, int c)
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

t_list	*list_f_data(t_list *root, int index)
{
	t_list	*list;
	int		i;

	list = root;
	i = 0;
	while (i++ != index)
		list = list->next;
	return (list);
}
