#include "deneme.h"

typedef struct m_list
{
    int data;
    struct m_list *next;
}ahmet_list;

int main(int argc, char **argv)
{
    ahmet_list *yiginA;
    ahmet_list *yiginB;
    
    yiginA = malloc(sizeof(ahmet_list));
    yiginB = yiginA;

    //yiginA -> data = argv[1][0];

    //printf("%c",yiginA -> data);

     int i;

     i = 0;
     while(i++ < argc)
    {
         yiginA -> data = argv[i][0];
         yiginA = yiginA -> next = malloc(sizeof(ahmet_list));
    }

    printf("%c",yiginA->data);
    // i = 0;
    // while (i < argc)
    // {
    //     printf("%c",yiginA -> data);
    //     i++;
    // }
    

}
