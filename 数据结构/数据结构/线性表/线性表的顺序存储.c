#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 10

typedef struct
{
    int Data[MAXSIZE];
    int Last;
}List;

List* MakeEmpty()
{
    List *PtrL;
    PtrL = (List*)malloc(sizeof(List));
    PtrL->Last = -1;
    return PtrL;
}

int Find(int x,List *PtrL)
{
    int i=0;
    while(i<=PtrL->Last && PtrL->Data[i]!=x)
        i++;
    if(i>PtrL->Last)
        return -1;
    else
        return i;
}

void Insert(int x,int k,List *PtrL)
{
    int i;
    if(i<1 || i>PtrL->Last+2)
    {
        printf("插入位置不合法");
        return;
    }
    for(i=PtrL->Last;i>=k-1;i--)
        PtrL->Data[i+1]=PtrL->Data[i];
    PtrL->Data[k-1] = x;
    PtrL->Last++;
    return;
}

void Delete(int k,List *PtrL)
{
    int i;
    if(k<1 || k>PtrL->Last+1)
    {
        printf("删除位置不合法");
        return;
    }
    for(i=k;i<=PtrL->Last;i++)
        PtrL->Data[i-1]=PtrL->Data[i];
    PtrL->Last--;
    return;
}

void main()
{
    int i,a;
    List *L;
    L = MakeEmpty();
    for(i=0;i<3;i++)
    {
        scanf("%d",&a);
        L->Last++;
        L->Data[L->Last] = a;
    }
    for(i=0;i<=L->Last;i++)
        printf("%d ",L->Data[i]);
}
