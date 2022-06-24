/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozer <mozer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 20:31:29 by mozer             #+#    #+#             */
/*   Updated: 2022/06/24 01:52:45 by mozer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_list
{
	int data;
	struct s_list *next;
}t_list;

int	ft_atoi(const char *str);
int	ft_isdigit(int c);
static int	ft_isspace(int c);
void sirala(t_list *yiginA);
void sa(t_list *yiginA);
t_list *list_last(t_list *yiginA);
t_list *ra(t_list *yiginA);

#endif