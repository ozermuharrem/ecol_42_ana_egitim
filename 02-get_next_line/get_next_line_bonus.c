/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozer <mozer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 10:44:39 by mozer             #+#    #+#             */
/*   Updated: 2022/03/08 10:51:56 by mozer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*_line(int fd, char *my_str)
{
	char	*buffer;
	int		a;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	a = 1;
	while (!ft_strchr(my_str, '\n') && a > 0)
	{
		a = read(fd, buffer, BUFFER_SIZE);
		if (a > 0)
		{
			buffer[a] = '\0';
			my_str = ft_strjoin(my_str, buffer);
		}
	}
	free(buffer);
	return (my_str);
}

char	*get_next_line(int fd)
{
	static char	*my_str[4096];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	my_str[fd] = _line(fd, my_str[fd]);
	if (!my_str[fd])
		return (NULL);
	line = new_line(my_str[fd]);
	my_str[fd] = my_new_str(my_str[fd]);
	return (line);
}
