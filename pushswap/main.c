/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozer <mozer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 00:05:11 by mozer             #+#    #+#             */
/*   Updated: 2022/09/14 20:31:10 by mozer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	push_b(t_list **stack_a, t_list **stack_b, int *dizi, int boyut)
{
	t_list	*temp;
	int		ort;
	int		index;
	int		minn;

	index = -1;
	while (++index < boyut)
	{
		temp = *stack_a;
		minn = 2147483647;
		while (temp)
		{
			if (minn > temp -> data
				&& ctrl_dizi(dizi, temp -> data, boyut))
				minn = temp -> data;
			temp = temp -> next;
		}
		dizi[index] = minn;
	}
	ort = dizi[boyut - 1];
	push_b2(stack_a, stack_b, ort);
}

void	push_b2(t_list **stack_a, t_list **stack_b, int ort)
{
	int	index;
	int	size;

	while (min(*stack_a) != ort)
	{
		size = ft_lstsize(*stack_a);
		index = find_index(*stack_a, ort);
		if (index <= size / 2 && index != 0)
			ra(stack_a);
		else if (index >= size / 2 && index != 0)
			rra(stack_a);
		else
			pb(stack_a, stack_b);
		if (min(*stack_a) == ort && !is_sorted(*stack_a) && size <= 5)
			five_sort(stack_a, stack_b);
	}
}

void	sort(t_list **stack_a)
{
	t_list	*stack_b;
	int		boyut;
	int		dizi[50];
	int		a;

	stack_b = NULL;
	if (is_sorted(*stack_a))
		return ;
	while (!is_sorted(*stack_a))
	{
		if (ft_lstsize(*stack_a) >= 40)
			boyut = 40;
		else
		{
			a = ft_lstsize(*stack_a);
			while (a--)
				pb(stack_a, &stack_b);
			break ;
		}
		push_b(stack_a, &stack_b, dizi, boyut);
	}
	if (stack_b)
		give_back(stack_a, &stack_b);
	free(stack_b);
}

void	push_swap(char **str, int len)
{
	t_list	*yigina;
	t_list	*yiginb;
	t_list	*temp;

	yiginb = NULL;
	yigina = to_int(str, len);
	is_uniq(yigina);
	if (ft_lstsize(yigina) <= 3 && !is_sorted(yigina))
		three_sort(&yigina);
	else if (ft_lstsize(yigina) <= 5 && !is_sorted(yigina))
		five_sort(&yigina, &yiginb);
	sort(&yigina);
	free_stack(&yigina);
	free_stack(&yiginb);
}

int	main(int argc, char **argv)
{
	if (!is_number(argv, argc))
	{
		write(1, "Error\n", 7);
		exit(1);
	}
	else if (argc > 1)
	{
		push_swap(argv, argc);
		exit(0);
	}
	return (0);
}
