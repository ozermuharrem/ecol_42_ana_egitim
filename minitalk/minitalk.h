/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozer <mozer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 11:48:44 by mozer             #+#    #+#             */
/*   Updated: 2022/05/08 12:05:13 by mozer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# define PIDERROR "PID Error!"
# define ARGERROR "ARG Error!"

# include <unistd.h>
# include <stdlib.h>
# include <signal.h>

char	*ft_itoa(int n);
void	ft_putstr(char *str);
int		ft_atoi(const char *str);
int		ft_strlen(const char *str);
char	*ft_strjoin(char *s1, char const s2);
char	*ft_strdup(const char *str);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

#endif