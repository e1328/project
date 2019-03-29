#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct
{
    char no[8];
    char name[20];
    int score;
}Student;

typedef struct
{
    Student data[50];
    int last;
}SqList;

SqList* MakeEmpty()
{
    SqList *List;
    List = (SqList*)malloc(sizeof(SqList));
    List->last = -1;
    return List;
}

void Add(int n,SqList *ptrl)
{
    int i;
    for(i=0;i<n;i++)
    {
        ptrl->last++;
        scanf("%s %s %d",ptrl->data[ptrl->last].no,ptrl->data[ptrl->last].name,
              &ptrl->data[ptrl->last].score);
    }
}

void Print(SqList *ptrl)
{
    int i;
    printf("ѧ�� ���� �ɼ�\n");
    for(i=0;i<=ptrl->last;i++)
        printf(" %s    %s    %d\n",ptrl->data[i].no,ptrl->data[i].name,ptrl->data[i].score);
}

void Find(char str[],SqList *ptrl)
{
    int i;
    for(i=0;i<ptrl->last;i++)
    {
        if(strcmp(str,ptrl->data[i].name)==0)
        {
            printf("ѧ��ѧ�ţ�%s �ɼ���%d\n",ptrl->data[i].no,ptrl->data[i].score);
            break;
        }
    }
}

void FindKth(int k,SqList *ptrl)
{
    printf("ѧ��ѧ�� %s ���� %s �ɼ� %d\n",ptrl->data[k-1].no,ptrl->data[k-1].name,ptrl->data[k-1].score);
}

void Insert(int k,Student x,SqList *ptrl)
{
    int i;
    for(i=ptrl->last;i>=k-1;i--)
        ptrl->data[i+1] = ptrl->data[i];
    ptrl->data[k-1] = x;
    ptrl->last++;
}

void DeleteKth(int k,SqList *ptrl)
{
    int i;
    for(i=k-1;i<=ptrl->last;i++)
        ptrl->data[i] = ptrl->data[i+1];
    ptrl->last--;
}

void Delete(char str[],SqList *ptrl)
{
    int i,index = 1;
    for(i=0;i<ptrl->last;i++)
    {
        if(strcmp(str,ptrl->data[i].name)==0)
            break;
    }
    DeleteKth(i+1,ptrl);
}

void count(SqList *ptrl)
{
    printf("ѧ������Ϊ��%d\n",ptrl->last);
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
    SqList *L;
    L = MakeEmpty();
    while(1)
    {
        menu();
        printf("�����빦�ܱ�ţ�");
        scanf("%d",&num);
        if(num==1)
        {
            printf("������Ҫ���ӵ�ѧ��������");
            scanf("%d",&n);
            printf("������Ҫ���ӵ�ѧ��ѧ�� ���� �ɼ�\n");
            Add(n,L);
        }
        else if(num==2)
        {
            Print(L);
        }
        else if(num==3)
        {
            printf("������Ҫ���ҵ�ѧ��������");
            scanf("%s",str);
            Find(str,L);
        }
        else if(num==4)
        {
            printf("������Ҫ���ҵ�ѧ��λ�ã�");
            scanf("%d",&index);
            FindKth(index,L);
        }
        else if(num==5)
        {
            Student x;
            printf("������Ҫ�����ѧ����Ϣ��(ѧ�� ���� �ɼ�)\n");
            scanf("%s %s %d",x.no,x.name,&x.score);
            printf("������Ҫ�����ѧ��λ�ã�");
            scanf("%d",&index);
            Insert(index,x,L);
        }
        else if(num ==6)
        {
            printf("������Ҫɾ����ѧ��λ�ã�");
            scanf("%d",&index);
            DeleteKth(index,L);
        }
        else if(num == 7)
        {
            printf("������Ҫɾ����ѧ��������");
            scanf("%s",str);
            Delete(str,L);
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
    return 0;
}
