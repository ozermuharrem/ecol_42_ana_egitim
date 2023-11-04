/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozturk <onur_fb_5959@hotmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 14:24:56 by ehazir            #+#    #+#             */
/*   Updated: 2023/02/13 12:36:53 by oozturk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	check_cmnd2(int **fd, int i)
{
	int (stat) = 0;
	int (index) = 0;
	while (!ft_strcmp(g_data->arg->content, "|") && g_data->arg != NULL)
	{
		ft_lstadd_back(&g_data->pipe_arg, ft_lstnew(g_data->arg->content));
		g_data->arg = g_data->arg->next;
		if (g_data->arg == NULL)
			break ;
		stat = arg_check();
		if (stat)
			break ;
		index++;
	}
	g_data->iter = g_data->pipe_arg;
	if (stat > 0)
		status_decider(stat, index);
	else if (i == 0)
		dup2(fd[0][1], 1);
	else if (i != g_data->pipe)
		dup2(fd[i][1], STDOUT_FILENO);
	wr_close_pipe(fd);
	run_cmd(g_data->pipe_arg);
}

void	create_pipe(int **fd)
{
	int	i;

	i = 0;
	while (i <= g_data->pipe)
	{
		if (pipe(fd[i]) == -1)
		{
			perror("");
			return ;
		}
		i++;
	}
}

void	run_pipe(void)
{
	int	pid;
	int	**fd;
	int	i;

	fd = malloc(sizeof(int *) * (g_data->pipe + 1));
	i = 0;
	while (i <= g_data->pipe)
		fd[i++] = malloc(sizeof(int) * 2);
	create_pipe(fd);
	pid = fork();
	i = 0;
	if (pid == 0)
	{
		check_cmnd2(fd, i);
		exit(0);
	}
	else
	{
		wait(NULL);
		waitpid(pid, NULL, 0);
		other_pipe_child(i, fd);
	}
	fd_free(fd);
}

int	has_pipe(void)
{
	t_list	*iter;

	iter = g_data->arg;
	while (iter != NULL)
	{
		if (ft_strcmp(iter->content, "|"))
		{
			if (iter->next == NULL)
			{
				write(2, "ERROR: A few arguments after pipe\n", 35);
				return (-1);
			}
			return (1);
		}
		iter = iter->next;
	}
	return (0);
}

void	pipe_count(void)
{
	t_list	*iter;

	iter = g_data->arg;
	g_data->pipe = 0;
	while (iter != NULL)
	{
		if (ft_strcmp(iter->content, "|"))
			g_data->pipe++;
		iter = iter->next;
	}
}
