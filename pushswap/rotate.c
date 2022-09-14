/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozer <mozer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 12:22:03 by mozer             #+#    #+#             */
/*   Updated: 2022/09/09 12:26:09 by mozer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ra(t_list **lsta)
{
	t_list	*listenin_sonu;
	t_list	*listenin_yeni_basi;

	listenin_yeni_basi = (*lsta)->next;
	write(1, "ra\n", 3);
	listenin_sonu = ft_lstlast(*lsta);
	listenin_sonu->next = *lsta;
	listenin_sonu->next->next = NULL;
	*lsta = listenin_yeni_basi;
}

void	rb(t_list **lstb)
{
	t_list	*listenin_sonu;
	t_list	*listenin_yeni_basi;

	listenin_yeni_basi = (*lstb)->next;
	write(1, "rb\n", 3);
	listenin_sonu = ft_lstlast(*lstb);
	listenin_sonu->next = *lstb;
	listenin_sonu->next->next = NULL;
	*lstb = listenin_yeni_basi;
}

void	rra(t_list **lsta)
{
	t_list	*end_lst;
	t_list	*temp;
	int		i;

	temp = *lsta;
	write(1, "rra\n", 4);
	i = ft_lstlast(*lsta)->data;
	while (temp->next->next)
		temp = temp->next;
	free(ft_lstlast(*lsta));
	temp->next = NULL;
	end_lst = malloc(sizeof(t_list));
	end_lst->data = i;
	end_lst->next = *lsta;
	*lsta = end_lst;
}

void	rrb(t_list **lstb)
{
	t_list	*end_lst;
	t_list	*temp;
	int		i;

	temp = *lstb;
	write(1, "rrb\n", 4);
	i = ft_lstlast(*lstb)->data;
	while (temp->next->next)
		temp = temp->next;
	free(ft_lstlast(*lstb));
	temp->next = NULL;
	end_lst = malloc(sizeof(t_list));
	end_lst->data = i;
	end_lst->next = *lstb;
	*lstb = end_lst;
}
