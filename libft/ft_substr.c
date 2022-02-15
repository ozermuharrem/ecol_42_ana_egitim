/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozer <mozer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 10:13:22 by mozer             #+#    #+#             */
/*   Updated: 2022/02/15 10:33:02 by mozer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_substr(char const *s, unsigned int start, size_t len)
{
    char *new_str;
    size_t  i;
    size_t  j;

    if (!s || !(new_str = (char *)malloc(len + 1)))
        return (0);
    i = start;
    j = 0;
    while (i < ft_strlen(s) && j < len)
        new_str[j++] = s[i++];
    new_str[j] = '\0';
    return (new_str);
}
/*
#include <stdio.h>
int main()
{
    char *sub ="ayvalik";

    char *str = ft_substr(sub, 2, 1);

    printf("%s",str);
} 
*/