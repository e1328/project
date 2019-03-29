#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100

typedef int ElemType;
typedef struct sequence_stack
{
    ElemType array[MAXSIZE];
    int top;
}seqStack;

//建立空栈
seqStack* Create()
{
    seqStack *stk = (seqStack*)malloc(sizeof(seqStack));
    stk->top = -1;
    return stk;
}

//入栈操作
void Push(seqStack *stack,int elem)
{
    stack->top++;
    stack->array[stack->top] = elem;
}

//出栈操作
void Pop(seqStack *stack,int *elem)
{
    *elem = stack->array[stack->top];
    stack->top--;
}

//销毁栈
void Destory(seqStack *stack)
{
    free(stack);
}

//主函数
int main()
{
    seqStack *stack;
    stack = Create();
    int elem_in = 11;
    int elem_out;
    //入栈
    Push(stack,elem_in);
    //出栈
    Pop(stack,&elem_out);
    //循环出栈/遍历
    int temp;
    while(stack->top>=0)
    {
        printf("%d\n",stack->array[stack->top]);
        Pop(stack,&temp); //元素出栈后top--
    }
    Destory(stack);
    return 0;
}
