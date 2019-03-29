#include<stdio.h>
#include<stdlib.h>

//1. 链式队列的定义
//队列结点
typedef struct queue_node
{
    int data; //数据域
    struct queue_node *next; //指针域
}queueNode,*queNode;

//队列
typedef struct queue
{
    queNode front; //队头指针
    queNode rear; //队尾指针
    int nodeNum; //节点计数,若需要
}queue,*Queue;

//2. 队列的初始化
void InitQue(queue *que)
{
    que->front = que->rear = NULL;
    que->nodeNum = 0;
}

//或者
int InitQue(queue *que)
{
    que->front = que->rear = (Queue)malloc(sizeof(queue));
    que->nodeNum = 0;
    if(!que->front)
        return -1;
    que->front->next = NULL;
    return 1;
}

//3. 判断队列是否为空
int IsEmpty(queue *que)
{
    if(que->front == NULL && que->rear == NULL && que->nodeNum == 0)
        return 1;
    else
        return 0;
}

//4. 清空队列
void EmptyQue(queue *que)
{
    queue *temp = que->front;
    while(temp != NULL)
    {
        que->front = que->front->next;
        free(temp);
        temp = que->front;
    }
}

//5. 队列遍历
int QueueTraverse(queue *que)
{
    if(que->front == NULL && que->rear == NULL)  //而不是que -> front == que -> rear
    {
        printf("队列为空\n");
            return -1;
    }
    queue *temp = que->front;
    while(temp != que->rear)
    {
        temp = temp->next; //指向下一个节点
        printf("%d ",temp->data);
    }
    return 1;
}

//6. 获取队列大小
int QueueSize(queue *que)
{
    return que->nodeNum;
}

//7. 元素入队
int AddItem2Queue(queue *que,int x)
{
    //定义操作结点
    queNode temp = (queNode)malloc(sizeof(queueNode));
    if(!temp)
        return 1;
    temp->next = NULL;
    temp->data = x;
    //元素入队
    if(IsEmpty(que))
    {
        que->front = que->rear = temp;
        que->nodeNum++;
    }
    else
    {
        que->rear->next = temp;
        que->rear = temp;
        que->nodeNum++;
    }
    return 0;
}

//8. 元素出队
//获取元素但不删除节点
int ReadItemFromQueue(queue *que)
{
     if (que -> front == que -> rear)
     {
         printf("队列为空");
         return -1;
     }
     return que -> front -> data;
}
//获取元素且删除结点
int ReadItemFromQueue(queue *que)
{
    if(que->front == que->rear)
    {
        printf("队列为空\n");
        return -1;
    }
    queNode temp = (queNode)malloc(sizeof(queueNode));
    temp = que->front;
    int x = temp->data;
    que->front = temp->next;
    que->nodeNum--;
    if(que->rear == temp) //只有一个结点
        que->rear = NULL;
    free(temp);
    return x;
}
