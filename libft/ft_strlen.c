/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozer <mozer@42.tr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:24:21 by mozer             #+#    #+#             */
/*   Updated: 2022/02/04 13:03:59 by mozer            ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */



#include <stdio.h>

/*    
 * size_t : bir nesnenin boyutunu tutan herhangi bir değişken yada argüman bildiriminde
 * önerilen yoldur.	
 *
 * GNU sisteminde { GNU özgür yazılım olan bir işletim sistemidir. GNU işletim sistemi
 * GNU paketlerinden ve üçüncü taraflarca yayımlanan özgür yazılımdan oluşur. GNU nun
 * geliştirilmesi, özgürlüğümüzü ihlal eden yazılımlar olmadan bir bilgisayarın kul-
 * lanılmasını mümkün kılmıştır. }
 *
 * GNU sisteminde size_t ya unsigned int yada unsigned long int türüne eşdeğerdir.
 * bu iki tür GNU sisteminde eş anlamlıdır ve bir çok kullanım amacına yönelik olarak
 * biri diğerinin yerine kullanılabilir. 
 */


size_t ft_strlen(const char *s)
{
	size_t len;

	len = 0;

	while (s[len] != 0)
	{
		len++;
	}
	return (len);
}

int main()
{
	char ad[] = "Muharrem";
//	char ad[3];

//	ft_strlen(ad);

	printf("%zu",ft_strlen(ad));

	return 0;
}

