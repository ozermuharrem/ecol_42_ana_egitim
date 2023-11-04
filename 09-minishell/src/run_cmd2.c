/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_cmd2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozturk <onur_fb_5959@hotmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 14:24:56 by ehazir            #+#    #+#             */
/*   Updated: 2023/02/13 12:37:09 by oozturk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	exec(char *path, char **arg)
{
	char	**env;

	env = list_to_char(g_data->lst_env);
	if (execve(path, arg, env) == -1)
	{
		reset_stdout();
		printf("%s: command not found.\n", arg[0]);
		free(path);
		exit(127);
	}
}

char	*f_path(char **arg)
{
	char	**path;
	char	*path_tmp;

	int (i) = 0;
	path_tmp = check_env(ft_strdup("PATH"));
	if (!path_tmp)
		printf("%s: No such file or directory\n", arg[0]);
	if (arg[0][0] == '.')
		path_tmp = ft_strjoin(path_tmp, ":./");
	else if (access(arg[0], F_OK) == 0)
		return (arg[0]);
	path = ft_split(path_tmp, ':');
	while (path[i])
	{
		path[i] = ft_strjoin(path[i], "/");
		path[i] = ft_strjoin(path[i], arg[0]);
		if (access(path[i], F_OK) == 0)
			break ;
		i++;
	}
	return (path[i]);
}

void	run_next(char **arg)
{
	int	pid;
	int	i;
	int	ret;

	i = 0;
	pid = fork();
	if (pid == 0)
		exec(f_path(arg), arg);
	waitpid(pid, &ret, 0);
	g_data->exit_status = ret % 255;
	wait(NULL);
	while (arg[i])
	{
		free(arg[i]);
		i++;
	}
	free(arg);
}

void	run_exit(t_list *list)
{
	if (list->next != NULL)
	{
		list = list->next;
		g_data->exit_status = ft_atoi(list->content);
	}
	exit(g_data->exit_status);
}

void	exporter(char *content, int i, t_list *list)
{
	while (content != NULL)
	{
		if (content == NULL)
			break ;
		if (lstcmp(content) && ft_strchr(content, '='))
			ft_lstadd_back(&g_data->lst_env, ft_lstnew(ft_strdup(content)));
		else if (lstcmp(content) && !ft_strchr(content, '='))
			ft_lstadd_back(&g_data->declare, ft_lstnew(ft_strdup(content)));
		else
		{
			destroy_node(g_data->cmp);
			if (ft_strchr(content, '='))
				ft_lstadd_back(&g_data->lst_env, ft_lstnew(ft_strdup(content)));
		}
		i++;
		content = list_data(list, i);
	}
	free(content);
}
