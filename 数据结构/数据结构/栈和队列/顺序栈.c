#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100

typedef int ElemType;
typedef struct sequence_stack
{
    ElemType array[MAXSIZE];
    int top;
}seqStack;

//������ջ
seqStack* Create()
{
    seqStack *stk = (seqStack*)malloc(sizeof(seqStack));
    stk->top = -1;
    return stk;
}

//��ջ����
void Push(seqStack *stack,int elem)
{
    stack->top++;
    stack->array[stack->top] = elem;
}

//��ջ����
void Pop(seqStack *stack,int *elem)
{
    *elem = stack->array[stack->top];
    stack->top--;
}

//����ջ
void Destory(seqStack *stack)
{
    free(stack);
}

//������
int main()
{
    seqStack *stack;
    stack = Create();
    int elem_in = 11;
    int elem_out;
    //��ջ
    Push(stack,elem_in);
    //��ջ
    Pop(stack,&elem_out);
    //ѭ����ջ/����
    int temp;
    while(stack->top>=0)
    {
        printf("%d\n",stack->array[stack->top]);
        Pop(stack,&temp); //Ԫ�س�ջ��top--
    }
    Destory(stack);
    return 0;
}
