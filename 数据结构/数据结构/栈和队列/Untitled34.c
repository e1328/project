#include<stdio.h>
#include<stdlib.h>

typedef struct queueNode
{
    int data;
    struct queueNode *next;
}queueNode;

typedef struct queue
{
    queueNode *front;
    queueNode *rear;
    int nodeNum;
}queue;

void initQueue(queue *q)
{
    q->front=q->rear=NULL;
    q->nodeNum=0;
}

int isEmpty(queue *q)
{
    if(q->front==NULL&&q->rear==NULL)
        return 1;
    return 0;
}

void addQueue(queue *q,int x)
{
    queueNode *temp=(queueNode*)malloc(sizeof(queueNode));
    temp->next=NULL;
    temp->data=x;
    if(isEmpty(q))
    {
        q->front=q->rear=temp;
        q->nodeNum++;
    }
    else
    {
        q->rear->next=temp;
        q->rear=temp;
        q->nodeNum++;
    }
}

int Delqueue1(queue *q)
{
    if(q->front==q->rear)
        return -1;
    return q->front->data;
}

int Delqueue2(queue *q)
{
    if(q->front==q->rear&&q->nodeNum==0)
        return -1;
    queueNode *temp=(queueNode*)malloc(sizeof(queueNode));
    temp=q->front;
    int x=temp->data;
    q->front=temp->next;
    q->nodeNum--;
    if(q->rear==temp)
        q->rear=NULL;
    free(temp);
    return x;
}

void main()
{
    queue *q=(queue*)malloc(sizeof(queue));
    initQueue(q);
    addQueue(q,2);
    addQueue(q,4);
    addQueue(q,5);
    printf("%d\n",q->nodeNum);
    //printf("%d\n",isEmpty(q));
    printf("%d\n",Delqueue2(q));
    printf("%d\n",Delqueue2(q));
    printf("%d\n",Delqueue2(q));
}
