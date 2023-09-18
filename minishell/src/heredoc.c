/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozturk <onur_fb_5959@hotmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 14:24:56 by ehazir            #+#    #+#             */
/*   Updated: 2023/02/13 12:36:25 by oozturk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

// dosyayı kapatıp free yapıp heredoc'u sonlandırır
void	heredoc_exit(int fd, char *eof, char *to_write)
{
	close(fd);
	free(eof);
	free(to_write);
	exit (0);
}

// sinyal geldiyse heredoc dosyasını oluşturur ve heredoc'u kapatır
void	h_signhandler(int sign)
{
	if (sign == SIGINT)
	{
		open(".heredoc", O_WRONLY | O_CREAT | O_TRUNC, 0777);
		exit(0);
	}
}

// heredoc oluşturur
// heredoc kullanarak oluşturduğumuz dosyasının içine yazdırır
void	heredoc_propt(int index)
{
	char	*to_write;
	char	*eof;
	int		fd;

	fd = open(".heredoc", O_WRONLY | O_CREAT | O_TRUNC, 0777);
	signal(SIGINT, h_signhandler);
	while (1 && fd)
	{
		eof = ft_strdup(list_data(g_data->arg, index + 1));
		to_write = readline(">");
		if (ft_strcmp(to_write, eof))
			heredoc_exit(fd, eof, to_write);
		else
		{
			ft_putstr_fd(to_write, fd);
			ft_putstr_fd("\n", fd);
		}
		if (g_data->heredoc_quit == 1)
			heredoc_exit(fd, eof, to_write);
		free(eof);
		free(to_write);
	}
}

// fork ile child process oluşturur, process bitene kadar bekler
void	heredoc(void)
{
	t_list	*iter;
	int		index;
	int		pid;

	index = heredoc_finder();
	iter = g_data->arg;
	pid = fork();
	if (pid == 0)
		heredoc_propt(index);
	wait(NULL);
}

// heredoc işaretinin varlığını kontrol eder
int	heredoc_check(void)
{
	t_list	*iter;

	iter = g_data->arg;
	if (!lstcmp2(iter, "<<"))
	{
		g_data->h_count = heredoc_count();
		heredoc();
	}
	return (1);
}
