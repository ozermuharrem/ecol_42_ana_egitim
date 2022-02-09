/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozer <mozer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 22:59:09 by mozer             #+#    #+#             */
/*   Updated: 2022/02/09 23:44:01 by mozer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>


int ft_strncmp(const char *s1, const char *s2, size_t n)
{
    size_t i;

    if (n == 0)
        return (0);

    i = 0;
    while (s1[i] == s2[i] && s1[i] != '\0')
    {
        if (i < (n - 1))
            i++;
        else
            return (0);
    }
    return ((unsigned char)(s1[i]) - (unsigned char)(s2[i])); 

} 

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

int main()
{
    char ds1[] = "freelenceeee";
    char ds2[] = "freekelimanagel";


    printf("ds1 len: %zu\n",ft_strlen(ds1));
    printf("ds2 len: %zu\n",ft_strlen(ds2));

   ft_strncmp(ds1,ds2,3);

    printf("%d",ft_strncmp(ds1,ds2,3));
    return(0);
}