/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozer <mozer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 00:05:11 by mozer             #+#    #+#             */
/*   Updated: 2022/06/26 18:53:19 by mozer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int main(int argc, char **argv)
{
	t_list *yiginA;
	t_list *yiginB;
	int i;
	int k;
	int count;

	count = 0;
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


	 if(yiginB == NULL)
	 {
		 printf("yigin null olduğu için return 0");
	 	return (0);
	 }
	 else
		{
			printf("yigin Null olmadiği için buradayiz");
			while(yiginB != NULL)
			{
	 			yiginB = yiginB -> next;
	 			count++;
	 		}
		}

//	count = 3;
	printf("count %d\n",count);

	if(count <= 2)
	{
		printf("conunt %d olduğu için return 0",count);
		return (0);
	}
	else
	{
		printf("count %d olduğu için sa\n",count);
		sa(yiginA);
	}
	
	// yiginA = ra(yiginA);

	 yiginB = yiginA;

	// /* SIRALAMA SONRASINI YAZDIRMAK İÇİN */
	 i = 0;
	while(i < argc - 1)
	{
	printf("%d\n",yiginB -> data);
	yiginB = yiginB -> next;
	i++;
	}
}
