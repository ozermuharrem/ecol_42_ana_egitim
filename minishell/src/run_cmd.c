/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozturk <onur_fb_5959@hotmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 14:24:56 by ehazir            #+#    #+#             */
/*   Updated: 2023/02/13 12:37:07 by oozturk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	run_echo(t_list *list)
{
	int (i) = 1;
	if (list_data(list, i) == NULL)
		printf("\n");
	else
	{
		if (!ft_strcmp(list_data(list, i), "-n"))
		{
			while (list_data(list, i) != NULL)
			{
				if (list_data(list, i + 1) == NULL)
					printf("%s\n", list_data(list, i));
				else
					printf("%s ", list_data(list, i));
				i++;
			}
		}
		else
			command_echo(list, ++i);
	}
	g_data->exit_status = 0;
}

void	run_cd(t_list *list)
{
	char	str[256];
	char	*pwd;

	int (i) = 0;
	g_data->cd = 1;
	pwd = NULL;
	if (list_data(list, i + 1) != NULL)
	{
		pwd = ft_strjoin(getcwd(str, sizeof(str)), "/");
		i++;
		pwd = ft_strjoin2(pwd, list_data(list, i));
		if (access(pwd, F_OK) == -1)
		{
			printf("cd: %s: No such file or directory\n", list_data(list, i));
			free(pwd);
			return ;
		}
		chdir(pwd);
		pwd_update(i, list);
		free(pwd);
	}
	else
		just_cd(i, list);
	g_data->cd = 0;
	g_data->exit_status = 0;
}

void	run_pwd(void)
{
	char	*pwd;

	pwd = check_env(ft_strdup("PWD"));
	printf("%s\n", pwd);
	free(pwd);
	g_data->exit_status = 0;
}

void	run_unset(t_list *list)
{
	int (i) = 0;
	ft_lstremove(list, i);
	g_data->exit_status = 0;
}

void	ft_env(void)
{
	t_list	*tmp;
	t_list	*iter;

	tmp = g_data->lst_env;
	while (tmp != NULL)
	{
		iter = tmp;
		printf("%s\n", tmp->content);
		tmp = tmp->next;
	}
	g_data->exit_status = 0;
}
