#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//����Ա
typedef struct
{
    char admin_name[30];
    char admin_pass[30];
}Admin;

typedef struct Node1
{
    Admin admin;
    struct Node1 *next;
}AdminList;

//�û�
typedef struct
{
    char user_name[30];
    char user_pass[30];
}User;

typedef struct Node2
{
    User user;
    struct Node2 *next;
}UserList;

//ͼ��
typedef struct
{
    int num;
    char name[30];
    char author[30];
    char publish[30];
    char date[30];
    double price;
}Book;

typedef struct Node3
{
    Book book;
    struct Node3 *next;
}BookList;

AdminList *admin_list;
UserList *user_list;
BookList *book_list;

void main_menu()
{
    printf("----------------------------------------------\n");
    printf("|           ͼ����鼮�����ѯϵͳ           |\n");
    printf("|                                            |\n");
    printf("|       1--����Ա��¼      2--�û���¼       |\n");
    printf("|                                            |\n");
    printf("|       3--�û�ע��        4--ϵͳ����       |\n");
    printf("|                                            |\n");
    printf("|       5--ϵͳ�˳�        6--ϵͳ�˳�       |\n");
    printf("----------------------------------------------\n");
}

void admin_menu()
{
    printf("----------------------------------------------\n");
    printf("|                 ����Ա����                 |\n");
    printf("|                                            |\n");
    printf("|       1--�鼮����        2--�û�����       |\n");
    printf("|                                            |\n");
    printf("|       3--����Ա��ʾ      4--�˳���¼       |\n");
    printf("----------------------------------------------\n");
}

void admin_book_menu()
{
    printf("----------------------------------------------\n");
    printf("|                 �鼮�������               |\n");
    printf("|                                            |\n");
    printf("|       1--�鼮����        2--�鼮ɾ��       |\n");
    printf("|                                            |\n");
    printf("|       3--�鼮��ѯ        4--�鼮�޸�       |\n");
    printf("|                                            |\n");
    printf("|       5--�鼮��ʾ        6--�˻���һ��     |\n");
    printf("----------------------------------------------\n");
}

void admin_book_search_menu()
{
    printf("---------------------------------------------------\n");
    printf("|                   �鼮��ѯ����                  |\n");
    printf("|                                                 |\n");
    printf("|       1--�鼮��ʾ        2--���鼮��Ų�ѯ      |\n");
    printf("|                                                 |\n");
    printf("|       3--��������ѯ      4--���鼮���߲�ѯ      |\n");
    printf("|                                                 |\n");
    printf("|       5--���������ѯ    6--���������ڲ�ѯ      |\n");
    printf("|                                                 |\n");
    printf("|       7--���۸��ѯ      8--�˻���һ��          |\n");
    printf("---------------------------------------------------\n");
}

void admin_book_modify_menu()
{
    printf("-------------------------------------------------------\n");
    printf("|                    �鼮�޸Ľ���                     |\n");
    printf("|                                                     |\n");
    printf("|       1--�޸��鼮���        2--�޸��鼮����        |\n");
    printf("|                                                     |\n");
    printf("|       3--�޸��鼮����        4--�޸ĳ���������      |\n");
    printf("|                                                     |\n");
    printf("|       5--�޸ĳ�������        6--�޸��鼮�۸�        |\n");
    printf("|                                                     |\n");
    printf("|       7--�˻���һ��          8--�˻���һ��          |\n");
    printf("-------------------------------------------------------\n");
}

void admin_user_menu()
{
    printf("----------------------------------------------\n");
    printf("|                 �û��������               |\n");
    printf("|                                            |\n");
    printf("|       1--ɾ���û�        2--�޸��û�       |\n");
    printf("|                                            |\n");
    printf("|       3--��ѯ�û�        4--��ʾ�����û�   |\n");
    printf("|                                            |\n");
    printf("|       5--�˻���һ��      6--�˻���һ��     |\n");
    printf("----------------------------------------------\n");
}

void user_menu()
{
    printf("---------------------------------------------------\n");
    printf("|                  �û�����                       |\n");
    printf("|                                                 |\n");
    printf("|       1--�鼮��ʾ        2--���鼮��Ų�ѯ      |\n");
    printf("|                                                 |\n");
    printf("|       3--��������ѯ      4--���鼮���߲�ѯ      |\n");
    printf("|                                                 |\n");
    printf("|       5--���������ѯ    6--���������ڲ�ѯ      |\n");
    printf("|                                                 |\n");
    printf("|       7--���۸��ѯ      8--�˳���¼            |\n");
    printf("---------------------------------------------------\n");
}

void admin_init()
{
    Admin admin;
    AdminList *head,*rear,*p;
    head = NULL;
    rear = NULL;
    FILE *fp;
    if((fp=fopen("admin.txt","r"))==NULL)
    {
        printf("cannot open admin.txt file!");
        exit(0);
    }
    while(fscanf(fp,"%s %s",admin.admin_name,admin.admin_pass)!=EOF)
    {
        p = (AdminList*)malloc(sizeof(AdminList));
        strcpy(p->admin.admin_name,admin.admin_name);
        strcpy(p->admin.admin_pass,admin.admin_pass);
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
    fclose(fp);
    rear->next = NULL;
    admin_list = head;
}

void print_admin(AdminList *AL)
{
    AdminList *p = AL;
    while(p)
    {
        printf("%-10s %-10s\n\n",p->admin.admin_name,p->admin.admin_pass);
        p = p->next;
    }
}

int admin_validate()
{
    char name[30];
    char pass[30];
    printf("���������Ա�˺ţ�");
    scanf("%s",name);
    printf("���������Ա���룺");
    scanf("%s",pass);
    AdminList *p = admin_list;
    while(p)
    {
        if(strcmp(p->admin.admin_name,name)==0&&(strcmp(p->admin.admin_pass,pass)==0))
        {
            printf("��ӭ����Ա %s ��¼ϵͳ��\n",name);
            return 1;
        }
        p = p->next;
    }
    printf("����Ա�˺Ż���������\n");
    return 0;
}

void user_init()
{
    User user;
    UserList *head,*rear,*p;
    head = NULL;
    rear = NULL;
    FILE *fp;
    if((fp=fopen("user.txt","r"))==NULL)
    {
        printf("cannot open user.txt file!");
        exit(0);
    }
    while(fscanf(fp,"%s %s",user.user_name,user.user_pass)!=EOF)
    {
        p = (UserList*)malloc(sizeof(UserList));
        strcpy(p->user.user_name,user.user_name);
        strcpy(p->user.user_pass,user.user_pass);
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
    fclose(fp);
    rear->next = NULL;
    user_list = head;
}

void print_user(UserList *UL)
{
    UserList *p = UL;
    while(p)
    {
        printf("%-10s %-10s\n\n",p->user.user_name,p->user.user_pass);
        p = p->next;
    }
}

int user_validate()
{
    char name[30];
    char pass[30];
    printf("�������û��˺ţ�");
    scanf("%s",name);
    printf("�������û����룺");
    scanf("%s",pass);
    UserList *p = user_list;
    while(p)
    {
        if(strcmp(p->user.user_name,name)==0&&(strcmp(p->user.user_pass,pass)==0))
        {
            printf("��ӭ�û� %s ��¼ϵͳ��\n",name);
            return 1;
        }
        p = p->next;
    }
    printf("�û��˺Ż���������\n");
    return 0;
}

UserList* search_user(UserList *UL,char name[])
{
    UserList *p = UL;
    while(p)
    {
        if(strcmp(p->user.user_name,name)==0)
            break;
        p = p->next;
    }
    return p;
}

UserList* add_user(UserList *UL)
{
    char name[30];
    char pass[30];
    printf("������Ҫע����û��˺ţ�");
    scanf("%s",name);
    printf("������Ҫע����û����룺");
    scanf("%s",pass);
    if(search_user(UL,name)!=NULL)
    {
        printf("���û��Ѿ����ڣ�\n");
        return UL;
    }
    else
    {
        UserList *p = UL,*q;
        User user;
        FILE *fp;
        q = (UserList*)malloc(sizeof(UserList));
        strcpy(q->user.user_name,name);
        strcpy(q->user.user_pass,pass);
        while(p)
        {
            if(p->next==NULL)
                break;
            p = p->next;
        }
        q->next = p->next;
        p->next = q;
        if((fp=fopen("user.txt","a"))==NULL)
        {
            printf("cannot open user.txt file!");
            exit(0);
        }
        strcpy(user.user_name,name);
        strcpy(user.user_pass,pass);
        fprintf(fp,"\n%-10s %-10s",user.user_name,user.user_pass);
        fclose(fp);
        printf("�����û��ɹ���\n");
        return UL;
    }
}

UserList* del_user(UserList *UL)
{
    char name[30];
    printf("������Ҫɾ�����û�����");
    scanf("%s",name);
    if(search_user(UL,name)==NULL)
    {
        printf("���û������ڣ�\n");
        return UL;
    }
    else
    {
        UserList *p = UL,*q;
        while(p)
        {
            if(strcmp(p->next->user.user_name,name)==0)
                break;
            p = p->next;
        }
        q = p->next;
        p->next = q->next;
        free(q);
        printf("ɾ���û��ɹ���\n");
        return UL;
    }
}

UserList* modify_user(UserList *UL)
{
    char name[30],pass[30];
    printf("������Ҫ�޸ĵ��û�����");
    scanf("%s",name);
    if(search_user(UL,name)==NULL)
    {
        printf("���û������ڣ�\n");
        return UL;
    }
    else
    {
        UserList *p = UL;
        while(p)
        {
            if(strcmp(p->user.user_name,name)==0)
                break;
            p = p->next;
        }
        printf("�������޸ĺ���û�����");
        scanf("%s",name);
        printf("�������޸ĺ���û����룺");
        scanf("%s",pass);
        strcpy(p->user.user_name,name);
        strcpy(p->user.user_pass,pass);
        printf("�޸��û��ɹ���\n");
        return UL;
    }
}

void update_user(UserList *UL)
{
    FILE *fp;
    User user;
    UserList *p = UL;
    if((fp=fopen("user.txt","w"))==NULL)
    {
        printf("cannot open user.txt file!");
        exit(0);
    }
    while(p)
    {
        strcpy(user.user_name,p->user.user_name);
        strcpy(user.user_pass,p->user.user_pass);
        fprintf(fp,"%-10s %-10s\n",user.user_name,user.user_pass);
        p = p->next;
    }
    fclose(fp);
}

void book_init()
{
    Book book;
    BookList *head,*rear,*p;
    head = NULL;
    rear = NULL;
    FILE *fp;
    if((fp=fopen("book.txt","r"))==NULL)
    {
        printf("cannot open book.txt file!");
        exit(0);
    }
    while(fscanf(fp,"%d %s %s %s %s %lf",&book.num,book.name,book.author,
                 book.publish,book.date,&book.price)!=EOF)
    {
        p = (BookList*)malloc(sizeof(BookList));
        p->book.num = book.num;
        strcpy(p->book.name,book.name);
        strcpy(p->book.author,book.author);
        strcpy(p->book.publish,book.publish);
        strcpy(p->book.date,book.date);
        p->book.price = book.price;
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
    fclose(fp);
    rear->next = NULL;
    book_list = head;
}

void print_book(BookList *BL)
{
    BookList *p = BL;
    while(p)
    {
        printf("%-5d %-26s %-10s %-20s %-10s %-10.1lf\n\n",p->book.num,p->book.name,
               p->book.author,p->book.publish,p->book.date,p->book.price);
        p = p->next;
    }
}

int findMax(Book book[],int L,int R)
{
    if(L==R)
        return book[L].num;
    else
    {
        int a = book[L].num;
        int b = findMax(book,L+1,R);
        if(a>b)
            return a;
        else
            return b;
    }
}

void radixSort(Book book[],int n)
{
    int max = findMax(book,0,n-1);
    int i,j,k,num,index;
    for(i=1;max/i>0;i=i*10)
    {
        Book buckets[n][10];
        for(j=0;j<n;j++)
        {
            for(k=0;k<10;k++)
            {
                buckets[j][k].num = -1;
            }
        }
        for(j=0;j<n;j++)
        {
            num = (book[j].num/i)%10;
            buckets[j][num].num = book[j].num;
            strcpy(buckets[j][num].name,book[j].name);
            strcpy(buckets[j][num].author,book[j].author);
            strcpy(buckets[j][num].publish,book[j].publish);
            strcpy(buckets[j][num].date,book[j].date);
            buckets[j][num].price = book[j].price;
        }
        index = 0;
        for(j=0;j<10;j++)
        {
            for(k=0;k<n;k++)
            {
                if(buckets[k][j].num!=-1)
                {
                    book[index].num = buckets[k][j].num;
                    strcpy(book[index].name,buckets[k][j].name);
                    strcpy(book[index].author,buckets[k][j].author);
                    strcpy(book[index].publish,buckets[k][j].publish);
                    strcpy(book[index].date,buckets[k][j].date);
                    book[index].price = buckets[k][j].price;
                    index++;
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
        if(book[midder].num == book_num)
        {
            return midder;
        }
        else if(book[midder].num > book_num)
        {
            hight = midder - 1;
        }
        else if(book[midder].num < book_num)
        {
            low = midder + 1;
        }
    }
    return -1;
}

void search_book_num(BookList *BL)
{
    int num,k=0;
    BookList *p = BL;
    Book book[100];
    while(p)
    {
        book[k].num = p->book.num;
        strcpy(book[k].name,p->book.name);
        strcpy(book[k].author,p->book.author);
        strcpy(book[k].publish,p->book.publish);
        strcpy(book[k].date,p->book.date);
        book[k].price = p->book.price;
        k++;
        p = p->next;
    }
    printf("������Ҫ��ѯ���鼮��ţ�");
    scanf("%d",&num);
    radixSort(book,k);//��������
    int flag = binary_search(book,k,num);
    if(flag==-1)
    {
        printf("û�в�ѯ�����Ϊ%d���鼮��\n");
    }
    else
    {
        printf("���ҳɹ���\n");
        printf("%-5d %-26s %-10s %-20s %-10s %-10.1lf\n\n",book[flag].num,book[flag].name,
               book[flag].author,book[flag].publish,book[flag].date,book[flag].price);
    }
}

int search_book_num2(BookList *BL,int book_num)
{
    int num,k=0;
    BookList *p = BL;
    Book book[100];
    while(p)
    {
        book[k].num = p->book.num;
        strcpy(book[k].name,p->book.name);
        strcpy(book[k].author,p->book.author);
        strcpy(book[k].publish,p->book.publish);
        strcpy(book[k].date,p->book.date);
        book[k].price = p->book.price;
        k++;
        p = p->next;
    }
    radixSort(book,k);//��������
    int flag = binary_search(book,k,book_num);
    if(flag==-1)
        return 0;
    else
        return 1;
}

void search_book_name(BookList *BL)
{
    char name[30];
    printf("������Ҫ��ѯ���鼮���ƣ�");
    scanf("%s",name);
    BookList *p = BL;
    while(p)
    {
        if(strcmp(p->book.name,name)==0)
            break;
        p = p->next;
    }
    if(p==NULL)
        printf("û�в�ѯ������Ϊ%s���鼮��\n",name);
    else
    {
        printf("��ѯ�ɹ���\n");
        printf("%-5d %-26s %-10s %-20s %-10s %-10.1lf\n\n",p->book.num,p->book.name,
               p->book.author,p->book.publish,p->book.date,p->book.price);
    }
}

void search_book_author(BookList *BL)
{
    char author[30];
    printf("������Ҫ��ѯ���鼮�������ƣ�");
    scanf("%s",author);
    BookList *p = BL;
    BookList *head,*rear,*q;
    head = NULL;
    rear = NULL;
    while(p)
    {
        if(strcmp(p->book.author,author)==0)
        {
            q = (BookList*)malloc(sizeof(BookList));
            q->book.num = p->book.num;
            strcpy(q->book.name,p->book.name);
            strcpy(q->book.author,p->book.author);
            strcpy(q->book.publish,p->book.publish);
            strcpy(q->book.date,p->book.date);
            q->book.price = p->book.price;
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
    if(head == NULL)
        printf("û�в�ѯ���鼮����Ϊ%s���鼮��\n",author);
    else
    {
        rear->next = NULL;
        printf("��ѯ�ɹ���\n");
        BookList *p = head;
        while(p)
        {
            printf("%-5d %-26s %-10s %-20s %-10s %-10.1lf\n\n",p->book.num,p->book.name,
               p->book.author,p->book.publish,p->book.date,p->book.price);
            p = p->next;
        }
    }
}

void search_book_publish(BookList *BL)
{
    char publish[30];
    printf("������Ҫ��ѯ�ĳ��������ƣ�");
    scanf("%s",publish);
    BookList *p = BL;
    BookList *head,*rear,*q;
    head = NULL;
    rear = NULL;
    while(p)
    {
        if(strcmp(p->book.publish,publish)==0)
        {
            q = (BookList*)malloc(sizeof(BookList));
            q->book.num = p->book.num;
            strcpy(q->book.name,p->book.name);
            strcpy(q->book.author,p->book.author);
            strcpy(q->book.publish,p->book.publish);
            strcpy(q->book.date,p->book.date);
            q->book.price = p->book.price;
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
    if(head == NULL)
        printf("û�в�ѯ��������Ϊ%s���鼮��\n",publish);
    else
    {
        rear->next = NULL;
        printf("��ѯ�ɹ���\n");
        BookList *p = head;
        while(p)
        {
            printf("%-5d %-26s %-10s %-20s %-10s %-10.1lf\n\n",p->book.num,p->book.name,
               p->book.author,p->book.publish,p->book.date,p->book.price);
            p = p->next;
        }
    }
}

void search_book_date(BookList *BL)
{
    char date[30];
    printf("������Ҫ��ѯ���鼮�������ڣ�");
    scanf("%s",date);
    BookList *p = BL;
    BookList *head,*rear,*q;
    head = NULL;
    rear = NULL;
    while(p)
    {
        if(strcmp(p->book.date,date)==0)
        {
            q = (BookList*)malloc(sizeof(BookList));
            q->book.num = p->book.num;
            strcpy(q->book.name,p->book.name);
            strcpy(q->book.author,p->book.author);
            strcpy(q->book.publish,p->book.publish);
            strcpy(q->book.date,p->book.date);
            q->book.price = p->book.price;
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
    if(head == NULL)
        printf("û�в�ѯ���鼮��������Ϊ%s���鼮��\n",date);
    else
    {
        rear->next = NULL;
        printf("��ѯ�ɹ���\n");
        BookList *p = head;
        while(p)
        {
            printf("%-5d %-26s %-10s %-20s %-10s %-10.1lf\n\n",p->book.num,p->book.name,
               p->book.author,p->book.publish,p->book.date,p->book.price);
            p = p->next;
        }
    }
}

void search_book_price(BookList *BL)
{
    double start,end;
    printf("������Ҫ��ѯ�鼮����ͼ۸�");
    scanf("%lf",&start);
    printf("������Ҫ��ѯ�鼮����߼۸�");
    scanf("%lf",&end);
    BookList *p = BL;
    BookList *head,*rear,*q;
    head = NULL;
    rear = NULL;
    while(p)
    {
        if(p->book.price>=start&&p->book.price<=end)
        {
            q = (BookList*)malloc(sizeof(BookList));
            q->book.num = p->book.num;
            strcpy(q->book.name,p->book.name);
            strcpy(q->book.author,p->book.author);
            strcpy(q->book.publish,p->book.publish);
            strcpy(q->book.date,p->book.date);
            q->book.price = p->book.price;
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
    if(head == NULL)
        printf("û�в�ѯ���鼮�۸��� %.1lf ~ %.1lf ��Χ���鼮��\n",start,end);
    else
    {
        rear->next = NULL;
        printf("��ѯ�ɹ���\n");
        BookList *p = head;
        while(p)
        {
            printf("%-5d %-26s %-10s %-20s %-10s %-10.1lf\n\n",p->book.num,p->book.name,
               p->book.author,p->book.publish,p->book.date,p->book.price);
            p = p->next;
        }
    }
}

BookList *add_book(BookList *BL)
{
    Book book;
    printf("������Ҫ���ӵ��鼮��ţ�");
    scanf("%d",&book.num);
    printf("������Ҫ���ӵ��鼮���ƣ�");
    scanf("%s",book.name);
    printf("������Ҫ���ӵ��鼮���ߣ�");
    scanf("%s",book.author);
    printf("������Ҫ���ӵ��鼮���������ƣ�");
    scanf("%s",book.publish);
    printf("������Ҫ���ӵ��鼮����ʱ�䣺");
    scanf("%s",book.date);
    printf("������Ҫ���ӵ��鼮�۸�");
    scanf("%lf",&book.price);
    if(search_book_num2(BL,book.num)==1)
    {
        printf("���鼮�Ѿ����ڣ�\n");
        return BL;
    }
    else
    {
        BookList *p = BL,*q;
        FILE *fp;
        q = (BookList*)malloc(sizeof(BookList));
        q->book.num = book.num;
        strcpy(q->book.name,book.name);
        strcpy(q->book.author,book.author);
        strcpy(q->book.publish,book.publish);
        strcpy(q->book.date,book.date);
        q->book.price = book.price;
        while(p)
        {
            if(p->next==NULL)
                break;
            p = p->next;
        }
        q->next = p->next;
        p->next = q;
        if((fp=fopen("book.txt","a"))==NULL)
        {
            printf("cannot open book.txt file!");
            exit(0);
        }
        fprintf(fp,"\n%-5d %-26s %-10s %-20s %-10s %-10.1lf",book.num,book.name,book.author,book.publish,book.date,
                book.price);
        fclose(fp);
        printf("�����鼮�ɹ���\n");
        return BL;
    }
}

BookList *del_book(BookList *BL)
{
    int num;
    printf("������Ҫɾ�����鼮��ţ�");
    scanf("%d",&num);
    if(search_book_num2(BL,num)==0)
    {
        printf("���鼮�����ڣ�\n");
        return BL;
    }
    else
    {
        BookList *p = BL,*q;
        while(p)
        {
            if(p->book.num==num)
                break;
            p = p->next;
        }
        q = p->next;
        p->next = q->next;
        free(q);
        printf("ɾ���鼮�ɹ���\n");
        return BL;
    }
}

BookList *modify_book(BookList *BL)
{
    int book_num;
    printf("������Ҫ�޸ĵ��鼮��ţ�");
    scanf("%d",&book_num);
    if(search_book_num2(BL,book_num)==0)
    {
        printf("���鼮�����ڣ�\n");
        return BL;
    }
    else
    {
        int book_modify;
        admin_book_modify_menu();
        printf("�����빦�ܱ�ţ�");
        scanf("%d",&book_modify);
        if(book_modify==1)
        {
            int num;
            printf("�������޸ĺ���鼮��ţ�");
            scanf("%d",&num);
            BookList *p = BL;
            while(p)
            {
                if(p->book.num==book_num)
                    break;
                p = p->next;
            }
            p->book.num = num;
            return BL;
        }
        else if(book_modify==2)
        {
            char name[30];
            printf("�������޸ĺ���鼮���ƣ�");
            scanf("%s",name);
            BookList *p = BL;
            while(p)
            {
                if(p->book.num==book_num)
                    break;
                p = p->next;
            }
            strcpy(p->book.name,name);
            return BL;
        }
        else if(book_modify==3)
        {
            char author[30];
            printf("�������޸ĺ���鼮�������ƣ�");
            scanf("%s",author);
            BookList *p = BL;
            while(p)
            {
                if(p->book.num==book_num)
                    break;
                p = p->next;
            }
            strcpy(p->book.author,author);
            return BL;
        }
        else if(book_modify==4)
        {
            char publish[30];
            printf("�������޸ĺ�ĳ��������ƣ�");
            scanf("%s",publish);
            BookList *p = BL;
            while(p)
            {
                if(p->book.num==book_num)
                    break;
                p = p->next;
            }
            strcpy(p->book.publish,publish);
            return BL;
        }
        else if(book_modify==5)
        {
            char date[30];
            printf("�������޸ĺ���鼮����ʱ�䣺");
            scanf("%s",date);
            BookList *p = BL;
            while(p)
            {
                if(p->book.num==book_num)
                    break;
                p = p->next;
            }
            strcpy(p->book.date,date);
            return BL;
        }
        else if(book_modify==6)
        {
            double price;
            printf("�������޸ĺ���鼮�۸�");
            scanf("%lf",price);
            BookList *p = BL;
            while(p)
            {
                if(p->book.num==book_num)
                    break;
                p = p->next;
            }
            p->book.price = price;
            return BL;
        }
    }
}

void update_book(BookList *BL)
{
    FILE *fp;
    Book book;
    BookList *p = BL;
    if((fp=fopen("book.txt","w"))==NULL)
    {
        printf("cannot open book.txt file!");
        exit(0);
    }
    while(p)
    {
        book.num = p->book.num;
        strcpy(book.name,p->book.name);
        strcpy(book.author,p->book.author);
        strcpy(book.publish,p->book.publish);
        strcpy(book.date,p->book.date);
        book.price = p->book.price;
        fprintf(fp,"%-5d %-26s %-10s %-20s %-10s %-10.1lf\n",book.num,book.name,book.author,book.publish,
                book.date,book.price);
        p = p->next;
    }
    fclose(fp);
}

int main()
{
    admin_init();
    user_init();
    book_init();
    while(1)
    {
        int main_num;
        main_menu();
        printf("������ϵͳ���ܱ�ţ�");
        scanf("%d",&main_num);
        if(main_num==1)
        {
            if(admin_validate()==1)
            {
                while(1)
                {
                    int admin_num;
                    admin_menu();
                    printf("�����빦�ܱ�ţ�");
                    scanf("%d",&admin_num);
                    if(admin_num==1)
                    {
                        while(1) //�鼮����
                        {
                            admin_book_menu();
                            int book;
                            printf("�����빦�ܱ�ţ�");
                            scanf("%d",&book);
                            if(book==1) //�����鼮
                                book_list = add_book(book_list);
                            else if(book==2) //ɾ���鼮
                            {
                                book_list = del_book(book_list);
                                update_book(book_list);
                            }
                            else if(book==3) //�鼮��ѯ
                            {
                                while(1)
                                {
                                    admin_book_search_menu();
                                    int book_search;
                                    printf("�����빦�ܱ�ţ�");
                                    scanf("%d",&book_search);
                                    if(book_search==1)
                                        print_book(book_list);
                                    else if(book_search==2)
                                        search_book_num(book_list);
                                    else if(book_search==3)
                                        search_book_name(book_list);
                                    else if(book_search==4)
                                        search_book_author(book_list);
                                    else if(book_search==5)
                                        search_book_publish(book_list);
                                    else if(book_search==6)
                                        search_book_date(book_list);
                                    else if(book_search==7)
                                        search_book_price(book_list);
                                    else if(book_search==8)
                                        break;
                                    system("pause");
                                    system("cls");
                                }
                            }
                            else if(book==4) //�鼮�޸�
                            {
                                book_list = modify_book(book_list);
                                update_book(book_list);
                            }
                            else if(book==5) //�鼮��ʾ
                                print_book(book_list);
                            //�˻���һ��
                            else if(book==6)
                                break;
                            system("pause");
                            system("cls");
                        }
                    }
                    else if(admin_num==2)
                    {
                        while(1) //�û�����
                        {
                            admin_user_menu();
                            int user;
                            printf("�����빦�ܱ�ţ�");
                            scanf("%d",&user);
                            if(user==1)
                            {
                                user_list = del_user(user_list);
                                update_user(user_list);
                            }
                            else if(user==2)
                            {
                                user_list = modify_user(user_list);
                                update_user(user_list);
                            }
                            else if(user==3)
                            {
                                char name[30];
                                printf("������Ҫ��ѯ���û�����");
                                scanf("%s",name);
                                UserList *p = search_user(user_list,name);
                                if(p == NULL)
                                    printf("�û�%s�����ڣ�",name);
                                else
                                {
                                    printf("��ѯ�ɹ���\n");
                                    printf("%-10s %-10s\n\n",p->user.user_name,p->user.user_pass);
                                }
                            }
                            else if(user==4)
                                print_user(user_list);
                            else if(user==5||user==6)
                                break;
                            system("pause");
                            system("cls");
                        }
                    }
                    else if(admin_num==3)
                        print_admin(admin_list);
                    else if(admin_num==4)
                        break;
                }
            }
        }
        else if(main_num==2)
        {
            if(user_validate()==1)
            {
                while(1)
                {
                    int num3;
                    user_menu();
                    printf("�����빦�ܱ�ţ�");
                    scanf("%d",&num3);
                    if(num3==1)
                        print_book(book_list);
                    else if(num3==2)
                        search_book_num(book_list);
                    else if(num3==3)
                        search_book_name(book_list);
                    else if(num3==4)
                        search_book_author(book_list);
                    else if(num3==5)
                        search_book_publish(book_list);
                    else if(num3==6)
                        search_book_date(book_list);
                    else if(num3==7)
                        search_book_price(book_list);
                    else if(num3==8)
                        break;
                    system("pause");
                    system("cls");
                }
            }
        }
        else if(main_num==3)
        {
            user_list = add_user(user_list);
        }
        system("pause");
        system("cls");
    }
    return 0;
}
