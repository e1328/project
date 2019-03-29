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
    printf("学号 姓名 成绩\n");
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
        printf("插入失败\n");
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
        printf("第%d个学生不存在\n",k-1);
        return ptrl;
    }
    else if(s == NULL)
    {
        printf("第%d个学生不存在\n",k);
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
        printf("%s这个学生不存在\n",str);
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
    printf("学生个数为：%d\n",index);
}

void menu()
{
    printf("*******************学生信息管理系统*******************\n");
    printf("1----------输入信息---------2-----------------显示信息\n");
    printf("3----------按姓名查找-------4-----------按指定位置查找\n");
    printf("5----------插入学生信息-----6-----------按指定位置删除\n");
    printf("7----------按姓名删除-------8-------------输出学生个数\n");
    printf("0----------退出系统-----------------------------------\n");
    printf("*******************学生信息管理系统*******************\n");
}

int main()
{
    int num,n,index;
    char str[20];
    List *L,*tmp;
    while(1)
    {
        menu();
        printf("请输入功能编号：");
        scanf("%d",&num);
        if(num == 1)
        {
            printf("请输入要创建的学生个数：");
            scanf("%d",&n);
            printf("请输入要创建的学生学号 姓名 成绩\n");
            L = CreateTail(n);
        }
        else if(num == 2)
        {
            print(L);
        }
        else if(num == 3)
        {
            printf("请输入要查找的学生姓名：");
            scanf("%s",str);
            tmp = Find(str,L);
            if(tmp == NULL)
                printf("查找失败\n");
            else
                printf("学生学号：%s 成绩：%d\n",tmp->data.no,tmp->data.score);
        }
        else if(num == 4)
        {
            printf("请输入要查找的学生位置：");
            scanf("%d",&index);
            tmp = FindKth(index,L);
            if(tmp == NULL)
                printf("查找失败\n");
            else
                printf("学生学号：%s 成绩：%d\n",tmp->data.no,tmp->data.score);
        }
        else if(num == 5)
        {
            Student x;
            printf("请输入要插入的学生信息：(学号 姓名 成绩)\n");
            scanf("%s %s %d",x.no,x.name,&x.score);
            printf("请输入要插入的学生位置：");
            scanf("%d",&index);
            L = Insert(x,index,L);
        }
        else if(num == 6)
        {
            printf("请输入要删除的学生位置：");
            scanf("%d",&index);
            L = DeleteKth(index,L);
        }
        else if(num == 7)
        {
            printf("请输入要删除的学生姓名：");
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
