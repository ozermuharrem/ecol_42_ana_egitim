/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozturk <onur_fb_5959@hotmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 12:36:42 by oozturk           #+#    #+#             */
/*   Updated: 2023/02/13 12:40:40 by oozturk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	q_check(char *str)
{
	int (i) = 0;
	int (k) = 0;
	int (l) = 0;
	while (str[i])
	{
		if (str[i] == 39)
			k++;
		if (str[i] == 34)
			l++;
		i++;
	}
	if (k % 2 == 0 && l % 2 == 0)
		return (1);
	else
	{
		printf("unexpected quote behavior\n");
		return (0);
	}
}

int	lines(void)
{
	g_data->line = readline(g_data->user);
	if (!g_data->line)
		ctrl_d();
	add_history(g_data->line);
	if (g_data->line[0] == 0)
		return (0);
	if (!q_check(g_data->line))
		return (0);
	return (1);
}

int	main(int argc, char **argv, char **env)
{
	(void) argc;
	(void)	**argv;
	env_init(env);
	while (1)
	{
		if (!lines())
		{
			free(g_data->line);
			continue ;
		}
		if (!lexer())
			continue ;
		expand();
		executor();
		lst_free();
	}
}
