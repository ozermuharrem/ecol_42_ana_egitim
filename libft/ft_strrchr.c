/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozer <mozer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 22:02:22 by mozer             #+#    #+#             */
/*   Updated: 2022/02/09 22:26:10 by mozer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

size_t ft_strlen(const char *s)
{
    size_t len; 

    len = 0;

    while (s[len] != 0)
    {
        len ++;
    }
    return (len);
}


char *ft_strrchr(const char *str, int c)
{
    int i;
    const char *muh;

    muh = str;

    i = ft_strlen(str);
    str = (str + i);
    while (*str != *muh && c != *str)
        str--;
    if ( c == *str)
        return ((char *)str);
    return (0); 
}

int main()
{
    char arr[] = "Memleket";

 //   printf("%zu",ft_strlen(arr));
    printf("%s",ft_strrchr(arr, 'l'));
    return (0);
}

