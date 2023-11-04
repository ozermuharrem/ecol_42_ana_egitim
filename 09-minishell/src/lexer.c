/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozturk <onur_fb_5959@hotmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 14:24:56 by ehazir            #+#    #+#             */
/*   Updated: 2023/02/13 12:36:32 by oozturk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

// <>| işaretlerini dizide tutar
void	lex_add(int count)
{
	char	*mal;
	int		i;

	i = 0;
	mal = malloc(sizeof(char *) * count + 1);
	while (count > 0)
	{
		mal[i] = *g_data->line;
		g_data->line++;
		count--;
		i++;
	}
	mal[i] = '\0';
	ft_lstadd_back(&g_data->arg, ft_lstnew(mal));
}

// | > < işaretlerinin sayısını lex_add fonksiyonuna gönderip listeye ekler
int	lexer_count(int count, int i)
{
	if (i == 1)
	{
		if (count > 0)
			lex_add(count);
		else if (count == -1)
			return (0);
	}
	else if (i == 2)
	{
		if (count > 0)
			lex_add(count);
	}
	return (1);
}

// tırnak içi stringin uzunluğunu alır
int	return_text(int a, int i)
{
	if (a == 1)
	{
		i++;
		while (g_data->line[i] != 34 && g_data->line[i] != '\0')
			i++;
		while (g_data->line[i] != ' ' && g_data->line[i] != '\0')
			i++;
		return (i);
	}
	else if (a == 2)
	{
		i++;
		while (g_data->line[i] != 39 && g_data->line[i] != '\0')
			i++;
		while (g_data->line[i] != ' ' && g_data->line[i] != '\0')
			i++;
		return (i);
	}
	return (1);
}

// tırnak gördüğü yerden itibaren string uzunluğunu döndürür
int	text_compare(void)
{
	int (i) = 0;
	while ((g_data->line[i] != ' ' && g_data->line[i] != '\0') && \
		(g_data->line[i] != '>' && g_data->line[i] != '<' \
			&& g_data->line[i] != '|'))
	{
		if (g_data->line[i] == 34)
		{
			i = return_text(1, i);
			return (i);
		}
		if (g_data->line[i] == 39)
		{
			i = return_text(2, i);
			return (i);
		}
		i++;
	}
	return (i);
}

int	lexer(void)
{
	int (count) = 0;
	int (next_fonk) = 0;
	char *(tmp) = g_data->line;
	while (*g_data->line)
	{
		space();
		if (g_data->arg == NULL || \
				ft_strcmp("|", ft_lstlast(g_data->arg)->content))
		{
			next_fonk = lexer_next(commands());
			if (next_fonk == -1)
				continue ;
			else if (next_fonk == 0)
				return (0);
		}
		count = compare2();
		if (lexer_count(count, 1) == 0)
			return (0);
		count = text_compare();
		lexer_count(count, 2);
	}
	free(tmp);
	return (1);
}
