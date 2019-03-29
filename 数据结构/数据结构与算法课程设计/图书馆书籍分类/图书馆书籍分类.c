#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct
{
    int number;
    char name[30];
    char author[30];
    char publish[30];
    char date[30];
}Book;

typedef struct Node1
{
    Book book;
    struct Node1 *next;
}List;

typedef struct
{
    char username[30];
    char password[30];
}Account;

typedef struct Node2
{
    Account account;
    struct Node2 *next;
}AccountList;

List *L;
AccountList *A_L;

List *Create()
{
    int i;
    FILE *fp;
    List *head,*rear,*p;
    head = NULL;
    rear = NULL;
    Book book;
    if((fp=fopen("book.txt","r"))==NULL)
    {
        printf("cannot open file!");
        exit(0);
    }
    while(fscanf(fp,"%d %s %s %s %s",&book.number,book.name,book.author,
                 book.publish,book.date)!=EOF)
    {
        p = (List*)malloc(sizeof(List));
        p->book.number = book.number;
        strcpy(p->book.name,book.name);
        strcpy(p->book.author,book.author);
        strcpy(p->book.publish,book.publish);
        strcpy(p->book.date,book.date);
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

void start()
{
    printf("--------------------------------------------------------------------------\n\n");
    printf("-------------------------图书馆书籍分类查询系统---------------------------\n\n");
    printf("----------------1---系统登录                    2---系统注册--------------\n\n");
    printf("----------------3---系统介绍                    4---系统退出--------------\n\n");
    printf("----------------5---输出用户                    6---删除用户--------------\n\n");
    printf("----------------7---系统退出                    8---系统退出--------------\n\n");
    printf("--------------------------------------------------------------------------\n\n");
}

AccountList* start_init()
{
    int i;
    AccountList account[3];
    strcpy(account[0].account.username,"zhangsan");
    strcpy(account[0].account.password,"123456");
    strcpy(account[1].account.username,"lisi");
    strcpy(account[1].account.password,"123456");
    strcpy(account[2].account.username,"wangwu");
    strcpy(account[2].account.password,"123456");
    AccountList *head,*rear,*p;
    head = NULL;
    rear = NULL;
    for(i=0;i<3;i++)
    {
        p = (AccountList*)malloc(sizeof(AccountList));
        strcpy(p->account.username,account[i].account.username);
        strcpy(p->account.password,account[i].account.password);
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

void menu()
{
    printf("----------------------------------------------------\n\n");
    printf("----------欢迎来到图书馆书籍分类查询系统！----------\n\n");
    printf("----------1-书籍录入            2-书籍添加----------\n\n");
    printf("----------3-书籍修改            4-书籍删除----------\n\n");
    printf("----------5-书籍查找            6-书籍显示----------\n\n");
    printf("----------7-退出系统            8-退出系统----------\n\n");
    printf("----------------------------------------------------\n\n");
}

void read()
{
    int n,i;
    //printf("请输入你要录入的书籍数量：");
    L = Create();
}

void init()
{
    A_L = start_init();
}

int findMax(Book book[],int L,int R)
{
    if(L == R)
        return book[L].number;
    else
    {
        int a = book[L].number;
        int b = findMax(book,L+1,R);
        if(a > b)
            return a;
        else
            return b;
    }
}

void radixSort(Book book[],int k)
{
    int max = findMax(book,0,k-1);
    int i,j,num,k1,h,r,t;
    for(i=1;max/i>0;i=i*10)
    {
        Book buckets[k][10];
        for(j=0;j<k;j++)
        {
            for(h=0;h<10;h++)
            {
                buckets[j][h].number = -1;
            }
        }
        for(j=0;j<k;j++)
        {
            num = (book[j].number/i)%10;
            buckets[j][num].number = book[j].number;
            strcpy(buckets[j][num].name,book[j].name);
            strcpy(buckets[j][num].author,book[j].author);
            strcpy(buckets[j][num].publish,book[j].publish);
            strcpy(buckets[j][num].date,book[j].date);
        }
        k1 = 0;
        for(r=0;r<10;r++)
        {
            for(t=0;t<k;t++)
            {
                if(buckets[t][r].number!=-1)
                {
                    book[k1].number = buckets[t][r].number;
                    strcpy(book[k1].name,buckets[t][r].name);
                    strcpy(book[k1].author,buckets[t][r].author);
                    strcpy(book[k1].publish,buckets[t][r].publish);
                    strcpy(book[k1].date,buckets[t][r].date);
                    k1++;
                }
            }
        }
    }
}

int binary_search(Book book[],int len,int book_num)
{
    int low = 0;
    int hight = len - 1;
    int midder;
    while(low <= hight)
    {
        midder = (low + hight) / 2;
        if(book[midder].number == book_num)
        {
            return midder;
        }
        else if(book[midder].number > book_num)
        {
            hight = midder - 1;
        }
        else if(book[midder].number < book_num)
        {
            low = midder + 1;
        }
    }
    return -1;
}

int search_num(List *l,int book_num)
{
    Book book[100];
    int k=0,i;
    List *p = l;
    while(p)
    {
        book[k].number = p->book.number;
        strcpy(book[k].name,p->book.name);
        strcpy(book[k].author,p->book.author);
        strcpy(book[k].publish,p->book.publish);
        strcpy(book[k].date,p->book.date);
        p = p->next;
        k++;
    }
    for(i=0;i<k;i++)
        printf("%d %s %s %s %s\n",book[i].number,book[i].name,book[i].author,book[i].publish,book[i].date);
    printf("------------------------\n");
    radixSort(book,k);
    for(i=0;i<k;i++)
        printf("%d %s %s %s %s\n",book[i].number,book[i].name,book[i].author,book[i].publish,book[i].date);
    int num = binary_search(book,k,book_num);
    if(num == -1)
    {
        printf("查询失败！\n");
        printf("没有查到编号为%d的书籍\n",book_num);
    }
    else
    {
        printf("查询成功！\n");
        printf("%d %s %s %s %s\n",book[num].number,book[num].name,book[num].author,book[num].publish,book[num].date);
    }
    /*List *p = l;
    while(p)
    {
        if(p->book.number == book_num)
            break;
        p = p->next;
    }
    return p;*/
    return num;
}

List* search_name(List *l,char book_name[])
{
    List *p = l;
    while(p)
    {
        if(strcmp(p->book.name,book_name)==0)
            break;
        p = p->next;
    }
    return p;
}

List* search_author(List *l,char book_author[])
{
    List *p = l;
    List *head,*rear,*q;
    head = NULL;
    rear = NULL;
    while(p)
    {
        if(strcmp(p->book.author,book_author) == 0)
        {
            q = (List*)malloc(sizeof(List));
            q->book.number = p->book.number;
            strcpy(q->book.name,p->book.name);
            strcpy(q->book.author,p->book.author);
            strcpy(q->book.publish,p->book.publish);
            strcpy(q->book.date,p->book.date);
            if(head == NULL)
            {
                head = q;
                rear = q;
                q->next = NULL;
            }
            else
            {
                rear->next = q;
                rear = q;
            }
        }
        p = p->next;
    }
    rear->next = NULL;
    return head;
}

List* search_publish(List *l,char book_publish[])
{
    List *p = l;
    List *head,*rear,*q;
    head = NULL;
    rear = NULL;
    while(p)
    {
        if(strcmp(p->book.publish,book_publish) == 0)
        {
            q = (List*)malloc(sizeof(List));
            q->book.number = p->book.number;
            strcpy(q->book.name,p->book.name);
            strcpy(q->book.author,p->book.author);
            strcpy(q->book.publish,p->book.publish);
            strcpy(q->book.date,p->book.date);
            if(head == NULL)
            {
                head = q;
                rear = q;
                q->next = NULL;
            }
            else
            {
                rear->next = q;
                rear = q;
            }
        }
        p = p->next;
    }
    rear->next = NULL;
    return head;
}

List* search_date(List *l,char book_date[])
{
    List *p = l;
    List *head,*rear,*q;
    head = NULL;
    rear = NULL;
    while(p)
    {
        if(strcmp(p->book.date,book_date) == 0)
        {
            q = (List*)malloc(sizeof(List));
            q->book.number = p->book.number;
            strcpy(q->book.name,p->book.name);
            strcpy(q->book.author,p->book.author);
            strcpy(q->book.publish,p->book.publish);
            strcpy(q->book.date,p->book.date);
            if(head == NULL)
            {
                head = q;
                rear = q;
                q->next = NULL;
            }
            else
            {
                rear->next = q;
                rear = q;
            }
        }
        p = p->next;
    }
    rear->next = NULL;
    return head;
}

List* add(List *l)
{
    List *p = (List*)malloc(sizeof(List));
    List *q;
    Book book;
    FILE *fp;
    if((fp=fopen("book.txt","a"))==NULL)
    {
        printf("cannot open file");
        exit(0);
    }
    printf("请依次输入要增加书籍的编号、名称、作者、出版社、出版日期（用空格隔开）：");
    scanf("%d %s %s %s %s",&p->book.number,p->book.name,p->book.author,p->book.publish,p->book.date);
    book.number = p->book.number;
    strcpy(book.name,p->book.name);
    strcpy(book.author,p->book.author);
    strcpy(book.publish,p->book.publish);
    strcpy(book.date,p->book.date);
    fprintf(fp,"%-5d %-30s %-20s %-30s %-20s\n",book.number,book.name,book.author,
            book.publish,book.date);
    fclose(fp);
    List *s = l;
    while(s)
    {
        if(s->next == NULL)
            break;
        s = s->next;
    }
    p->next = s->next;
    s->next = p;
    return l;
}

List *del(List *l)
{
    int book_num,index=1;
    printf("请输入你要删除的书籍编号：");
    scanf("%d",&book_num);
    int q = search_num(l,book_num);
    if(q == -1)
    {
        printf("删除失败！编号为%d的书籍不存在！\n",book_num);
        return l;
    }
    else
    {
        if(l->book.number == book_num)
        {
            List *p = l;
            l = l->next;
            free(p);
            return l;
        }
        else
        {
            List *p = l,*q;
            while(p)
            {
                if(p->next->book.number == book_num)
                    break;
                p = p->next;
            }
            q = p->next;
            p->next = q->next;
            free(q);
            return l;
        }
    }
}

List* modify(List *l)
{
    int n,book_num;
    char book_name[30],book_author[30],book_publish[30],book_date[30];
    printf("请输入要修改的书籍名称：");
    scanf("%s",book_name);
    List *p = l;
    while(p)
    {
        if(strcmp(p->book.name,book_name)==0)
            break;
        p = p->next;
    }
    if(p == NULL)
    {
        printf("修改失败！\n");
        printf("书名为%s的书籍不存在！\n",book_name);
    }
    else
    {
        printf("-----1-书籍编号修改                    2-书籍名称修改-----\n");
        printf("-----3-书籍作者修改                    4-出版社修改-----\n");
        printf("-----5-出版日期修改                               -----\n");
        printf("请输入修改的功能编号：");
        scanf("%d",&n);
        if(n == 1)
        {
            printf("请输入修改后的书籍编号：");
            scanf("%d",&book_num);
            p->book.number = book_num;
            return l;
        }
        else if(n == 2)
        {
            printf("请输入修改后的书籍名称：");
            scanf("%s",book_name);
            strcpy(p->book.name,book_name);
            return l;
        }
        else if(n == 3)
        {
            printf("请输入修改后的书籍作者：");
            scanf("%s",book_author);
            strcpy(p->book.author,book_author);
            return l;
        }
        else if(n == 4)
        {
            printf("请输入修改后的出版社名称：");
            scanf("%s",book_publish);
            strcpy(p->book.publish,book_publish);
            return l;
        }
        else if(n == 5)
        {
            printf("请输入修改后的出版日期：");
            scanf("%s",book_date);
            strcpy(p->book.date,book_date);
            return l;
        }
    }
}

void show(List *l)
{
    List *p = l;
    printf("编号   名称                          作者                 出版社                         出版日期\n");
    while(p)
    {
        printf("%-5d %-30s %-20s %-30s %-20s\n\n",p->book.number,p->book.name,p->book.author,p->book.publish,p->book.date);
        p = p->next;
    }
}

void search(List *l)
{
    int n,book_num;
    char book_name[30],book_author[30],book_publish[30],book_date[30];
    printf("-----1-书籍编号查询                    2-书籍名称查询-----\n");
    printf("-----3-书籍作者查询                    4-出版社查询-----\n");
    printf("-----5-出版日期查询                                -----\n");
    printf("请输入查询的功能编号：");
    scanf("%d",&n);
    if(n==1)
    {
        printf("请输入要查询的书籍编号：");
        scanf("%d",&book_num);
        search_num(l,book_num);
    }
    else if(n == 2)
    {
        List *p;
        printf("请输入要查询的书籍名称：");
        scanf("%s",book_name);
        p = search_name(l,book_name);
        if(p == NULL)
        {
            printf("查询失败！\n");
            printf("没有查到名称为%s的书籍\n",book_name);
        }
        else
        {
            printf("查询成功！\n");
            printf("编号:%d 名称:%s 作者:%s 出版社:%s 出版日期%s\n",p->book.number,p->book.name,p->book.author,
                   p->book.publish,p->book.date);
        }
    }
    else if(n == 3)
    {
        printf("请输入要查询的作者名称：");
        scanf("%s",book_author);
        printf("%s",book_author);
        List *p = search_author(l,book_author);
        if(p == NULL)
        {
            printf("查询失败！\n");
            printf("没有查到作者为%s的相关书籍！\n",book_author);
        }
        else
        {
            printf("查询成功！\n");
            show(p);
        }
    }
    else if(n == 4)
    {
        printf("请输入要查询的出版社名称：");
        scanf("%s",book_publish);
        List *p = search_publish(l,book_publish);
        if(p == NULL)
        {
            printf("查询失败！\n");
            printf("没有查到出版社为%s的相关书籍！\n",book_publish);
        }
        else
        {
            printf("查询成功！\n");
            show(p);
        }
    }
    else if(n == 5)
    {
        printf("请输入要查询的出版时间：");
        scanf("%s",book_date);
        List *p = search_date(l,book_date);
        if(p == NULL)
        {
            printf("查询失败！\n");
            printf("没有查到出版社时间为%s的相关书籍！\n",book_date);
        }
        else
        {
            printf("查询成功！\n");
            show(p);
        }
    }
}

AccountList* add_account(AccountList *l)
{
    char user_name[30];
    char user_pass[30];
    printf("请输入要注册的用户名：");
    scanf("%s",user_name);
    printf("请输入要注册的密码：");
    scanf("%s",user_pass);
    AccountList *p = (AccountList*)malloc(sizeof(AccountList));
    strcpy(p->account.username,user_name);
    strcpy(p->account.password,user_pass);
    AccountList *q = A_L;
    while(q)
    {
        if(q->next == NULL)
            break;
        q = q->next;
    }
    p->next = q->next;
    q->next = p;
    return l;
}

void print_user(AccountList *l)
{
    AccountList *p = l;
    while(p)
    {
        printf("用户名：%s 密码：%s\n",p->account.username,p->account.password);
        p = p->next;
    }
}

void update_book(List *l)
{
    FILE *fp;
    if((fp=fopen("book.txt","w"))==NULL)
    {
        printf("cannot open file");
        exit(0);
    }
    List *p = l;
    Book book;
    while(p)
    {
        book.number = p->book.number;
        strcpy(book.name,p->book.name);
        strcpy(book.author,p->book.author);
        strcpy(book.publish,p->book.publish);
        strcpy(book.date,p->book.date);
        fprintf(fp,"%-5d %-30s %-20s %-30s %-20s\n",book.number,book.name,book.author,book.publish,book.date);
        p = p->next;
    }
    fclose(fp);
}

void main()
{
    init();
    read();
    while(1)
    {
        int main_num;
        start();
        printf("请输入系统功能编号：");
        scanf("%d",&main_num);
        if(main_num == 1)
        {
            char user_name[30];
            char user_pass[30];
            printf("请输入用户名：");
            scanf("%s",user_name);
            printf("请输入密码：");
            scanf("%s",user_pass);
            AccountList *p = A_L;
            while(p)
            {
                if((strcmp(p->account.username,user_name)==0)&&strcmp(p->account.password,user_pass)==0)
                    break;
                p = p->next;
            }
            if(p == NULL)
            {
                printf("登录失败！用户名或密码有误！\n");
            }
            else
            {
                while(1)
                {
                    int num;
                    menu();
                    printf("请输入功能编号：");
                    scanf("%d",&num);
                    if(num==1)
                    {
                        read();
                    }
                    else if(num == 2)
                    {
                        L = add(L);
                    }
                    else if(num == 3)
                    {
                        L = modify(L);
                        update_book(L);
                    }
                    else if(num == 4)
                    {
                        L = del(L);
                        update_book(L);
                    }
                    else if(num == 5)
                    {
                        search(L);
                    }
                    else if(num == 6)
                    {
                        show(L);
                    }
                    else if(num == 7 || num == 8)
                    {
                        break;
                    }
                    system("pause");
                    system("cls");
                }
            }
        }
        else if(main_num == 2)
        {
            A_L = add_account(A_L);
        }
        else if(main_num == 4)
            break;
        else if(main_num == 5)
            print_user(A_L);
        system("pause");
        system("cls");
    }
}
