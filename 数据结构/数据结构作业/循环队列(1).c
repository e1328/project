#include<stdio.h>
#include<stdlib.h>

#define MAX 100

typedef struct
{
    char name[20];
    char gender;
}Person;

typedef struct
{
    Person data[MAX];
    int front;
    int rear;
}Queue;

void init(Queue *q)
{
    q->front=0;
    q->rear=0;
}

int add(Queue *q,Person p)
{
    if((q->rear+1)%MAX==q->front)
        return 0;
    q->data[q->rear]=p;
    q->rear=(q->rear+1)%MAX;
    return 1;
}

Person* del(Queue *q)
{
    Person *p;
    if(q->front==q->rear)
        return NULL;
    *p=q->data[q->front];
    q->front=(q->front+1)%MAX;
    return p;
}

void main()
{
    Queue *q1=(Queue*)malloc(sizeof(Queue));
    Queue *q2=(Queue*)malloc(sizeof(Queue));
    init(q1);
    init(q2);
    int a,b,k,i;
    scanf("%d %d",&a,&b);
    if(a>b)
        k=b-1;
    else if(a<b)
        k=a-1;
    Person m[a],w[b];
    for(i=0;i<a;i++)
    {
        scanf("%s %c",m[i].name,&m[i].gender);
        add(q1,m[i]);
    }
    for(i=0;i<b;i++)
    {
        scanf("%s %c",w[i].name,&w[i].gender);
        add(q2,w[i]);
    }
    //printf("%d %d\n",q1->front,q1->rear);
    //for(i=q1->front;i<q1->rear;i++)
    //    printf("%s\n",q1->data[i].name);
    Person *p1,*p2;
    /*int n=1;
    while(1)
    {
        p1=del(q1);
        p2=del(q2);
        if(p1!=NULL&&p2!=NULL)
        {
            printf("%s %s\n",(*p1).name,(*p2).name);
            add(q1,(*p1));
            add(q2,(*p2));
            n++;
        }
        if(n==3)
            break;
    }*/
    p1=del(q1);
    printf("%s %c\n",(*p1).name,(*p1).gender);
}
