#include<stdio.h>
#include<stdlib.h>

//1. ��ʽ���еĶ���
//���н��
typedef struct queue_node
{
    int data; //������
    struct queue_node *next; //ָ����
}queueNode,*queNode;

//����
typedef struct queue
{
    queNode front; //��ͷָ��
    queNode rear; //��βָ��
    int nodeNum; //�ڵ����,����Ҫ
}queue,*Queue;

//2. ���еĳ�ʼ��
void InitQue(queue *que)
{
    que->front = que->rear = NULL;
    que->nodeNum = 0;
}

//����
int InitQue(queue *que)
{
    que->front = que->rear = (Queue)malloc(sizeof(queue));
    que->nodeNum = 0;
    if(!que->front)
        return -1;
    que->front->next = NULL;
    return 1;
}

//3. �ж϶����Ƿ�Ϊ��
int IsEmpty(queue *que)
{
    if(que->front == NULL && que->rear == NULL && que->nodeNum == 0)
        return 1;
    else
        return 0;
}

//4. ��ն���
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

//5. ���б���
int QueueTraverse(queue *que)
{
    if(que->front == NULL && que->rear == NULL)  //������que -> front == que -> rear
    {
        printf("����Ϊ��\n");
            return -1;
    }
    queue *temp = que->front;
    while(temp != que->rear)
    {
        temp = temp->next; //ָ����һ���ڵ�
        printf("%d ",temp->data);
    }
    return 1;
}

//6. ��ȡ���д�С
int QueueSize(queue *que)
{
    return que->nodeNum;
}

//7. Ԫ�����
int AddItem2Queue(queue *que,int x)
{
    //����������
    queNode temp = (queNode)malloc(sizeof(queueNode));
    if(!temp)
        return 1;
    temp->next = NULL;
    temp->data = x;
    //Ԫ�����
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

//8. Ԫ�س���
//��ȡԪ�ص���ɾ���ڵ�
int ReadItemFromQueue(queue *que)
{
     if (que -> front == que -> rear)
     {
         printf("����Ϊ��");
         return -1;
     }
     return que -> front -> data;
}
//��ȡԪ����ɾ�����
int ReadItemFromQueue(queue *que)
{
    if(que->front == que->rear)
    {
        printf("����Ϊ��\n");
        return -1;
    }
    queNode temp = (queNode)malloc(sizeof(queueNode));
    temp = que->front;
    int x = temp->data;
    que->front = temp->next;
    que->nodeNum--;
    if(que->rear == temp) //ֻ��һ�����
        que->rear = NULL;
    free(temp);
    return x;
}
