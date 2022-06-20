#include "deneme.h"

typedef struct elma{ 

    int data;
    struct elma *next;
    struct elma *prew;

}t_list;

void    sa(t_list   *stack_a)
{
    int a = stack_a -> data;
    int b = stack_a -> next -> data;

    stack_a -> data = b;
    stack_a -> next -> data = a;
    printf("\nsa\n");
}

t_list  *list_last(t_list   *stack_a)
{
    while(stack_a -> next != NULL)
        stack_a = stack_a -> next;
    return (stack_a);
}

t_list    *ra(t_list *stack_a)
{
    t_list  *listenin_yeni_basi;
    t_list  *listenin_basi;
    t_list  *listenin_sonu;

    listenin_basi = stack_a;
    listenin_yeni_basi = stack_a -> next;
    listenin_sonu = list_last(stack_a);

    listenin_sonu -> next = stack_a;
    listenin_basi -> next = NULL;
    printf("\nra\n");
    return (listenin_yeni_basi);
}

t_list    *rra(t_list *stack_a)
{
    // prew uygulayacağım
    stack_a -> prew = NULL;
    t_list *listeninYeniBasi;
    t_list *listeninSonu;
    t_list *listeninBasi;

    listeninBasi = stack_a;
    listeninYeniBasi = list_last(stack_a);
    listeninSonu = list_last(stack_a) -> prew;

    printf("\nrra\n");

    return(listeninYeniBasi);

}

int main(int argv,char **argc)
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

    int i = 0;
    while(i++ < 5)
    {
        printf("%d ", stack_b -> data);
        stack_b = stack_b -> next;
    }
    // stack_b = stack_a;
    // sa(stack_a);
    // i = 0;
    // while(i++ < 5)
    // {
    //     printf("%d ", stack_b -> data);
    //     stack_b = stack_b -> next;
    // }
    // stack_a = ra(stack_a);

    stack_a = rra(stack_a);
    //stack_b = stack_a;
    i = 0;
    while(i++ < 5)
    {
        printf("%d ", stack_a -> data);
        stack_a = stack_a -> next;
    }
    // t_list  *stack_b;
    // t_list  *prew_stack_a;

    // stack_a = malloc(sizeof(t_list));
    // stack_a -> data = 1;
    // stack_a -> next = NULL;
    // stack_a -> prew = NULL;
    
    // stack_b = stack_a;

    // int i = 0;
    // while (i++ < 10)
    // {
    //     stack_a -> next = malloc(sizeof(t_list));
    //     prew_stack_a = stack_a;
    //     stack_a = stack_a -> next;
    //     stack_a -> data = i * 20;
    //     stack_a -> next = NULL;
    //     stack_a -> prew = prew_stack_a;
    // }
    // i = 0;
    // printf("%d", stack_b -> next -> next -> next -> prew -> prew -> data);
    
}