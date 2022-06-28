/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozer <mozer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 00:05:11 by mozer             #+#    #+#             */
/*   Updated: 2022/06/28 22:26:55 by mozer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int main(int argc, char **argv)
{
	t_list *yiginA;
	t_list *yiginB;
	t_list *listStartA;
	t_list *listStartB;
	int i;
	int k;

	k = 1;
	i = 0;
	yiginA = malloc(sizeof(t_list));
	yiginA -> data = ft_atoi(argv[k]);

	listStartA = yiginA;

	yiginA -> next = malloc(sizeof(t_list));
	yiginA -> next -> data = ft_atoi(argv[2]);

	yiginA -> next -> next = malloc(sizeof(t_list));
	yiginA -> next -> next -> data = ft_atoi(argv[3]);

	yiginA -> next -> next -> next = malloc(sizeof(t_list));
	yiginA -> next -> next -> next -> data = ft_atoi(argv[4]);
	
	yiginB = malloc(sizeof(t_list));
	yiginB -> data = 33;

	listStartB = yiginB;

	yiginB -> next = malloc(sizeof(t_list));
	yiginB -> next -> data = 26;

	yiginB -> next -> next = malloc(sizeof(t_list));
	yiginB -> next -> next -> data = 21;

	yiginB -> next -> next -> next = malloc(sizeof(t_list));
	yiginB -> next -> next -> next -> data = 4;

	/* ARGÜMANDAN GELEN VERİYİ LİSTEYE ATAMA İŞLEMİ*/

	//  while(k < argc)
	//  {
	//  	yiginA -> next = malloc(sizeof(t_list));
	//  	yiginA -> data = ft_atoi(argv[k]);
	// 	yiginA = yiginA -> next;
	// 	k++;
	//  }

	/* MEVCUT DURUMU YAZDIRMAK İÇİN */

	while(i < argc - 1)
	{
		printf("%d ",listStartA -> data);
		listStartA = listStartA -> next;
		i++;
	}

	listStartA = yiginA;
 
	//sb(yiginB);
	
	 yiginA = rra(yiginA);

	 listStartA = yiginA;

	// /* SIRALAMA SONRASINI YAZDIRMAK İÇİN */
	
	i = 0;
	
	while(i < argc - 1)
	{
		printf("%d ",listStartA -> data);
		listStartA = listStartA -> next;
		i++;
	}
}
