#include<stdio.h>
void swap1(int a,int b)
{
    int c;
    c = a;
    a = b;
    b = c;
}
void swap2(int *p1,int *p2)
{
    int c;
    c = *p1;
    *p1 = *p2;
    *p2 = c;
}
void main()
{
    int a = 1;
    int b = 2;
    swap1(a,b);
    printf("a=%d,b=%d\n",a,b);
    swap2(&a,&b);
    printf("a=%d,b=%d\n",a,b);
}
