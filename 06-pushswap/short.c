/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozer <mozer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 21:27:02 by mozer             #+#    #+#             */
/*   Updated: 2022/09/09 20:21:03 by mozer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	three_sort(t_list **stack)
{
	if (big_index(*stack) == 0 && (min_index(*stack) == 2)
		&& ft_lstsize(*stack) != 2)
	{
		sa(*stack);
		rra(stack);
	}
	else if (big_index(*stack) == 0 && ft_lstsize(*stack) == 2)
		sa(*stack);
	else if (big_index(*stack) == 0 && is_sorted((*stack)->next))
		ra(stack);
	else if (big_index(*stack) == 1 && min_index(*stack) == 0)
	{
		rra(stack);
		sa(*stack);
	}
	else if (min_index(*stack) == 2 && big_index(*stack) == 1)
		rra(stack);
	else
		sa(*stack);
}

void	give_back(t_list **stack_a, t_list **stack_b)
{
	int	size;
	int	index;

	while (*stack_b != NULL)
	{
		size = ft_lstsize(*stack_b);
		index = big_index(*stack_b);
		if (index == 1)
			sb(*stack_b);
		else if (index <= size / 2 && index != 0)
			rb(stack_b);
		else if (index >= size / 2 && index != 0)
			rrb(stack_b);
		else
			pa(stack_a, stack_b);
	}
}

void	five_sort(t_list **stack, t_list **stack_b)
{
	int	size;
	int	index;
	int	i;

	i = 0;
	size = ft_lstsize(*stack);
	while (ft_lstsize(*stack) > 3)
	{
		index = min_index(*stack);
		if (index >= ft_lstsize(*stack) / 2 && index != 0)
			rra(stack);
		else if (index <= ft_lstsize(*stack) / 2 && index != 0)
			ra(stack);
		else
			pb(stack, stack_b);
	}
	if (ft_lstsize(*stack) <= 3 && !is_sorted(*stack))
		three_sort(stack);
	while (i <= (size - ft_lstsize(*stack)))
	{
		pa(stack, stack_b);
		i++;
	}
}

int	is_sorted(t_list *stack)
{
	while (stack->next != NULL)
	{
		if (stack->data < stack->next->data)
			stack = stack->next;
		else
			return (0);
	}
	return (1);
}
