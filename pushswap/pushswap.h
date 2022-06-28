/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozer <mozer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 20:31:29 by mozer             #+#    #+#             */
/*   Updated: 2022/06/28 22:26:27 by mozer            ###   ########.fr       */
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

int	ft_isspace(int c);
int	ft_atoi(const char *str);
int	ft_isdigit(int c);
void sirala(t_list *yiginA);
void sa(t_list *yiginA);
void sb(t_list *yiginB);
t_list *list_last(t_list *yiginA);
t_list *ra(t_list *yiginA);
t_list *rb(t_list *yiginB);
t_list *pa(t_list *yiginA, t_list *yiginB);
t_list *pb(t_list *yiginA, t_list *yiginB);
t_list *rra(t_list *yiginA);

#endif