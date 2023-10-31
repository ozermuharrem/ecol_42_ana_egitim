/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_main_utulis.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozer <mozer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 00:05:11 by mozer             #+#    #+#             */
/*   Updated: 2022/09/14 20:19:52 by mozer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	is_number(char **str, int arg)
{
	int	i;
	int	j;
	int	k;

	i = 1;
	k = 0;
	while (i < arg)
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j - 1] == ' ' || str[i][j - 1] == '\t')
				k = 0;
			while ((str[i][j] == '-' || str[i][j] == '+') && ++j)
				k++;
			if (((str[i][j] != '-') && (str[i][j] < '0' || str[i][j] > '9')
							&& (str[i][j] != 32 && str[i][j] != '\t')) || k > 1)
				return (0);
			j++;
		}
		i++;
		k = 0;
	}
	return (1);
}

t_list	*to_int(char **str, int ac)
{
	t_list	*ret;
	int		size;

	ret = NULL;
	while (--ac >= 1)
	{
		size = ft_strlen(str[ac]);
		while (str[ac][--size] && size >= 0)
		{
			while ((str[ac][size] >= '0' && str[ac][size] <= '9')
				|| str[ac][size] == '-')
				size--;
			push(&ret, ft_atoi(&str[ac][size + 1]));
			while (str[ac][size] == ' ')
				size--;
			if (size == 0)
				push(&ret, ft_atoi(&str[ac][size]));
		}
	}
	return (ret);
}

void	push(t_list **stack, int veri)
{
	t_list	*tmp;

	tmp = (t_list *)malloc(sizeof(t_list));
	if (!tmp)
		return ;
	tmp -> data = veri;
	tmp -> next = NULL;
	if (!stack)
	{
		(*stack) = tmp;
		return ;
	}
	tmp -> next = (*stack);
	(*stack) = tmp;
}

void	free_stack(t_list **stack)
{
	t_list	*temp;

	while (*stack)
	{
		temp = (*stack)-> next;
		free(*stack);
		(*stack) = temp;
	}
}
