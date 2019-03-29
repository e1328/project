#include<stdio.h>
#include<stdlib.h>

typedef struct stack_node
{
    int data;
    struct stack_node *next;
}SNode,*stackNode;

typedef struct link_list_stack
{
    SNode *top;
    SNode *bottom;
    int count;
}LinkStack;

void StackInit(LinkStack *stack)
{
    if(stack->top = (SNode*)malloc(sizeof(SNode)) == NULL)
    {
        printf("¶¯Ì¬ÄÚ´æ·ÖÅäÊ§°Ü£¡\n");
        return;
    }
    stack->bottom = stack->top;
    stack->top->next = NULL;
    stack->count = 0;
}

int IsEmpty(LinkStack *stack)
{
    if(stack->top == stack->bottom)
        return 1;
    return 0;
}

void Push(LinkStack *stack,int x)
{
    SNode *newNode = (SNode*)malloc(sizeof(SNode));
    newNode->data = x;
    newNode->next = stack->top;
    stack->top = newNode;
    stack->count++;
}

void Pop(LinkStack *stack,int *x)
{
    if(IsEmpty())
    {
        printf("stack is empty\n");
        return;
    }
    SNode *tempNode = (SNode*)malloc(sizeof(SNode));
    tempNode = stack->top;
    *x = tempNode->data;
    stack->top = temp->next;
    stack->count--;
    free(tempNode);
    tempNode = NULL;
}

void StackTraverse(LinkStack *stack)
{
    SNode *nodeScan = stack->top;
    while(nodeScan != stack->bottom)
    {
        printf("%d ",nodeScan->data);
        nodeScan = nodeScan->next;
    }
    printf("\n");
    return;
}

int StackLength(LinkStack *stack)
{
    return stack->count;
}

void EmptyStack(LinkStack *stack)
{
    if(IsEmpty())
        return;
    SNode *nodeScan = stack->top;
    SNode *tempNode = (SNode*)malloc(sizeof(SNode));
    tempNode = NULL;
    while(nodeScan != stack->bottom)
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
    LinkStack *stack = (LinkStack*)malloc(sizeof(LinkStack));
    StackInit(stack);
    int i;
    for(i=0;i<10;i++)
        Push(stack,i+1);
    IsEmpty(stack);
    StackTraverse(stack);
    int value;
    Pop(stack,*value);
    EmptyStack(stack);
    return 0;
}
