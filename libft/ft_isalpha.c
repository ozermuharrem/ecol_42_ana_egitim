/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozer <mozer@42.tr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 13:56:31 by mozer             #+#    #+#             */
/*   Updated: 2022/02/01 13:58:16 by mozer             ###   ########.tr      */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int ft_isalpha(char str){
	
	if(str >= 'a' && str <= 'z'){
		return 1;
	}
	else if(str >= 'Z' && str <= 'Z'){
		return 1;
	}
	else
		return 0;

}

int main(){

	printf("string alphabeden ise 1  degilse 0 döner\n return degeri: %d",ft_isalpha('f'));


	return 0;
}

