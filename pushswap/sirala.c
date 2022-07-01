/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sirala.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozer <mozer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 23:21:00 by mozer             #+#    #+#             */
/*   Updated: 2022/07/02 01:52:05 by mozer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void sa(t_list *yiginA)
{	
	int a = yiginA -> data;
	int b = yiginA -> next -> data;

	yiginA -> data = b;
	yiginA -> next -> data = a;
	printf("\nsa\n");
}

void sb(t_list *yiginB)
{
	int a = yiginB -> data;
	int b = yiginB -> next -> data;

	yiginB -> data = b;
	yiginB -> next -> data = a;
	printf("\nsb\n");
}

t_list *list_last(t_list *yigin)
{
	while(yigin -> next != NULL)
		yigin = yigin -> next;

	return (yigin);
}

t_list *ra(t_list *yiginA)
{
	t_list *listeninYeniBasi;
	t_list *listeninBasi;
	t_list *listeninSonu;

	listeninBasi = yiginA;
	listeninYeniBasi = yiginA -> next;
	listeninSonu = list_last(yiginA);

	listeninSonu -> next = yiginA;
	listeninBasi -> next = NULL;
	printf("\nra\n");
	return (listeninYeniBasi);
} 

t_list *rb(t_list *yiginB)
{
	t_list *listeninYeniBasi;
	t_list *listeninBasi;
	t_list *listeninSonu;

	listeninBasi = yiginB;
	listeninYeniBasi = yiginB -> next;
	listeninSonu = list_last(yiginB);

	listeninSonu -> next = yiginB;
	listeninBasi -> next = NULL;
	printf("\nrb\n");
	return (listeninYeniBasi);
}

t_list *pa(t_list *yiginA, t_list *yiginB)
{
	t_list *listeninYeniBasi;
	t_list	*new_element;

	new_element = malloc(sizeof(t_list));
	new_element -> data = yiginA -> data;
	if(!yiginB)
		yiginB = new_element;
	else
		new_element -> next = yiginB;
	listeninYeniBasi = yiginA -> next;
	free(yiginA);
	yiginA = listeninYeniBasi;
	// listeninYeniBasi = yiginB;
	// listeninYeniBasi -> data = yiginB -> data;
	// listeninYeniBasi -> next = yiginA;
	printf("\npa\n");
	return (yiginB);
}

t_list *pb(t_list *yiginA, t_list *yiginB)
{
	t_list *new;
	t_list *A_nin_ilk = yiginA;
	
	new = malloc(sizeof(t_list));
	new -> data = yiginA -> data;
	new -> next = NULL;

	if(!yiginB)
		yiginB = new;
	else
		new -> next = yiginB;
	yiginA = yiginA -> next;
	free(A_nin_ilk);
	printf("\npb\n");
	return (yiginA);
} 

t_list *rra(t_list *yiginA)
{
	t_list *end;
	t_list	*temp = yiginA;

	while(temp -> next -> next)
		temp = temp -> next;
	end = temp -> next;
	temp -> next -> next = yiginA;
	temp -> next = NULL;
	yiginA = end;
	printf("\nrra\n");
	return (end);
}
