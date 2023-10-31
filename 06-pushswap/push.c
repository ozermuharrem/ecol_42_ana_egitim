/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozer <mozer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 12:21:01 by mozer             #+#    #+#             */
/*   Updated: 2022/09/09 12:26:24 by mozer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	pa(t_list **lsta, t_list **lstb)
{
	t_list	*temp;

	write(1, "pa\n", 3);
	temp = (*lstb)->next;
	ft_lstadd_front(lsta, *lstb);
	(*lstb) = temp;
}

void	pb(t_list **lsta, t_list **lstb)
{
	t_list	*temp;

	write(1, "pb\n", 3);
	temp = (*lsta)->next;
	ft_lstadd_front(lstb, *lsta);
	(*lsta) = temp;
}

void	rrr(t_list **lsta, t_list **lstb)
{
	write(1, "rrr\n", 4);
	rra(lsta);
	rrb(lstb);
}
