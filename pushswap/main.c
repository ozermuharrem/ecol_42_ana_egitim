/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozer <mozer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 00:05:11 by mozer             #+#    #+#             */
/*   Updated: 2022/07/02 00:13:34 by mozer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int main(int argc, char **argv)
{
	t_list *yiginA;
	t_list *yiginB = NULL;
	t_list *listStartA;
	//t_list *listStartB;
	int i;
	int k;

	k = 1;
	i = 0;
	yiginA = malloc(sizeof(t_list));
	yiginA -> data = atoi(argv[k]);
	yiginA -> next = NULL;
	listStartA = yiginA;

	/* ARGÜMANDAN GELEN VERİYİ LİSTEYE ATAMA İŞLEMİ*/

	 while(k < argc - 1)
	 {
		t_list	*new;
		new = malloc(sizeof(t_list));
		new -> data = atoi(argv[++k]);
		new -> next = NULL;
		list_last(yiginA) -> next = new;
	 }

	/* MEVCUT DURUMU YAZDIRMAK İÇİN */

	// while(i < argc - 1)
	// {
	// 	printf("%d ",listStartA -> data);
	// 	listStartA = listStartA -> next;
	// 	i++;
	// }
 
	//sb(yiginB);
	
	yiginB = pb(yiginA, yiginB);
	yiginB = pb(yiginA, yiginB);
	 
	printf("b1: %d\n", yiginB -> data);
	printf("b2: %d\n", yiginB -> next -> data);

	// /* SIRALAMA SONRASINI YAZDIRMAK İÇİN */
	
	i = 0;
	
	while(i < argc - 1)
	{
		printf("%d ",listStartA -> data);
		listStartA = listStartA -> next;
		i++;
	}
}
