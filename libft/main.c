#include	"libft.h"
#include <stdio.h> 

// void    *ft_calloc(size_t count, size_t size);

int main()
{
    int *a;
    a = (int *) ft_calloc(5, sizeof(int));
    printf("%p - %d\n", a, *a);
    printf("%lu",sizeof(int) * 5);
}