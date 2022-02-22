#include	"libft.h"
#include	<stdio.h> 

int	main()
{
	char okul[] = "xyztc";

	t_list	*root;
	root =ft_lstnew(okul);

	printf("%s",root->content);
}
