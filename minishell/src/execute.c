/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozturk <onur_fb_5959@hotmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 14:24:56 by oozturk           #+#    #+#             */
/*   Updated: 2023/02/13 12:35:52 by oozturk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

// <> saydırma
int	redirect(void)
{
	t_list	*iter;

	if (g_data->arg == NULL)
		return (0);
	iter = g_data->arg;
	while (iter)
	{
		if (ft_strcmp(iter->content, "<") || ft_strcmp(iter->content, ">") \
			|| ft_strcmp(iter->content, ">>") || ft_strcmp(iter->content, "<<"))
		{
			if (ft_strcmp(iter->content, "<"))
				g_data->l_redirect++;
			else if (ft_strcmp(iter->content, ">"))
				g_data->r_redirect++;
			else if (ft_strcmp(iter->content, ">>"))
				g_data->dr_redirect++;
			else if (ft_strcmp(iter->content, "<<"))
				g_data->dl_redirect++;
		}
		iter = iter->next;
	}
	return (1);
}

void	run_cmd_with_redirect(void)
{
	int (pid) = fork();
	if (!pid)
	{
		if (g_data->r_redirect)
		{
			if (ft_strcmp(g_data->arg->next->content, ">"))
				right_redirect(1, redirect_cntr());
			else
				right_redirect(2, redirect_cntr());
		}
		else if (g_data->l_redirect)
		{
			if (ft_strcmp(g_data->arg->next->content, "<"))
				left_redirect(1, redirect_cntr());
			else
				left_redirect(2, redirect_cntr());
		}
		run_cmd(g_data->arg);
		exit(0);
	}
	wait(NULL);
}

void	run_cmd_with_d_redirect(void)
{
	if (!fork())
	{
		if (g_data->dl_redirect)
		{
			if (ft_strcmp(g_data->arg->next->content, "<<"))
				run_heredoc(1);
			else
				run_heredoc(2);
		}
		else if (g_data->dr_redirect)
		{
			if (ft_strcmp(g_data->arg->next->content, ">>"))
				double_right_redirect(1, redirect_cntr());
			else
				double_right_redirect(2, redirect_cntr());
		}
		run_cmd(g_data->arg);
		exit(0);
	}
	wait(NULL);
}

static void	reset_shellint(void)
{
	g_data->l_redirect = 0;
	g_data->r_redirect = 0;
	g_data->dr_redirect = 0;
	g_data->dl_redirect = 0;
}

void	executor(void)
{
	int (stat) = has_pipe();
	if (g_data->arg == NULL)
		return ;
	redirect();
	heredoc_check();
	if (stat)
	{
		pipe_count();
		run_pipe();
	}
	if (!stat)
	{
		if (g_data->r_redirect || g_data->l_redirect)
			run_cmd_with_redirect();
		else if (g_data->dl_redirect || g_data->dr_redirect)
			run_cmd_with_d_redirect();
		else if (!stat && !(g_data->dl_redirect || g_data->r_redirect \
				|| g_data->l_redirect || g_data->dr_redirect))
			run_cmd(g_data->arg);
		reset_stdout();
		reset_stdin();
		reset_shellint();
	}
	else
		return ;
}
