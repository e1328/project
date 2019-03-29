#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100

typedef int QElemType;
typedef struct
{
    QElemType data[MAXSIZE];
    int rear; //头指针
    int front; //尾指针，若队列不为空，指向队尾元素的下一个元素
}SqQueue;

int InitQueue(SqQueue *Q)
{
    Q->rear = 0;
    Q->front = 0;
    return 1;
}

int QueueLength(SqQueue *Q)
{
    return (Q.rear-Q.front+MAXSIZE) % MAXSIZE;
}

int insertQueue(SqQueue *Q,QElemType e)
{
    if((Q->rear+1)%MAXSIZE == Q->front)
        return -1;
    Q->data[Q->rear] = e;
    Q->rear = (Q->rear + 1) % MAXSIZE;
    return 1;
}

int deleteQueue(SqQueue *Q,QElemType *e)
{
    if(Q->rear == Q->front)
        return -1;
    *e = Q->data[Q->front];
    Q->front = (Q->front + 1) % MAXSIZE;
    return 1;
}
