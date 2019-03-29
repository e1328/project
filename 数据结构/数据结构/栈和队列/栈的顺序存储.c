#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100

typedef struct
{
    int data[MAXSIZE];
    int top;
}seqStack;

seqStack* Create()
{
    seqStack *stk = (seqStack*)malloc(sizeof(seqStack));
    stk->top = -1;
    return stk;
}

void Push(seqStack *stack,int x)
{
    stack->top++;
    stack->data[stack->top] = x;
}

void Pop(seqStack *stack,int *x)
{
    *x = stack->data[stack->top];
    stack->top--;
}

void Destory(seqStack *stack)
{
    free(stack);
}

int main()
{
    seqStack *stack;
    stack = Create();
    int elem_in = 10;
    int elem_out;
    Push(stack,elem_in);
    Pop(stack,&elem_out);
    int temp;
    while(stack->top>=0)
    {
        printf("%d ",stack->data[stack->top]);
        Pop(stack,&temp);
    }
    Destory(stack);
    return 0;
}
