#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int Data;
    struct Node *Next;
}List;

// 头插法（有头节点）
List* HeadCreate1()
{
    int x,i;
    List *p;
    List *head;
    head = (List*)malloc(sizeof(List));
    head->Next = NULL;
    head->Data = 0;
    for(i=0;i<3;i++)
    {
        scanf("%d",&x);
        p = (List*)malloc(sizeof(List));
        p->Data = x;
        p->Next = head->Next;
        head->Next = p;
        head->Data++;
    }
    return head;
}

// 头插法（无头节点）
List* HeadCreate2()
{
    int x,i;
    List *p;
    List *head;
    head = NULL;
    for(i=0;i<3;i++)
    {
        scanf("%d",&x);
        p = (List*)malloc(sizeof(List));
        p->Data = x;
        if(head == NULL)
        {
            head = p;
            p->Next = NULL;
        }
        else
        {
            p->Next = head;
            head = p;
        }
    }
    return head;
}

// 尾插法（有头节点）
List* TailCreate1()
{
    int x,i;
    List *p;
    List *head;
    List *rear;
    head = (List*)malloc(sizeof(List));
    head->Next = NULL;
    rear = head;
    for(i=0;i<3;i++)
    {
        scanf("%d",&x);
        p = (List*)malloc(sizeof(List));
        p->Data = x;
        rear->Next = p;
        rear = p;
    }
    rear->Next = NULL;
    return head;
}

// 尾插法（无头节点）
List* TailCreate2()
{
    int x,i;
    List *p;
    List *head;
    List *rear;
    head = NULL;
    rear = NULL;
    for(i=0;i<3;i++)
    {
        scanf("%d",&x);
        p = (List*)malloc(sizeof(List));
        p->Data = x;
        if(head == NULL)
        {
            head = p;
            rear = p;
            p->Next = NULL;
        }
        else
        {
            rear->Next = p;
            rear = p;
        }
    }
    rear->Next = NULL;
    return head;
}

// 1.求表长
int Length(List *PtrL)
{
    List *p=PtrL;
    int i=0;
    while(p)
    {
        p=p->Next;
        i++;
    }
    return i;
}


// 2.查找-按顺序查找
List* FindKth(int k,List *PtrL)
{
    List *p = PtrL;
    int i = 1;
    while(p!=NULL && i<k)
    {
        p = p->Next;
        i++;
    }
    if(p==NULL)
        return NULL;
    else
        return p;
}

// 2.查找-按值查找
List* Find(int x,List *PtrL)
{
    List *p=PtrL;
    while(p!=NULL && p->Data!=x)
        p = p->Next;
    return p;
}

// 3.插入
List* Insert(List *PtrL,int k,int x)
{
    List *p,*s;
    if(k==1)
    {
        s = (List*)malloc(sizeof(List));
        s->Data = x;
        s->Next = Ptrl;
        return s;
    }
    p = FindKth(k-1,PtrL);
    if(p==NULL)
    {
        printf("请输入正确的k值");
        return NULL;
    }
    else
    {
        s=(List*)malloc(sizeof(List));
        s->Data = x;
        s->Next = p->Next;
        p->Next = s;
        return PtrL;
    }
}

// 4.删除
List* Delete(int k,List *PtrL)
{
    List *p,*s;
    if(k==1)
    {
        s = PtrL;
        PtrL = PtrL->Next;
        free(s);
        return PtrL;
    }
    p = FindKth(k-1,PtrL);
    s = p->Next;
    if(p == NULL)
    {
        printf("第%d个结点不存在",k-1);
        return NULL;
    }
    else if(s == NULL)
    {
        printf("第%d个结点不存在",k);
        return NULL;
    }
    else
    {
        p->Next = s->Next;
        free(s);
        return PtrL;
    }
}

void main()
{
    int num;
    List *L,*L1;
    L = TailCreate2();
    L1 = L;
    while(L)
    {
        printf("%d ",L->Data);
        L = L->Next;
    }
    num=Length(L1);
    printf("\n%d",num);
}
