/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozer <mozer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 23:45:26 by mozer             #+#    #+#             */
/*   Updated: 2022/02/09 23:58:55 by mozer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int ft_memcmp(const void *s1, const void *s2, size_t n)
{
    size_t i;

    i = 0;
    while (i < n)
    {
        if (((unsigned char *)s1)[i] != ((unsigned char *)s2)[i])
            return (((unsigned char *)s1)[i]- ((unsigned char *)s2)[i]);
        i++;
    }
    return (0);
}

int main(){
    char *ona = "soyle";
    char *kan = "damliyorgozumden";

    printf("%d",ft_memcmp(ona,kan,6));

    return (0);

}