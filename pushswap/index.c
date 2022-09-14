/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozer <mozer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 11:42:39 by mozer             #+#    #+#             */
/*   Updated: 2022/09/09 12:07:14 by mozer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	min_index(t_list *stack)
{
	int		i;
	int		data;
	t_list	*temp;

	temp = stack;
	data = temp->data;
	i = 0;
	while (stack != NULL)
	{
		if (data <= stack->data && stack != NULL)
			stack = stack->next;
		else
		{
			temp = temp->next;
			data = temp->data;
			i++;
		}
	}
	return (i);
}

int	min(t_list *stack)
{
	int		data;
	t_list	*temp;

	temp = stack;
	data = temp->data;
	while (stack != NULL)
	{
		if (data <= stack->data && stack != NULL)
			stack = stack->next;
		else
		{
			temp = temp->next;
			data = temp->data;
		}
	}
	return (data);
}

int	big_index(t_list *stack)
{
	int		i;
	int		data;
	t_list	*temp;

	temp = stack;
	data = temp->data;
	i = 0;
	while (stack != NULL)
	{
		if (data >= stack->data && stack != NULL)
			stack = stack->next;
		else
		{
			temp = temp->next;
			data = temp->data;
			i++;
		}
	}
	return (i);
}

int	find_index(t_list *stack, int veri)
{
	int		first;
	int		last;
	int		j;
	int		size;

	first = 0;
	size = ft_lstsize(stack);
	while (stack && veri <= stack->data)
	{
		stack = stack->next;
		first++;
	}
	j = first;
	while (stack)
	{
		if (veri > stack->data)
			last = j;
		stack = stack->next;
		j++;
	}
	if (first > (size - last))
		return (last);
	return (first);
}

int	ctrl_dizi(int *dizi, int min, int boyut)
{
	int	i;

	i = -1;
	while (++i < boyut)
		if (dizi[i] == min)
			return (0);
	return (1);
}
