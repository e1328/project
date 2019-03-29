#include<stdio.h>
#include<stdlib.h>

//��ʽջ����
typedef int ElemType;
typedef struct stack_node
{
    ElemType data;
    struct stack_node *next;
}SNode,*stackNode;

typedef struct link_list_stack
{
    SNode *top;
    SNode *bottom;
    int count;
}LinkStack;

//��ʽջ��ʼ��
void StackInit(LinkStack *stack)
{
    if((stack->top = (SNode*)malloc(sizeof(SNode))) == NULL)
    {
        printf("��̬�ڴ����ʧ��!\n");
        return;
    }
    stack->bottom = stack->top;
    stack->top->next = NULL;
    stack->count = 0;
}

//�ж�ջ�Ƿ�Ϊ��
int IsEmpty(LinkStack *stack)
{
    if(stack->top == stack->bottom) //���߰�stack->count���ж�
        return 1;
    return 0;
}

//Ԫ����ջ
void Push(LinkStack *stack,int elem)
{
    //����ռ�
    SNode *newNode = (SNode*)malloc(sizeof(SNode));
    newNode->data = elem;
    //push��ջ��
    newNode->next = stack->top;
    stack->top = newNode; //�ȡ�
    stack->count++; //�󡣽�ջ�ڵ㡰��������
}

//��ջ��Ԫ�ش洢��valueָ����
void Pop(LinkStack *stack,int *value)
{
    if(IsEmpty(stack))
    {
        printf("stack is empty\n");
        return;
    }
    //��ȡ���
    SNode *tempNode = (SNode*)malloc(sizeof(SNode));
    tempNode = stack->top;
    *value = tempNode->data;
    //ջָ��䶯
    stack->top = tempNode->next;
    stack->count--;
    //�ͷ�ջ���
    free(tempNode); //˵������������Ԫ��ʱ��ջ��ָ��õ����£�ָ���µĽڵ�
    tempNode = NULL;
}

//ջ����
void StackTraverse(LinkStack *stack)
{
    //���ɨ��
    SNode *nodeScan = stack->top;
    //�������
    while(nodeScan != stack->bottom)
    {
        printf("%d ",nodeScan->data);
        nodeScan = nodeScan->next; //Ԫ����ջ�����У��ѽ��ڵ����Ρ��������������Կ��Է������
    }
    printf("\n");
    return;
}

//��ջ�ĳ���
int StackLength(LinkStack *stack)
{
    return stack->count;
}

//���/����ջ
void EmptyStack(LinkStack *stack)
{
    if(IsEmpty(stack))
        return;
    SNode *nodeScan = stack->top;
    SNode *tempNode = (SNode*)malloc(sizeof(SNode));
    tempNode = NULL;
    while(nodeScan != stack->bottom) //��count != 0
    {
        tempNode = nodeScan->next;
        free(nodeScan);
        nodeScan = tempNode;
        stack->count--;
    }
    stack->top = stack->bottom;
}

int main()
{
    //��ʽջ��������ʼ��
    LinkStack *stack = (LinkStack*)malloc(sizeof(LinkStack)); //�ǵ�Ϊ��ʽջ����ռ�
    StackInit(stack);
    int i;
    for(i=0;i<10;i++) //��ջ��ѹ��10��Ԫ��
    {
        Push(stack,i+1);
    }
    //�ж�ջ�Ƿ�Ϊ��
    IsEmpty(stack);
    //ջ����
    StackTraverse(stack);
    //ȡ����ɾ��ջ��Ԫ��
    int value;
    Pop(stack,&value);
    //���/����ջ
    EmptyStack(stack);
    return 0;
}
