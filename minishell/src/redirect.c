/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozturk <onur_fb_5959@hotmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 14:24:56 by ehazir            #+#    #+#             */
/*   Updated: 2023/02/13 12:37:03 by oozturk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	cut_redirect(int index)
{
	ft_dstry_node_for_red(g_data->arg, index);
	ft_dstry_node_for_red(g_data->arg, index);
}

void	right_redirect(int index, int r)
{
	int	fd;

	while (r > 0)
	{
		fd = open (list_data(g_data->arg, index + 1), O_RDWR | O_CREAT | \
				O_TRUNC, 0777);
		close (fd);
		cut_redirect(index);
		r--;
	}
	g_data->to_open = list_data(g_data->arg, index + 1);
	cut_redirect(index);
	fd = open(g_data->to_open, O_RDWR | O_CREAT | O_TRUNC, 0777);
	if (fd < 0)
		return ;
	dup2(fd, 1);
	close (fd);
}

void	double_right_redirect(int index, int r_c)
{
	int	fd;

	while (r_c > 0)
	{
		fd = open (list_data(g_data->arg, index + 1), \
			O_RDWR | O_CREAT | O_TRUNC, 0777);
		close (fd);
		index += 2;
		r_c--;
	}
	g_data->to_open = list_data(g_data->arg, index + 1);
	cut_redirect(index);
	fd = open(g_data->to_open, O_RDWR | O_APPEND, 0777);
	if (fd < 0)
		return ;
	dup2(fd, 1);
	close (fd);
}

void	left_redirect(int index, int r_c)
{
	int	fd;

	while (r_c > 0)
	{
		fd = open(list_data(g_data->arg, index + 1), \
			O_RDWR | O_CREAT | O_TRUNC, 0777);
		close (fd);
		index += 2;
		r_c--;
	}
	g_data->to_open = list_data(g_data->arg, index + 1);
	cut_redirect(index);
	fd = open(g_data->to_open, O_RDWR, 0777);
	if (fd < 0)
	{
		printf("no such file\n");
		exit(0);
	}
	dup2(fd, 0);
	close(fd);
}

void	redirect_decider(int status, int index, int r_c)
{
	if (status == 1)
		right_redirect(index, r_c);
	else if (status == 2)
		double_right_redirect(index, r_c);
	else if (status == 3)
		left_redirect(index, r_c);
	else if (status == 4)
		run_heredoc(index);
}
