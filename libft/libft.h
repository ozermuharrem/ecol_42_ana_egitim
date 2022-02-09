/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozer <mozer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 20:50:52 by mozer             #+#    #+#             */
/*   Updated: 2022/02/10 00:30:24 by mozer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>

void    ft_bzero(void *s, size_t n);
int ft_isalnum(int c);
int ft_isalpha(char str);
int ft_isascii(int c);
int ft_isdigit(int c);
int ft_isprint(int c);
int ft_memcmp(const void *s1, const void *s2, size_t n);
void    *ft_memcpy(void *dst, const void *src, size_t n);
void    *ft_memmove(void *dst, const void *src, size_t len);
void    *ft_memset(void *str, int c, size_t len);
char    *ft_strchr(const char *s, int c);
size_t  ft_strlen(const char *s);
size_t  ft_strlen(const char *s);
size_t  ft_strlen(const char *s);
int ft_strncmp(const char *s1, const char *s2, size_t n);
char    *ft_strnstr(const char *haystack, const char *needle, size_t len);
size_t  ft_strlen(const char *s);
int ft_tolower(int c);
int ft_toupper(int c);


#endif