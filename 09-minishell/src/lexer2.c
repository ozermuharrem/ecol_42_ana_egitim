/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozturk <onur_fb_5959@hotmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 14:24:56 by ehazir            #+#    #+#             */
/*   Updated: 2023/02/13 12:36:34 by oozturk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	space(void)
{
	int	i;

	i = 0;
	while (g_data->line[i] <= 32 && g_data->line[i + 1] != '\0')
		g_data->line++;
	if (g_data->line[i] <= 32 && g_data->line[i + 1] == '\0')
	{
		*g_data->line = '\0';
		return ;
	}
}

// Tırnak içi uzunluğu
int	command_length(int i)
{
	if (g_data->line[i] == 34)
	{
		while (g_data->line[i] != 34 && g_data->line[i] != '\0')
			i++;
		i++;
		while (g_data->line[i] > 32 && g_data->line[i] != '\0')
			i++;
		return (i);
	}
	else if (g_data->line[i] == 39)
	{
		i++;
		while (g_data->line[i] != 39 && g_data->line[i] != '\0')
			i++;
		i++;
		while (g_data->line[i] > 32 && g_data->line[i] != '\0')
			i++;
		return (i);
	}
	return (0);
}

// komut kontrolü(|, >, <, ', ") 
int	commands(void)
{
	int	i;

	i = 0;
	if (g_data->line[i] == '|')
	{
		write(2, "minishell: syntax error near unexpected token '|'\n", 51);
		return (-1);
	}
	while ((g_data->line[i] != ' ' && g_data->line[i] != '\0') && \
		(g_data->line[i] != '>' && g_data->line[i] != '<' \
		&& g_data->line[i] != '|'))
	{
		if (g_data->line[i] == 34 || g_data->line[i] == 39)
		{
			i = command_length(i);
			return (i);
		}
		i++;
	}
	return (i);
}

// Tırnak içi kelimeleri listeye atar
void	command_cut(int len)
{
	int		i;
	char	*mal;

	i = 0;
	mal = malloc(sizeof(char *) * len);
	while (len > 0)
	{
		if (*g_data->line == 34 || *g_data->line == 39)
			g_data->line++;
		else
		{
			mal[i] = *g_data->line;
			g_data->line++;
			i++;
		}
		len--;
	}
	mal[i] = '\0';
	if (mal[0] != '\0')
		ft_lstadd_back(&g_data->arg, ft_lstnew(mal));
}

// > < | işaretlerinin sayısını döndürür
// (>, < işareti 2'den fazlaysa -1 döndürür)
int	compare2(void)
{
	int (i) = 0;
	if (g_data->line[i] == '>' || g_data->line[i] == '<' \
		|| g_data->line[i] == '|')
	{
		if ((g_data->line[i] == '>' && g_data->line[i + 1] == '>') || \
				(g_data->line[i] == '<' && g_data->line[i + 1] == '<'))
		{
			if (g_data->line[i + 2] == '>' || g_data->line[i + 2] == '<')
			{
				errormessage(1);
				return (-1);
			}
			else
				return (2);
		}
		else if (g_data->line[i] == '|' && g_data->line[i + 1] == '|')
		{
			errormessage(2);
			return (-1);
		}
		else
			return (1);
	}
	return (0);
}
