/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozturk <onur_fb_5959@hotmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 12:37:15 by ehazir            #+#    #+#             */
/*   Updated: 2023/02/13 12:37:58 by oozturk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

/*
yeni liste oluşturup içine content koyar
*/

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (new == NULL)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

/*
int main()
{
    char new1[] = "Ferdi TAYFUR";
	t_list new;
    // new = (t_list *)malloc(sizeof(int));
    //printf("%s", (char *)ft_lstnew(new1));
	new = *ft_lstnew(new1);
	printf("%s", new.content);

}
*/