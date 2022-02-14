/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozer <mozer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 14:57:59 by mozer             #+#    #+#             */
/*   Updated: 2022/02/14 15:33:56 by mozer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

char    *ft_strdup(const char *s1)
{
    char *s2;

    if (!(s2 = (char *)malloc(ft_strlen(s1)+1)))
        return (0);
    ft_memcpy(s2, s1, ft_strlen(s1) + 1);
    return (s2);
}
/*
#include <stdio.h>

int main()
{
    char *arr = "Zararsiz";
    const char *arr2; 
    printf("arr in degeri: %s\n",arr);
    printf("arr2 nin degeri:%s\n",arr2);
    
    arr2 = ft_strdup(arr);

    printf("%s\n",arr);
    printf("arr2 nin yeni degeri : %s",arr2);


    return (0);
} */