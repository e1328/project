#include<stdio.h>

#define MAXSIZE 10

typedef struct LNode
{
    int Data[MAXSIZE];
    int last
}*List;

List *MakeEmpty()
{
    List L;
    L = (list)malloc(sizeof(struct LNode));
    L->list = -1;
    return L;
}
