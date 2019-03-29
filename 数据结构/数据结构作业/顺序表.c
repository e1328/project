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
    printf("学号 姓名 成绩\n");
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
            printf("学生学号：%s 成绩：%d\n",ptrl->data[i].no,ptrl->data[i].score);
            break;
        }
    }
}

void FindKth(int k,SqList *ptrl)
{
    printf("学生学号 %s 姓名 %s 成绩 %d\n",ptrl->data[k-1].no,ptrl->data[k-1].name,ptrl->data[k-1].score);
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
    printf("学生个数为：%d\n",ptrl->last);
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
    SqList *L;
    L = MakeEmpty();
    while(1)
    {
        menu();
        printf("请输入功能编号：");
        scanf("%d",&num);
        if(num==1)
        {
            printf("请输入要增加的学生个数：");
            scanf("%d",&n);
            printf("请输入要增加的学生学号 姓名 成绩\n");
            Add(n,L);
        }
        else if(num==2)
        {
            Print(L);
        }
        else if(num==3)
        {
            printf("请输入要查找的学生姓名：");
            scanf("%s",str);
            Find(str,L);
        }
        else if(num==4)
        {
            printf("请输入要查找的学生位置：");
            scanf("%d",&index);
            FindKth(index,L);
        }
        else if(num==5)
        {
            Student x;
            printf("请输入要插入的学生信息：(学号 姓名 成绩)\n");
            scanf("%s %s %d",x.no,x.name,&x.score);
            printf("请输入要插入的学生位置：");
            scanf("%d",&index);
            Insert(index,x,L);
        }
        else if(num ==6)
        {
            printf("请输入要删除的学生位置：");
            scanf("%d",&index);
            DeleteKth(index,L);
        }
        else if(num == 7)
        {
            printf("请输入要删除的学生姓名：");
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
