/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozturk <onur_fb_5959@hotmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 14:24:56 by oozturk           #+#    #+#             */
/*   Updated: 2023/02/13 12:42:31 by oozturk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ctrl_d(void)
{
	printf("\b\bexit\n");
	free(g_data->line);
	exit(1);
}

void	sighandler(int num)
{
	if (num == SIGINT)
	{
		printf("\n");
		rl_on_new_line();
		rl_redisplay();
	}
}

void	lst_free(void)
{
	t_list	*iter;

	while (g_data->arg != NULL)
	{
		iter = g_data->arg;
		free(g_data->arg->content);
		g_data->arg = g_data->arg->next;
		free(iter);
	}
}

void	fd_free(int **fd)
{
	int	i;

	i = 0;
	while (i <= g_data->pipe)
	{
		free(fd[i]);
		i++;
	}
	free(fd);
}

void	reset_stdout(void)
{
	dup2(g_data->saved_stdout, STDOUT_FILENO);
	close(g_data->saved_stdout);
}
