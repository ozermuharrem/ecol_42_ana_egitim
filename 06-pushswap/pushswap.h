/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozer <mozer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 20:31:29 by mozer             #+#    #+#             */
/*   Updated: 2022/09/14 20:17:20 by mozer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>

typedef struct s_list
{
	int				data;
	struct s_list	*next;
}t_list;

void	push_swap(char **str, int len);
int		is_number(char **str, int arg);
t_list	*to_int(char **str, int ac);
size_t	ft_strlen(const char *str);
int		ft_isspace(int c);
int		ft_isdigit(int c);
int		ft_atoi(const char *str);
void	push(t_list **stack, int veri);
int		is_uniq(t_list *stack);
t_list	*ft_lstlast(t_list *lst);
int		ft_lstsize(t_list *lst);
int		is_sorted(t_list *stack);
int		min_index(t_list *stack);
int		min(t_list *stack);
int		big_index(t_list *stack);
int		find_index(t_list *stack, int veri);
int		ctrl_dizi(int *dizi, int min, int boyut);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	three_sort(t_list **stack);
void	give_back(t_list **stack_a, t_list **stack_b);
void	five_sort(t_list **stack, t_list **stack_b);
void	sa(t_list *lst);
void	pa(t_list **lsta, t_list **lstb);
void	ra(t_list **lsta);
void	rra(t_list **lsta);
void	sb(t_list *lst);
void	pb(t_list **lsta, t_list **lstb);
void	rb(t_list **lstb);
void	rrb(t_list **lstb);
void	ss(t_list *lsta, t_list *lstb);
void	rr(t_list **lsta, t_list **lstb);
void	rrr(t_list **lsta, t_list **lstb);
void	push_b2(t_list **stack_a, t_list **stack_b, int ort);
void	push_b(t_list **stack_a, t_list **stack_b, int *dizi, int boyut);
void	sort(t_list **stack_a);
void	free_stack(t_list **stack);
#endif
