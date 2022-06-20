#include "deneme.h"

typedef struct s_list{ 

    int data;
    struct s_list *next;
    struct s_list *prew;

}t_list;

t_list  *list_last(t_list   *stack_a)
{
    while(stack_a -> next != NULL)
        stack_a = stack_a -> next;
    return (stack_a);
}

 t_list    *rra(t_list *stack_a)
{
    t_list  *prew_stack_a;
     // prew uygulayacağım
    stack_a -> prew = NULL;

   
    int i;

    i = 0;
     while(i++ < 5)
     {
          printf("fonksiyon içinde stack_a %d ", stack_a->data);
        // prew_stack_a = stack_a;
        // stack_a = stack_a -> next;
        // stack_a -> next = NULL;
        // stack_a -> prew = prew_stack_a;
     }
     
     t_list *listeninYeniBasi;
     t_list *listeninSonu;
     t_list *listeninBasi;

     listeninBasi = stack_a;
     listeninYeniBasi = list_last(stack_a);
     listeninSonu = prew_stack_a;
     stack_a -> prew = NULL;

    printf("\nrra\n");

    return(stack_a);

}

int main()
{
    t_list  *stack_a;
    t_list  *stack_b;
    int dizi[5] = {34, 123, -243, 0, 7};
    stack_a = malloc(sizeof(t_list));
    stack_a -> data = dizi[0];
    
    stack_b = stack_a;

    stack_a -> next = malloc(sizeof(t_list));
    stack_a -> next -> data = dizi[1];

    stack_a -> next -> next = malloc(sizeof(t_list));
    stack_a -> next -> next -> data = dizi[2];
    
    stack_a -> next -> next -> next = malloc(sizeof(t_list));
    stack_a -> next -> next -> next -> data = dizi[3];

    stack_a -> next -> next -> next -> next = malloc(sizeof(t_list));
    stack_a -> next -> next -> next -> next -> data = dizi[4];

    stack_a = rra(stack_a);

    int i = 0;
    while(i++ < 5)
    {
        printf("%d ", stack_b -> data);
        stack_b = stack_b -> next;
    }

   // stack_a = rra(stack_a);
    stack_b = stack_a;
    i = 0;
    while(i++ < 5)
    {
        printf("\n%d ", stack_a -> data);
        stack_a = stack_a -> next;
    }
}

