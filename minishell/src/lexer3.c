/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozturk <onur_fb_5959@hotmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 14:24:56 by ehazir            #+#    #+#             */
/*   Updated: 2023/02/13 12:36:36 by oozturk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	errormessage(int i)
{
	if (i == 1)
	{
		write(2, "minishell: parse error near '<'\n", 33);
		free(g_data->line);
	}
	else
	{
		write(2, "minishell: syntax error near expected token '|'\n", 49);
		free(g_data->line);
	}
}

int	lexer_next(int count)
{
	if (count == -1)
	{
		free(g_data->line);
		return (0);
	}
	else if (count > 0)
	{
		command_cut(count);
		return (-1);
	}
	return (1);
}
