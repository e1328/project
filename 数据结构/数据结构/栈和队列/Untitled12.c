#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100

typedef struct
{
    int data[MAXSIZE];
    int front;
    int rear;
}SqQueue;

void initQueue(SqQueue *q)
{
    q->front=0;
    q->rear=0;
}

int insertQueue(SqQueue *q,int x)
{
    if((q->rear+1)%MAXSIZE==q->front)
        return 0;
    q->data[q->rear]=x;
    q->rear=(q->rear+1)%MAXSIZE;
    return 1;
}

int deleteQueue(SqQueue *q,int *x)
{
    if(q->front==q->rear)
        return 0;
    *x=q->data[q->front];
    q->front=(q->front+1)%MAXSIZE;
    return 1;
}

int lengthQueue(SqQueue *q)
{
    return q->rear-q->front;
}

void main()
{
    int x,i;
    SqQueue *q = (SqQueue*)malloc(sizeof(SqQueue));
    initQueue(q);
    insertQueue(q,12);
    insertQueue(q,34);
    insertQueue(q,56);
    printf("%d\n",lengthQueue(q));
    for(i=q->front;i<q->rear;i++)
        printf("%d ",q->data[i]);
    printf("\n");
    deleteQueue(q,&x);
    deleteQueue(q,&x);
    for(i=q->front;i<q->rear;i++)
        printf("%d ",q->data[i]);
}
