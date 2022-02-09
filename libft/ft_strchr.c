/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozer <mozer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 22:27:09 by mozer             #+#    #+#             */
/*   Updated: 2022/02/09 22:31:29 by mozer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char *ft_strchr(const char *s, int c)
{
    while (*s != '\0' && c != *s)
        s++;
    if (c == *s)
        return ((char *)s);
    return (0);
} 

int main()
{
    char dizi[] = "Elmalikek";

    printf("%s",ft_strchr(dizi, 'a'));

    return (0);
}