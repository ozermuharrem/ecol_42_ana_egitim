/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozer <mozer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 12:16:01 by mozer             #+#    #+#             */
/*   Updated: 2022/09/09 12:25:49 by mozer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	sa(t_list *lst)
{
	int	temp;

	write(1, "sa\n", 3);
	temp = (lst)->next->data;
	(lst)->next->data = (lst)->data;
	(lst)->data = temp;
}

void	sb(t_list *lst)
{
	int	temp;

	write(1, "sb\n", 3);
	temp = (lst)->next->data;
	(lst)->next->data = (lst)->data;
	(lst)->data = temp;
}

void	ss(t_list *lsta, t_list *lstb)
{
	write(1, "ss\n", 3);
	sa(lsta);
	sb(lstb);
}

void	rr(t_list **lsta, t_list **lstb)
{
	write(1, "rr\n", 3);
	ra(lsta);
	rb(lstb);
}
