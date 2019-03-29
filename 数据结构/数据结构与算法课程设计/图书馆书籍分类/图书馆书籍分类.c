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
    printf("-------------------------ͼ����鼮�����ѯϵͳ---------------------------\n\n");
    printf("----------------1---ϵͳ��¼                    2---ϵͳע��--------------\n\n");
    printf("----------------3---ϵͳ����                    4---ϵͳ�˳�--------------\n\n");
    printf("----------------5---����û�                    6---ɾ���û�--------------\n\n");
    printf("----------------7---ϵͳ�˳�                    8---ϵͳ�˳�--------------\n\n");
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
    printf("----------��ӭ����ͼ����鼮�����ѯϵͳ��----------\n\n");
    printf("----------1-�鼮¼��            2-�鼮���----------\n\n");
    printf("----------3-�鼮�޸�            4-�鼮ɾ��----------\n\n");
    printf("----------5-�鼮����            6-�鼮��ʾ----------\n\n");
    printf("----------7-�˳�ϵͳ            8-�˳�ϵͳ----------\n\n");
    printf("----------------------------------------------------\n\n");
}

void read()
{
    int n,i;
    //printf("��������Ҫ¼����鼮������");
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
        printf("��ѯʧ�ܣ�\n");
        printf("û�в鵽���Ϊ%d���鼮\n",book_num);
    }
    else
    {
        printf("��ѯ�ɹ���\n");
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
    printf("����������Ҫ�����鼮�ı�š����ơ����ߡ������硢�������ڣ��ÿո��������");
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
    printf("��������Ҫɾ�����鼮��ţ�");
    scanf("%d",&book_num);
    int q = search_num(l,book_num);
    if(q == -1)
    {
        printf("ɾ��ʧ�ܣ����Ϊ%d���鼮�����ڣ�\n",book_num);
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
    printf("������Ҫ�޸ĵ��鼮���ƣ�");
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
        printf("�޸�ʧ�ܣ�\n");
        printf("����Ϊ%s���鼮�����ڣ�\n",book_name);
    }
    else
    {
        printf("-----1-�鼮����޸�                    2-�鼮�����޸�-----\n");
        printf("-----3-�鼮�����޸�                    4-�������޸�-----\n");
        printf("-----5-���������޸�                               -----\n");
        printf("�������޸ĵĹ��ܱ�ţ�");
        scanf("%d",&n);
        if(n == 1)
        {
            printf("�������޸ĺ���鼮��ţ�");
            scanf("%d",&book_num);
            p->book.number = book_num;
            return l;
        }
        else if(n == 2)
        {
            printf("�������޸ĺ���鼮���ƣ�");
            scanf("%s",book_name);
            strcpy(p->book.name,book_name);
            return l;
        }
        else if(n == 3)
        {
            printf("�������޸ĺ���鼮���ߣ�");
            scanf("%s",book_author);
            strcpy(p->book.author,book_author);
            return l;
        }
        else if(n == 4)
        {
            printf("�������޸ĺ�ĳ��������ƣ�");
            scanf("%s",book_publish);
            strcpy(p->book.publish,book_publish);
            return l;
        }
        else if(n == 5)
        {
            printf("�������޸ĺ�ĳ������ڣ�");
            scanf("%s",book_date);
            strcpy(p->book.date,book_date);
            return l;
        }
    }
}

void show(List *l)
{
    List *p = l;
    printf("���   ����                          ����                 ������                         ��������\n");
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
    printf("-----1-�鼮��Ų�ѯ                    2-�鼮���Ʋ�ѯ-----\n");
    printf("-----3-�鼮���߲�ѯ                    4-�������ѯ-----\n");
    printf("-----5-�������ڲ�ѯ                                -----\n");
    printf("�������ѯ�Ĺ��ܱ�ţ�");
    scanf("%d",&n);
    if(n==1)
    {
        printf("������Ҫ��ѯ���鼮��ţ�");
        scanf("%d",&book_num);
        search_num(l,book_num);
    }
    else if(n == 2)
    {
        List *p;
        printf("������Ҫ��ѯ���鼮���ƣ�");
        scanf("%s",book_name);
        p = search_name(l,book_name);
        if(p == NULL)
        {
            printf("��ѯʧ�ܣ�\n");
            printf("û�в鵽����Ϊ%s���鼮\n",book_name);
        }
        else
        {
            printf("��ѯ�ɹ���\n");
            printf("���:%d ����:%s ����:%s ������:%s ��������%s\n",p->book.number,p->book.name,p->book.author,
                   p->book.publish,p->book.date);
        }
    }
    else if(n == 3)
    {
        printf("������Ҫ��ѯ���������ƣ�");
        scanf("%s",book_author);
        printf("%s",book_author);
        List *p = search_author(l,book_author);
        if(p == NULL)
        {
            printf("��ѯʧ�ܣ�\n");
            printf("û�в鵽����Ϊ%s������鼮��\n",book_author);
        }
        else
        {
            printf("��ѯ�ɹ���\n");
            show(p);
        }
    }
    else if(n == 4)
    {
        printf("������Ҫ��ѯ�ĳ��������ƣ�");
        scanf("%s",book_publish);
        List *p = search_publish(l,book_publish);
        if(p == NULL)
        {
            printf("��ѯʧ�ܣ�\n");
            printf("û�в鵽������Ϊ%s������鼮��\n",book_publish);
        }
        else
        {
            printf("��ѯ�ɹ���\n");
            show(p);
        }
    }
    else if(n == 5)
    {
        printf("������Ҫ��ѯ�ĳ���ʱ�䣺");
        scanf("%s",book_date);
        List *p = search_date(l,book_date);
        if(p == NULL)
        {
            printf("��ѯʧ�ܣ�\n");
            printf("û�в鵽������ʱ��Ϊ%s������鼮��\n",book_date);
        }
        else
        {
            printf("��ѯ�ɹ���\n");
            show(p);
        }
    }
}

AccountList* add_account(AccountList *l)
{
    char user_name[30];
    char user_pass[30];
    printf("������Ҫע����û�����");
    scanf("%s",user_name);
    printf("������Ҫע������룺");
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
        printf("�û�����%s ���룺%s\n",p->account.username,p->account.password);
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
        printf("������ϵͳ���ܱ�ţ�");
        scanf("%d",&main_num);
        if(main_num == 1)
        {
            char user_name[30];
            char user_pass[30];
            printf("�������û�����");
            scanf("%s",user_name);
            printf("���������룺");
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
                printf("��¼ʧ�ܣ��û�������������\n");
            }
            else
            {
                while(1)
                {
                    int num;
                    menu();
                    printf("�����빦�ܱ�ţ�");
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
