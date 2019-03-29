#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//管理员
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

//用户
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

//图书
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
    printf("+--------------------------------------------+\n");
    printf("|           图书馆书籍分类查询系统           |\n");
    printf("|                                            |\n");
    printf("|       1--管理员登录      2--用户登录       |\n");
    printf("|                                            |\n");
    printf("|       3--用户注册        4--系统介绍       |\n");
    printf("|                                            |\n");
    printf("|       5--系统退出        6--系统退出       |\n");
    printf("+--------------------------------------------+\n");
}

void admin_menu()
{
    printf("+--------------------------------------------+\n");
    printf("|                 管理员界面                 |\n");
    printf("|                                            |\n");
    printf("|       1--书籍管理        2--用户管理       |\n");
    printf("|                                            |\n");
    printf("|       3--管理员显示      4--退出登录       |\n");
    printf("+--------------------------------------------+\n");
}

void admin_book_menu()
{
    printf("+--------------------------------------------+\n");
    printf("|                 书籍管理界面               |\n");
    printf("|                                            |\n");
    printf("|       1--书籍增加        2--书籍删除       |\n");
    printf("|                                            |\n");
    printf("|       3--书籍查询        4--书籍修改       |\n");
    printf("|                                            |\n");
    printf("|       5--书籍显示        6--退回上一级     |\n");
    printf("+--------------------------------------------+\n");
}

void admin_book_search_menu()
{
    printf("+-------------------------------------------------+\n");
    printf("|                   书籍查询界面                  |\n");
    printf("|                                                 |\n");
    printf("|       1--书籍显示        2--按书籍编号查询      |\n");
    printf("|                                                 |\n");
    printf("|       3--按书名查询      4--按书籍作者查询      |\n");
    printf("|                                                 |\n");
    printf("|       5--按出版社查询    6--按出版日期查询      |\n");
    printf("|                                                 |\n");
    printf("|       7--按价格查询      8--退回上一级          |\n");
    printf("+-------------------------------------------------+\n");
}

void admin_book_modify_menu()
{
    printf("+-----------------------------------------------------+\n");
    printf("|                    书籍修改界面                     |\n");
    printf("|                                                     |\n");
    printf("|       1--修改书籍编号        2--修改书籍名称        |\n");
    printf("|                                                     |\n");
    printf("|       3--修改书籍作者        4--修改出版社名称      |\n");
    printf("|                                                     |\n");
    printf("|       5--修改出版日期        6--修改书籍价格        |\n");
    printf("+-----------------------------------------------------+\n");
}

void admin_user_menu()
{
    printf("+--------------------------------------------+\n");
    printf("|                 用户管理界面               |\n");
    printf("|                                            |\n");
    printf("|       1--删除用户        2--修改用户       |\n");
    printf("|                                            |\n");
    printf("|       3--查询用户        4--显示所有用户   |\n");
    printf("|                                            |\n");
    printf("|       5--退回上一级      6--退回上一级     |\n");
    printf("+--------------------------------------------+\n");
}

void user_menu()
{
    printf("+-------------------------------------------------+\n");
    printf("|                  用户界面                       |\n");
    printf("|                                                 |\n");
    printf("|       1--书籍显示        2--按书籍编号查询      |\n");
    printf("|                                                 |\n");
    printf("|       3--按书名查询      4--按书籍作者查询      |\n");
    printf("|                                                 |\n");
    printf("|       5--按出版社查询    6--按出版日期查询      |\n");
    printf("|                                                 |\n");
    printf("|       7--按价格查询      8--退出登录            |\n");
    printf("+-------------------------------------------------+\n");
}

void book_show_menu()
{
    printf("+------------------------------------------------------------+\n");
    printf("|                        书籍显示界面                        |\n");
    printf("|                                                            |\n");
    printf("|         1--价格升序显示         2--价格降序显示            |\n");
    printf("|                                                            |\n");
    printf("|         3--出版时间升序显示     4--出版时间降序显示        |\n");
    printf("|                                                            |\n");
    printf("|         5--普通显示             6--退回上一级              |\n");
    printf("+------------------------------------------------------------+\n");
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
    printf("+-------------+--------------+\n");
    printf("|   账号      |      密码    |\n");
    printf("+-------------+--------------+\n");
    while(p)
    {
        printf("|  %-10s |%10s    |   \n",p->admin.admin_name,p->admin.admin_pass);
        p = p->next;
    }
    printf("+-------------+--------------+\n");
}

int admin_validate()
{
    char name[30];
    char pass[30];
    printf("请输入管理员账号：");
    scanf("%s",name);
    printf("请输入管理员密码：");
    scanf("%s",pass);
    AdminList *p = admin_list;
    while(p)
    {
        if(strcmp(p->admin.admin_name,name)==0&&(strcmp(p->admin.admin_pass,pass)==0))
        {
            printf("欢迎管理员 %s 登录系统！\n",name);
            system("pause");
            return 1;
        }
        p = p->next;
    }
    printf("管理员账号或密码有误！\n");
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
    printf("+-------------+--------------+\n");
    printf("|   账号      |      密码    |\n");
    printf("+-------------+--------------+\n");
    while(p)
    {
        printf("| %-10s  | %10s   |\n",p->user.user_name,p->user.user_pass);
        p = p->next;
    }
    printf("+-------------+--------------+\n");
}

int user_validate()
{
    char name[30];
    char pass[30];
    printf("请输入用户账号：");
    scanf("%s",name);
    printf("请输入用户密码：");
    scanf("%s",pass);
    UserList *p = user_list;
    while(p)
    {
        if(strcmp(p->user.user_name,name)==0&&(strcmp(p->user.user_pass,pass)==0))
        {
            printf("欢迎用户 %s 登录系统！\n",name);
            system("pause");
            return 1;
        }
        p = p->next;
    }
    printf("用户账号或密码有误！\n");
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
    printf("请输入要注册的用户账号：");
    scanf("%s",name);
    printf("请输入要注册的用户密码：");
    scanf("%s",pass);
    if(search_user(UL,name)!=NULL)
    {
        printf("该用户已经存在！\n");
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
        fprintf(fp,"\n  %-20s    %-8s",user.user_name,user.user_pass);
        fclose(fp);
        printf("注册用户成功！\n");
        return UL;
    }
}

UserList* del_user(UserList *UL)
{
    char name[30];
    printf("请输入要删除的用户名：");
    scanf("%s",name);
    if(search_user(UL,name)==NULL)
    {
        printf("该用户不存在！\n");
        return UL;
    }
    else
    {
        UserList *p = UL,*q;
        if(strcmp(p->user.user_name,name)==0)
        {
            q = p;
            p = p->next;
            free(q);
            printf("删除用户成功！\n");
            return p;
        }
        else
        {
            while(p)
            {
                if(strcmp(p->next->user.user_name,name)==0)
                    break;
                p = p->next;
            }
            q = p->next;
            p->next = q->next;
            free(q);
            printf("删除用户成功！\n");
            return UL;
        }
    }
}

UserList* modify_user(UserList *UL)
{
    char name[30],pass[30];
    printf("请输入要修改的用户名：");
    scanf("%s",name);
    if(search_user(UL,name)==NULL)
    {
        printf("该用户不存在！\n");
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
        printf("请输入修改后的用户名：");
        scanf("%s",name);
        printf("请输入修改后的用户密码：");
        scanf("%s",pass);
        strcpy(p->user.user_name,name);
        strcpy(p->user.user_pass,pass);
        printf("修改用户成功！\n");
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
        fprintf(fp,"  %-20s    %-8s\n",user.user_name,user.user_pass);
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
    printf("+---------+-------------------------+------------+-------------------+-------------+----------------+\n");
    printf("|  编号   |         名称            |    作者    |     出版社        |   出版日期  |     价格       |\n");
    printf("+---------+-------------------------+------------+-------------------+-------------+----------------+\n");
    while(p)
    {
        printf("|  %-5d  |%-25s| %-10s | %-17s | %-10s  |    %-10.1lf  |\n",p->book.num,p->book.name,
               p->book.author,p->book.publish,p->book.date,p->book.price);
        p = p->next;
    }
    printf("+---------+-------------------------+------------+-------------------+-------------+----------------+\n");
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
    printf("请输入要查询的书籍编号：");
    scanf("%d",&num);
    radixSort(book,k);//基数排序
    int flag = binary_search(book,k,num);
    if(flag==-1)
    {
        printf("没有查询到编号为%d的书籍！\n",num);
    }
    else
    {
        printf("查找成功！\n");
        printf("+---------+-------------------------+------------+-------------------+-------------+----------------+\n");
        printf("|  编号   |         名称            |    作者    |     出版社        |   出版日期  |     价格       |\n");
        printf("+---------+-------------------------+------------+-------------------+-------------+----------------+\n");
        printf("|  %-5d  |%-25s| %-10s | %-17s | %-10s  |    %-10.1lf  |\n",book[flag].num,book[flag].name,
               book[flag].author,book[flag].publish,book[flag].date,book[flag].price);
        printf("+---------+-------------------------+------------+-------------------+-------------+----------------+\n");
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
    radixSort(book,k);//基数排序
    int flag = binary_search(book,k,book_num);
    if(flag==-1)
        return 0;
    else
        return 1;
}

void search_book_name(BookList *BL)
{
    char name[30];
    printf("请输入要查询的书籍名称：");
    scanf("%s",name);
    BookList *p = BL;
    while(p)
    {
        if(strcmp(p->book.name,name)==0)
            break;
        p = p->next;
    }
    if(p==NULL)
        printf("没有查询到书名为%s的书籍！\n",name);
    else
    {
        printf("查询成功！\n");
        print_book(p);
    }
}

void search_book_author(BookList *BL)
{
    char author[30];
    printf("请输入要查询的书籍作者名称：");
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
        printf("没有查询到书籍作者为%s的书籍！\n",author);
    else
    {
        rear->next = NULL;
        printf("查询成功！\n");
        BookList *p = head;
        print_book(p);
    }
}

void search_book_publish(BookList *BL)
{
    char publish[30];
    printf("请输入要查询的出版社名称：");
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
        printf("没有查询到出版社为%s的书籍！\n",publish);
    else
    {
        rear->next = NULL;
        printf("查询成功！\n");
        BookList *p = head;
        print_book(p);
    }
}

void search_book_date(BookList *BL)
{
    char date[30];
    printf("请输入要查询的书籍出版日期：");
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
        printf("没有查询到书籍出版日期为%s的书籍！\n",date);
    else
    {
        rear->next = NULL;
        printf("查询成功！\n");
        BookList *p = head;
        print_book(p);
    }
}

void search_book_price(BookList *BL)
{
    double start,end;
    printf("请输入要查询书籍的最低价格：");
    scanf("%lf",&start);
    printf("请输入要查询书籍的最高价格：");
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
        printf("没有查询到书籍价格在 %.1lf ~ %.1lf 范围的书籍！\n",start,end);
    else
    {
        rear->next = NULL;
        printf("查询成功！\n");
        printf("书籍价格在 %.1lf ~ %.1lf 范围的书籍\n",start,end);
        BookList *p = head;
        print_book(p);
    }
}

BookList *add_book(BookList *BL)
{
    Book book;
    printf("请输入要增加的书籍编号：");
    scanf("%d",&book.num);
    printf("请输入要增加的书籍名称：");
    scanf("%s",book.name);
    printf("请输入要增加的书籍作者：");
    scanf("%s",book.author);
    printf("请输入要增加的书籍出版社名称：");
    scanf("%s",book.publish);
    printf("请输入要增加的书籍出版时间：");
    scanf("%s",book.date);
    printf("请输入要增加的书籍价格：");
    scanf("%lf",&book.price);
    if(search_book_num2(BL,book.num)==1)
    {
        printf("该书籍已经存在！\n");
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
        fprintf(fp,"\n  %-5d      %-26s %-10s   %-20s  %-10s     %-10.1lf ",book.num,book.name,book.author,book.publish,book.date,
                book.price);
        fclose(fp);
        printf("增加书籍成功！\n");
        return BL;
    }
}

BookList *del_book(BookList *BL)
{
    int num;
    printf("请输入要删除的书籍编号：");
    scanf("%d",&num);
    if(search_book_num2(BL,num)==0)
    {
        printf("该书籍不存在！\n");
        return BL;
    }
    else
    {
        BookList *p = BL,*q;
        if(p->book.num==num)
        {
            q = p;
            p = p->next;
            free(q);
            printf("删除书籍成功！\n");
            return p;
        }
        else
        {
            while(p)
            {
                if(p->next->book.num==num)
                    break;
                p = p->next;
            }
            q = p->next;
            p->next = q->next;
            free(q);
            printf("删除书籍成功！\n");
            return BL;
        }
    }
}

BookList *modify_book(BookList *BL)
{
    char book_name[30];
    printf("请通过关键字查询要修改的书籍的名称：");
    scanf("%s",book_name);
    BookList *p = BL;
    BookList *head,*rear,*q;
    head = NULL;
    rear = NULL;
    while(p)
    {
        if(strstr(p->book.name,book_name))
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
    if(head==NULL)
    {
        printf("没有查询到书名包含“%s”关键字的书籍！\n",book_name);
        return BL;
    }
    else
    {
        rear->next = NULL;
        system("cls");
        printf("通过关键字“%s”查询书籍成功！\n",book_name);
        print_book(head);
        int book_num;
        printf("请输入你要修改的书籍编号：");
        scanf("%d",&book_num);
        while(head)
        {
            if(head->book.num==book_num)
                break;
            head = head->next;
        }
        if(head==NULL)
        {
            printf("书籍编号为 %d 的书籍不存在！\n",book_num);
            return BL;
        }
        else
        {
            system("cls");
            int book_modify;
            admin_book_modify_menu();
            printf("请输入功能编号：");
            scanf("%d",&book_modify);
            if(book_modify==1)
            {
                int num;
                printf("请输入修改后的书籍编号：");
                scanf("%d",&num);
                if(search_book_num2(BL,num)==1)
                {
                    printf("书籍编号重复，不能修改！\n");
                    return BL;
                }
                else
                {
                    BookList *p = BL;
                    while(p)
                    {
                        if(p->book.num==book_num)
                            break;
                        p = p->next;
                    }
                    p->book.num = num;
                    printf("修改书籍编号成功！\n");
                    return BL;
                }
            }
            else if(book_modify==2)
            {
                char name[30];
                printf("请输入修改后的书籍名称：");
                scanf("%s",name);
                BookList *p = BL;
                while(p)
                {
                    if(p->book.num==book_num)
                        break;
                    p = p->next;
                }
                strcpy(p->book.name,name);
                printf("修改书籍名称成功！\n");
                return BL;
            }
            else if(book_modify==3)
            {
                char author[30];
                printf("请输入修改后的书籍作者名称：");
                scanf("%s",author);
                BookList *p = BL;
                while(p)
                {
                    if(p->book.num==book_num)
                        break;
                    p = p->next;
                }
                strcpy(p->book.author,author);
                printf("修改书籍作者成功！\n");
                return BL;
            }
            else if(book_modify==4)
            {
                char publish[30];
                printf("请输入修改后的出版社名称：");
                scanf("%s",publish);
                BookList *p = BL;
                while(p)
                {
                    if(p->book.num==book_num)
                        break;
                    p = p->next;
                }
                strcpy(p->book.publish,publish);
                printf("修改书籍出版社成功！\n");
                return BL;
            }
            else if(book_modify==5)
            {
                char date[30];
                printf("请输入修改后的书籍出版时间：");
                scanf("%s",date);
                BookList *p = BL;
                while(p)
                {
                    if(p->book.num==book_num)
                        break;
                    p = p->next;
                }
                strcpy(p->book.date,date);
                printf("修改书籍出版时间成功！\n");
                return BL;
            }
            else if(book_modify==6)
            {
                double price;
                printf("请输入修改后的书籍价格：");
                scanf("%lf",price);
                BookList *p = BL;
                while(p)
                {
                    if(p->book.num==book_num)
                        break;
                    p = p->next;
                }
                p->book.price = price;
                printf("修改书籍价格成功！\n");
                return BL;
            }
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
        fprintf(fp,"  %-5d      %-26s %-10s   %-20s  %-10s     %-10.1lf \n",book.num,book.name,book.author,book.publish,
                book.date,book.price);
        p = p->next;
    }
    fclose(fp);
}

int book_amount(BookList *BL)
{
    BookList *p = BL;
    int index = 0;
    while(p)
    {
        index++;
        p = p->next;
    }
    return index;
}

void show_book_price_up(BookList *BL)
{
    int i,j,n = book_amount(BL);
    BookList *p,*q;
    Book book;
    for(i=0;i<n-1;i++)
    {
        p = BL;
        for(j=0;j<n-1-i;j++)
        {
            q = p->next;
            if(p->book.price>q->book.price)
            {
                book.num = p->book.num;
                strcpy(book.name,p->book.name);
                strcpy(book.author,p->book.author);
                strcpy(book.publish,p->book.publish);
                strcpy(book.date,p->book.date);
                book.price = p->book.price;
                p->book.num = q->book.num;
                strcpy(p->book.name,q->book.name);
                strcpy(p->book.author,q->book.author);
                strcpy(p->book.publish,q->book.publish);
                strcpy(p->book.date,q->book.date);
                p->book.price = q->book.price;
                q->book.num = book.num;
                strcpy(q->book.name,book.name);
                strcpy(q->book.author,book.author);
                strcpy(q->book.publish,book.publish);
                strcpy(q->book.date,book.date);
                q->book.price = book.price;
            }
            p = p->next;
        }
    }
    print_book(BL);
}

void show_book_price_down(BookList *BL)
{
    int i,j,n = book_amount(BL);
    BookList *p,*q;
    Book book;
    for(i=0;i<n-1;i++)
    {
        p = BL;
        for(j=0;j<n-1-i;j++)
        {
            q = p->next;
            if(p->book.price<q->book.price)
            {
                book.num = p->book.num;
                strcpy(book.name,p->book.name);
                strcpy(book.author,p->book.author);
                strcpy(book.publish,p->book.publish);
                strcpy(book.date,p->book.date);
                book.price = p->book.price;
                p->book.num = q->book.num;
                strcpy(p->book.name,q->book.name);
                strcpy(p->book.author,q->book.author);
                strcpy(p->book.publish,q->book.publish);
                strcpy(p->book.date,q->book.date);
                p->book.price = q->book.price;
                q->book.num = book.num;
                strcpy(q->book.name,book.name);
                strcpy(q->book.author,book.author);
                strcpy(q->book.publish,book.publish);
                strcpy(q->book.date,book.date);
                q->book.price = book.price;
            }
            p = p->next;
        }
    }
    print_book(BL);
}

void show_book_date_up(BookList *BL)
{
    int i,j,n = book_amount(BL);
    BookList *p,*q;
    Book book;
    for(i=0;i<n-1;i++)
    {
        p = BL;
        for(j=0;j<n-1-i;j++)
        {
            q = p->next;
            if(strcmp(p->book.date,q->book.date)>0)
            {
                book.num = p->book.num;
                strcpy(book.name,p->book.name);
                strcpy(book.author,p->book.author);
                strcpy(book.publish,p->book.publish);
                strcpy(book.date,p->book.date);
                book.price = p->book.price;
                p->book.num = q->book.num;
                strcpy(p->book.name,q->book.name);
                strcpy(p->book.author,q->book.author);
                strcpy(p->book.publish,q->book.publish);
                strcpy(p->book.date,q->book.date);
                p->book.price = q->book.price;
                q->book.num = book.num;
                strcpy(q->book.name,book.name);
                strcpy(q->book.author,book.author);
                strcpy(q->book.publish,book.publish);
                strcpy(q->book.date,book.date);
                q->book.price = book.price;
            }
            p = p->next;
        }
    }
    print_book(BL);
}

void show_book_date_down(BookList *BL)
{
    int i,j,n = book_amount(BL);
    BookList *p,*q;
    Book book;
    for(i=0;i<n-1;i++)
    {
        p = BL;
        for(j=0;j<n-1-i;j++)
        {
            q = p->next;
            if(strcmp(p->book.date,q->book.date)<0)
            {
                book.num = p->book.num;
                strcpy(book.name,p->book.name);
                strcpy(book.author,p->book.author);
                strcpy(book.publish,p->book.publish);
                strcpy(book.date,p->book.date);
                book.price = p->book.price;
                p->book.num = q->book.num;
                strcpy(p->book.name,q->book.name);
                strcpy(p->book.author,q->book.author);
                strcpy(p->book.publish,q->book.publish);
                strcpy(p->book.date,q->book.date);
                p->book.price = q->book.price;
                q->book.num = book.num;
                strcpy(q->book.name,book.name);
                strcpy(q->book.author,book.author);
                strcpy(q->book.publish,book.publish);
                strcpy(q->book.date,book.date);
                q->book.price = book.price;
            }
            p = p->next;
        }
    }
    print_book(BL);
}

void show_book(BookList *BL)
{
    system("cls");
    while(1)
    {
        book_show_menu();
        int book_show;
        printf("请输入功能编号：");
        scanf("%d",&book_show);
        if(book_show==1)
        {
            show_book_price_up(BL);
            book_init();
        }
        else if(book_show==2)
        {
            show_book_price_down(BL);
            book_init();
        }
        else if(book_show==3)
        {
            show_book_date_up(BL);
            book_init();
        }
        else if(book_show==4)
        {
            show_book_date_down(BL);
            book_init();
        }
        else if(book_show==5)
            print_book(BL);
        else if(book_show==6)
            break;
        system("pause");
        system("cls");
    }
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
        printf("请输入系统功能编号：");
        scanf("%d",&main_num);
        if(main_num==1)
        {
            if(admin_validate()==1)
            {
                system("cls");
                while(1)
                {
                    int admin_num;
                    admin_menu();
                    printf("请输入功能编号：");
                    scanf("%d",&admin_num);
                    if(admin_num==1)
                    {
                        system("cls");
                        while(1) //书籍管理
                        {
                            admin_book_menu();
                            int book;
                            printf("请输入功能编号：");
                            scanf("%d",&book);
                            if(book==1) //增加书籍
                                book_list = add_book(book_list);
                            else if(book==2) //删除书籍
                            {
                                book_list = del_book(book_list);
                                update_book(book_list);
                            }
                            else if(book==3) //书籍查询
                            {
                                while(1)
                                {
                                    admin_book_search_menu();
                                    int book_search;
                                    printf("请输入功能编号：");
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
                            else if(book==4) //书籍修改
                            {
                                book_list = modify_book(book_list);
                                update_book(book_list);
                            }
                            else if(book==5) //书籍显示
                                show_book(book_list);
                            else if(book==6) //退回上一级
                                break;
                            system("pause");
                            system("cls");
                        }
                    }
                    else if(admin_num==2)
                    {
                        system("cls");
                        while(1) //用户管理
                        {
                            admin_user_menu();
                            int user;
                            printf("请输入功能编号：");
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
                                printf("请输入要查询的用户名：");
                                scanf("%s",name);
                                UserList *p = search_user(user_list,name);
                                if(p == NULL)
                                    printf("用户%s不存在！\n",name);
                                else
                                {
                                    printf("查询成功！\n");
                                    print_user(p);
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
                    system("pause");
                    system("cls");
                }
            }
        }
        else if(main_num==2)
        {
            if(user_validate()==1)
            {
                system("cls");
                while(1)
                {
                    int num3;
                    user_menu();
                    printf("请输入功能编号：");
                    scanf("%d",&num3);
                    if(num3==1)
                        show_book(book_list);
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
            user_list = add_user(user_list);
        else if(main_num==4)
        {
            printf("+----------------------------------------------+\n");
            printf("|该系统主要是利用某本书的一些信息，通过其中的任|\n");
            printf("|意一个信息，找出我们所需要的查找的该本书的所有|\n");
            printf("|信息，采用基数排序法对一组具有结构特点的书籍编|\n");
            printf("|号进行排序，利用二分查找法对排序好的书籍记录按|\n");
            printf("|书籍编号实现快速查找，并按其他关键字的查找可以|\n");
            printf("|采用最简单的顺序查找方法进行。                |\n");
            printf("+----------------------------------------------+\n");
        }
        else if(main_num==5||main_num==6)
            break;
        system("pause");
        system("cls");
    }
    return 0;
}
