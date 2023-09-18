/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozturk <onur_fb_5959@hotmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 14:24:56 by ehazir            #+#    #+#             */
/*   Updated: 2023/02/13 12:37:00 by oozturk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	other_pipe_child(int i, int **fd)
{
	t_list	*iter;
	int		pid;

	while (++i < g_data->pipe + 1)
	{
		go_pipe();
		if (ft_strcmp(g_data->arg->content, "|"))
		{
			iter = g_data->arg;
			free(g_data->arg->content);
			g_data->arg = g_data->arg->next;
			free(iter);
		}
		pid = fork();
		if (pid == 0)
		{
			dup2(fd[i - 1][0], STDIN_FILENO);
			check_cmnd2(fd, i);
			exit(0);
		}
	}
	wr_close_pipe(fd);
	waitpid(pid, NULL, 0);
	wait(NULL);
}

void	wr_close_pipe(int **fd)
{
	int	j;

	j = 0;
	while (j < g_data->pipe)
	{
		close(fd[j][1]);
		close(fd[j][0]);
		j++;
	}
}
