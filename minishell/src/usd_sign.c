/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usd_sign.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozturk <onur_fb_5959@hotmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 14:24:56 by ehazir            #+#    #+#             */
/*   Updated: 2023/02/13 12:37:14 by oozturk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

// env ataması: env adından sonrasını alır
char	*result_env(int i, char *str)
{
	int		len;
	int		j;
	char	*tmp;

	j = i;
	len = 0;
	while (str[j++])
		len++;
	tmp = malloc(sizeof(char *) * (len + 1));
	j = 0;
	while (str[i++])
		tmp[j++] = str[i];
	tmp[j] = '\0';
	return (tmp);
}

// env döndürür
char	*check_env(char *env)
{
	t_list	*temp;
	char	*name;
	size_t	i;

	i = 0;
	temp = g_data->lst_env;
	while (temp != NULL)
	{
		name = env_name(temp->content);
		if (ft_strcmp(name, env))
		{
			free(env);
			while (i < ft_strlen(name))
				i++;
			free(name);
			return (result_env(i, temp->content));
		}
		temp = temp->next;
		free(name);
	}
	free(env);
	return (NULL);
}

// ? olan kısımları işler ve bulundupu konum ve bir önceki karakteri tarar.
char	*question_mark(char *str, char *tmp, int i, int j)
{
	char	*exit;

	exit = ft_itoa(g_data->exit_status);
	while (exit[i])
	{
		tmp[i] = exit[i];
		i++;
	}
	j++;
	while (str[j] != '\0' && str[j] != 32 && str[j] != 34 \
			&& str[j] != '$' && str[j] != 39)
	{
		tmp[i] = str[j];
		i++;
		j++;
	}
	tmp[i] = '\0';
	free(exit);
	free(str);
	return (tmp);
}

int	size_finder(char *str, int j)
{
	int	len;

	len = 0;
	while (str[j] != '\0' && str[j] != 32 && str[j] != 34 && str[j] != '$')
	{
		j++;
		len++;
	}
	return (len);
}

// $ ve ? kontrol
char	*usd_sign(char *str, int j)
{
	char	*env;
	char	*ret;
	char	*tmp;

	int (i) = 0;
	tmp = malloc(size_finder(str, j) + 1);
	if (str[j] == 34 || ft_strlen(str) == 1)
		return ("$\0");
	if (str[j] == '?')
		return (question_mark(str, tmp, i, j));
	while (str[j] != '\0' && str[j] != 32 && str[j] != 34 \
			&& str[j] != '$' && str[j] != 39)
	{
		tmp[i] = str[j];
		i++;
		j++;
	}
	tmp[i] = '\0';
	free(str);
	env = check_env(tmp);
	if (env == NULL)
		return ("");
	ret = ft_strdup(env);
	free(env);
	return (ret);
}
