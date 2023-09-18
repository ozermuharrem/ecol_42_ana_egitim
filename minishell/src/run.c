/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozturk <onur_fb_5959@hotmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 14:24:56 by ehazir            #+#    #+#             */
/*   Updated: 2023/02/13 12:37:11 by oozturk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	run_cmd(t_list *list)
{
	if (ft_strcmp(list->content, "echo"))
		run_echo(list);
	else if (ft_strcmp(list->content, "cd"))
		run_cd(list);
	else if (ft_strcmp(list->content, "pwd"))
		run_pwd();
	else if (ft_strcmp(list->content, "export"))
		ft_export(list);
	else if (ft_strcmp(list->content, "unset"))
		run_unset(list);
	else if (ft_strcmp(list->content, "env"))
		ft_env();
	else if (ft_strcmp(list->content, "exit"))
		run_exit(list);
	else
		run_next(list_to_char(list));
}
