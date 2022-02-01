/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozer <mozer@42.tr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 14:30:20 by mozer             #+#    #+#             */
/*   Updated: 2022/02/01 14:38:16 by mozer             ###   ########.tr      */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> 

int ft_isdigit(int c){

	if( c >= 0 && c <= 9){
		return 1;
	}

	return 0;

}

int main(){

	printf("%d", ft_isdigit('s'));

	return 0;

}


