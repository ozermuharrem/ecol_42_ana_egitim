/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sirala.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozer <mozer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 23:21:00 by mozer             #+#    #+#             */
/*   Updated: 2022/06/28 22:28:13 by mozer            ###   ########.fr       */
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

	listeninYeniBasi = yiginB;
	listeninYeniBasi -> data = yiginB -> data;
	listeninYeniBasi -> next = yiginA;

	printf("\npa\n");
	return (listeninYeniBasi);
}

t_list *pb(t_list *yiginA, t_list *yiginB)
{
	t_list *listeninYeniBasi;

	listeninYeniBasi = yiginA;
	listeninYeniBasi -> data = yiginA -> data;
	listeninYeniBasi -> next = yiginB;

	printf("\npb\n");
	return (listeninYeniBasi);
} 

t_list *rra(t_list *yiginA)
{
	t_list *start;
	t_list *end;
	int listLength;

	listLength = 0;

	while(yiginA != NULL)
		listLength++;

	printf("liste sayısı %d\n",listLength);

	end = list_last(yiginA);
	start -> data = end;

	while(--listLength)
	{
		start -> next = yiginA;
		yiginA = yiginA -> next;	
	}

	printf("\nrra\n");

	return (start);
	
}