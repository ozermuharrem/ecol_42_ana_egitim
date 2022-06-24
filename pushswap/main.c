/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozer <mozer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 00:05:11 by mozer             #+#    #+#             */
/*   Updated: 2022/06/24 03:42:17 by mozer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int main(int argc, char **argv)
{
	t_list *yiginA;
	t_list *yiginB;
	int i;
	int k;

	k = 1;
	i = 0;
	yiginA = malloc(sizeof(t_list));
	yiginA -> data = ft_atoi(argv[k]);
	yiginB = yiginA;

	 yiginA -> next = malloc(sizeof(t_list));
	 yiginA -> next -> data = ft_atoi(argv[2]);

	 yiginA -> next -> next = malloc(sizeof(t_list));
	 yiginA -> next -> next -> data = ft_atoi(argv[3]);

	 yiginA -> next -> next -> next = malloc(sizeof(t_list));
	 yiginA -> next -> next -> next -> data = ft_atoi(argv[4]);

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
	printf("%d\n",yiginB -> data);
	yiginB = yiginB -> next;
	i++;
	}

	yiginB = yiginA;

	sa(yiginA);
	yiginA = ra(yiginA);

	yiginB = yiginA;

	/* SIRALAMA SONRASINI YAZDIRMAK İÇİN */
	i = 0;


	while(i < argc - 1)
	{
	printf("%d\n",yiginB -> data);
	yiginB = yiginB -> next;
	i++;
	}
}
