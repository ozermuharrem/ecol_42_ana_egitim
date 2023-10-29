/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozer <mozer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 15:50:51 by mozer             #+#    #+#             */
/*   Updated: 2022/03/08 15:50:51 by mozer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

int		get_len(int nbr);
int		ekranayaz(char c);
int		stringyaz(char *str);
int		ptr_(unsigned long n);
int		ptryaz(unsigned long n);
int		basamakyay(unsigned int c);
int		unsigneditooo(unsigned int a);
int		ft_printf(const char *str, ...);
int		hex_system(unsigned int n, char c);
int		kontrol(va_list arg, const char c);

char	*ft_itoa(int n);
char	*ft_strdup(const char *str);

size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);

#endif
