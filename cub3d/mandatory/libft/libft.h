/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozturk <oozturk@student.42kocaeli.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 11:15:19 by oozturk           #+#    #+#             */
/*   Updated: 2023/05/02 14:20:37 by oozturk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdarg.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX 1024
# endif

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

///////////////BASIC_LIBFT/////////////////////////////////////////////////////
void	*ft_calloc(size_t count, size_t size);
int		ft_isalnum(int x);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int x);
void	*ft_memcpy(void *dest, const void *src, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
char	*ft_itoa(int n);
int		ft_isprint(int c);
void	*ft_memmove(void *dest, const void *src, size_t len);
void	*ft_memset(void *w, int val, size_t n);
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
char	*ft_strchr(const char *s, int x);
char	**ft_split(char const *s, char c);
void	ft_putstr_fd(char *s, int fd);
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
int		ft_strlen(const char *s);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*ft_strrchr(const char *s, int x);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_tolower(int w);
int		ft_toupper(int x);
void	ft_bzero(void *s, size_t n);
int		ft_atoi(const char *str);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
t_list	*ft_lstnew(void	*content);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstdelone(t_list *lst, void (*del)(void *));
t_list	*ft_lstlast(t_list *lst);
//////////////////////////////////GET_NEXT_LINE///////////////////////////////
char	*ft_strjoin1(char *s1, char *s2);
size_t	ft_strlen1(char *s);
char	*ft_strchr1(char *src, int c);
char	*ft_read_line(char *src);
char	*ft_save(char *src);
char	*get_line(char *src, int fd);
char	*get_next_line(int fd);
/////////////////////////////////FT_PRINTF////////////////////////////////////
int		ft_printf(const char *str, ...);
int		ft_strchecker(va_list arg, int g);
int		print_arry(char *str);
int		ft_uitoa(unsigned int u);
int		ft_bsm_say(unsigned int b);
int		ft_putchar_vol2(char c);
int		print_hex(unsigned int n, char c);
int		printer_ptr(unsigned long n);
int		print_ptr(unsigned long n);
///////////////////////////////LST FUNCTIONS///////////////////////////////////
//compare the given list to given string
int		lstcmp(t_list *iter, char *str);
//delete the number c'th node from the given list
void	ft_dstry_node(t_list *iter, int c);
//return the content of the index'th node
char	*list_data(t_list *root, int index);
//return the index'th node
t_list	*list_f_data(t_list *root, int index);
////////////////////////////////STRING FUNCTIONS////////////////////////////////
//compare 2 string with each other
int		ft_strcmp(char *asd, char *sda);
//check for the c char in the asd string
int		check_char(char *asd, char c);
#endif
