#include<stdio.h>

void main()
{
    int *p;
    p = malloc(sizeof(int));
    *p = 1;
    printf("%d\n",*p);
}
