/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sirala.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozer <mozer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 23:21:00 by mozer             #+#    #+#             */
/*   Updated: 2022/06/24 04:12:08 by mozer            ###   ########.fr       */
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

t_list *list_last(t_list *yiginA)
{
	while(yiginA -> next != NULL)
		yiginA = yiginA -> next;

	return (yiginA);
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


void sirala(t_list *yiginA)
{
	sa(yiginA);
	ra(yiginA);
}