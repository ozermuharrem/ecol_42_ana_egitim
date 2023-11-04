/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozturk <onur_fb_5959@hotmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 14:24:56 by ehazir            #+#    #+#             */
/*   Updated: 2023/02/13 12:36:26 by oozturk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

// heredoc işaretini bul
int	heredoc_finder(void)
{
	int		i;
	t_list	*iter;

	i = 0;
	iter = g_data->arg;
	while (iter)
	{
		if (ft_strcmp(iter->content, "<<"))
			return (1);
		i++;
		iter = iter->next;
	}
	return (0);
}

// heredoc işaretinin sayısını al
int	heredoc_count(void)
{
	t_list	*iter;
	int		i;

	iter = g_data->arg;
	i = 0;
	while (iter)
	{
		if (ft_strcmp(iter->content, "<<"))
			i++;
		iter = iter->next;
	}
	return (i);
}

// son hamle
void	run_heredoc(int i)
{
	int	fd;

	fd = open(".heredoc", O_RDWR, 0777);
	if (fd < 0)
		return ;
	dup2(fd, 0);
	close(fd);
	cut_heredoc(i);
	run_cmd(g_data->arg);
}

void	cut_heredoc(int index)
{
	int (i) = g_data->h_count;
	destroy2(g_data->arg, index);
	destroy2(g_data->arg, index);
	while (i > 1)
	{
		destroy2(g_data->arg, index);
		destroy2(g_data->arg, index);
		i--;
	}
}
