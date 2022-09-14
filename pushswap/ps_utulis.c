/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utulis.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozer <mozer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 22:50:50 by mozer             #+#    #+#             */
/*   Updated: 2022/09/14 20:20:34 by mozer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len] != 0)
		len++;
	return (len);
}

int	ft_isspace(int c)
{
	if (c == ' ' || c == '\r' || c == '\f' || c == '\v'
		|| c == '\n' || c == '\t')
		return (1);
	return (0);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int				i;
	unsigned long	ret;
	int				isnegative;

	i = 0;
	ret = 0;
	isnegative = 1;
	while (str[i] == '\n' && str[i] == ' ')
		i++;
	if (str[i] == '-')
		isnegative *= -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		ret = (ret * 10) + (str[i] - '0');
		i++;
	}
	if ((ret > 2147483647 && isnegative != -1)
		|| (ret > 2147483648 && isnegative == -1))
	{
		write(2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	return (ret * isnegative);
}

int	is_uniq(t_list *stack)
{
	int		data;
	t_list	*temp;

	temp = stack;
	data = temp->data;
	while (stack && temp->next != NULL)
	{
		if (stack->next != NULL && data == stack->next->data)
		{
			write(1, "Error\n", 6);
			pause();
			free_stack(&stack);
			exit(1);
			return (0);
		}
		else if (stack->next == NULL)
		{
			temp = temp->next;
			data = temp->data;
			stack = temp;
		}
		else
			stack = stack->next;
	}
	return (1);
}
