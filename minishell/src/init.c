/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozturk <onur_fb_5959@hotmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 14:24:56 by ehazir            #+#    #+#             */
/*   Updated: 2023/02/13 12:36:30 by oozturk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ft_fill(void)
{
	int (i) = 0;
	g_data->lst_env = NULL;
	while (g_data->env[i] != NULL)
	{
		ft_lstadd_back(&g_data->lst_env, \
			ft_lstnew(ft_strdup(g_data->env[i])));
		i++;
	}
	alpha_finder();
}

void	env_init(char **env)
{
	printf("\n\033[1;31m|--------------->\033[1m \
	\033[1;34mMiniShell\033[0m \
	\033[1;31m<---------------|\033[0m\n\n");
	g_data = malloc(sizeof(t_env));
	g_data->user = ft_strjoin(getenv("USER"), "\033[0;34m@minishell -> \033[0m");
	g_data->env = env;
	g_data->cd = 0;
	ft_fill();
	g_data->saved_stdout = dup(1);
	g_data->saved_stdin = dup(0);
	g_data->l_redirect = 0;
	g_data->r_redirect = 0;
	g_data->dl_redirect = 0;
	g_data->dr_redirect = 0;
	g_data->heredoc_quit = 0;
	signal(SIGINT, sighandler);
	signal(SIGQUIT, SIG_IGN);
}

void	reset_stdin(void)
{
	dup2(g_data->saved_stdin, STDIN_FILENO);
	close(g_data->saved_stdin);
}
