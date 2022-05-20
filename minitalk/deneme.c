#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>


int main()
{

    char *str = "NULL";

    str = ((char *)malloc(sizeof(char)*2));
    if(!str)
        printf("str boş");
    else
        printf("str boş ama olsun");

    return 0;



}
