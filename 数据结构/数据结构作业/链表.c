#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct
{
    char no[8];
    char name[20];
    int score;
}Student;

typedef struct Node
{
    Student data;
    struct Node *next;
}List;

List *CreateTail(int n)
{
    int i;
    List *p,*head,*rear;
    head = NULL;
    rear = NULL;
    for(i=0;i<n;i++)
    {
        p = (List*)malloc(sizeof(List));
        scanf("%s %s %d",p->data.no,p->data.name,&p->data.score);
        if(head == NULL)
        {
            head = p;
            rear = p;
            p->next = NULL;
        }
        else
        {
            rear->next = p;
            rear = p;
        }
    }
    rear->next = NULL;
    return head;
}

void print(List *ptrl)
{
    List *p = ptrl;
    printf("ѧ�� ���� �ɼ�\n");
    while(p)
    {
        printf(" %s    %s    %d\n",p->data.no,p->data.name,p->data.score);
        p = p->next;
    }
}

List* Find(char str[],List *ptrl)
{
    List *p = ptrl;
    while(p!=NULL && strcmp(str,p->data.name) != 0)
        p = p->next;
    return p;
}

List* FindKth(int k,List *ptrl)
{
    int i = 1;
    List *p = ptrl;
    while(p!=NULL && i<k)
    {
        p = p->next;
        i++;
    }
    if(p==NULL)
        return NULL;
    else
        return p;
}

List *Insert(Student x,int k,List *ptrl)
{
    List *p,*s;
    if(k==1)
    {
        s = (List*)malloc(sizeof(List));
        s->data = x;
        s->next = ptrl;
        return s;
    }
    p = FindKth(k-1,ptrl);
    if(p==NULL)
    {
        printf("����ʧ��\n");
        return ptrl;
    }
    else
    {
        s = (List*)malloc(sizeof(List));
        s->data = x;
        s->next = p->next;
        p->next = s;
        return ptrl;
    }
}

List* DeleteKth(int k,List *ptrl)
{
    List *p,*s;
    if(k == 1)
    {
        s = ptrl;
        ptrl = ptrl->next;
        free(s);
        return ptrl;
    }
    p = FindKth(k-1,ptrl);
    s = p->next;
    if(p == NULL)
    {
        printf("��%d��ѧ��������\n",k-1);
        return ptrl;
    }
    else if(s == NULL)
    {
        printf("��%d��ѧ��������\n",k);
        return ptrl;
    }
    else
    {
        p->next = s->next;
        free(s);
        return ptrl;
    }
}

List* Delete(char str[],List *ptrl)
{
    List *p,*tmp;
    int index = 1;
    p = ptrl;
    while(p!=NULL && strcmp(str,p->data.name)!=0)
    {
        index++;
        p = p->next;
    }
    if(p==NULL)
    {
        printf("%s���ѧ��������\n",str);
        return ptrl;
    }
    tmp = DeleteKth(index,ptrl);
    return tmp;
}

void count(List *ptrl)
{
    List *p = ptrl;
    int index = 0;
    while(p)
    {
        index++;
        p = p->next;
    }
    printf("ѧ������Ϊ��%d\n",index);
}

void menu()
{
    printf("*******************ѧ����Ϣ����ϵͳ*******************\n");
    printf("1----------������Ϣ---------2-----------------��ʾ��Ϣ\n");
    printf("3----------����������-------4-----------��ָ��λ�ò���\n");
    printf("5----------����ѧ����Ϣ-----6-----------��ָ��λ��ɾ��\n");
    printf("7----------������ɾ��-------8-------------���ѧ������\n");
    printf("0----------�˳�ϵͳ-----------------------------------\n");
    printf("*******************ѧ����Ϣ����ϵͳ*******************\n");
}

int main()
{
    int num,n,index;
    char str[20];
    List *L,*tmp;
    while(1)
    {
        menu();
        printf("�����빦�ܱ�ţ�");
        scanf("%d",&num);
        if(num == 1)
        {
            printf("������Ҫ������ѧ��������");
            scanf("%d",&n);
            printf("������Ҫ������ѧ��ѧ�� ���� �ɼ�\n");
            L = CreateTail(n);
        }
        else if(num == 2)
        {
            print(L);
        }
        else if(num == 3)
        {
            printf("������Ҫ���ҵ�ѧ��������");
            scanf("%s",str);
            tmp = Find(str,L);
            if(tmp == NULL)
                printf("����ʧ��\n");
            else
                printf("ѧ��ѧ�ţ�%s �ɼ���%d\n",tmp->data.no,tmp->data.score);
        }
        else if(num == 4)
        {
            printf("������Ҫ���ҵ�ѧ��λ�ã�");
            scanf("%d",&index);
            tmp = FindKth(index,L);
            if(tmp == NULL)
                printf("����ʧ��\n");
            else
                printf("ѧ��ѧ�ţ�%s �ɼ���%d\n",tmp->data.no,tmp->data.score);
        }
        else if(num == 5)
        {
            Student x;
            printf("������Ҫ�����ѧ����Ϣ��(ѧ�� ���� �ɼ�)\n");
            scanf("%s %s %d",x.no,x.name,&x.score);
            printf("������Ҫ�����ѧ��λ�ã�");
            scanf("%d",&index);
            L = Insert(x,index,L);
        }
        else if(num == 6)
        {
            printf("������Ҫɾ����ѧ��λ�ã�");
            scanf("%d",&index);
            L = DeleteKth(index,L);
        }
        else if(num == 7)
        {
            printf("������Ҫɾ����ѧ��������");
            scanf("%s",str);
            L = Delete(str,L);
        }
        else if(num == 8)
        {
            count(L);
        }
        else if(num == 0)
        {
            break;
        }
    }
}
