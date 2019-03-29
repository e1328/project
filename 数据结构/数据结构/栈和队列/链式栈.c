#include<stdio.h>
#include<stdlib.h>

//链式栈定义
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

//链式栈初始化
void StackInit(LinkStack *stack)
{
    if((stack->top = (SNode*)malloc(sizeof(SNode))) == NULL)
    {
        printf("动态内存分配失败!\n");
        return;
    }
    stack->bottom = stack->top;
    stack->top->next = NULL;
    stack->count = 0;
}

//判断栈是否为空
int IsEmpty(LinkStack *stack)
{
    if(stack->top == stack->bottom) //或者按stack->count来判断
        return 1;
    return 0;
}

//元素入栈
void Push(LinkStack *stack,int elem)
{
    //申请空间
    SNode *newNode = (SNode*)malloc(sizeof(SNode));
    newNode->data = elem;
    //push到栈中
    newNode->next = stack->top;
    stack->top = newNode; //先。
    stack->count++; //后。将栈节点“串起来”
}

//出栈，元素存储在value指针中
void Pop(LinkStack *stack,int *value)
{
    if(IsEmpty(stack))
    {
        printf("stack is empty\n");
        return;
    }
    //提取结点
    SNode *tempNode = (SNode*)malloc(sizeof(SNode));
    tempNode = stack->top;
    *value = tempNode->data;
    //栈指针变动
    stack->top = tempNode->next;
    stack->count--;
    //释放栈结点
    free(tempNode); //说明：当插入新元素时，栈顶指针得到更新，指向新的节点
    tempNode = NULL;
}

//栈遍历
void StackTraverse(LinkStack *stack)
{
    //结点扫描
    SNode *nodeScan = stack->top;
    //遍历输出
    while(nodeScan != stack->bottom)
    {
        printf("%d ",nodeScan->data);
        nodeScan = nodeScan->next; //元素入栈过程中，已将节点依次“串起来”，所以可以反向操作
    }
    printf("\n");
    return;
}

//求栈的长度
int StackLength(LinkStack *stack)
{
    return stack->count;
}

//清空/销毁栈
void EmptyStack(LinkStack *stack)
{
    if(IsEmpty(stack))
        return;
    SNode *nodeScan = stack->top;
    SNode *tempNode = (SNode*)malloc(sizeof(SNode));
    tempNode = NULL;
    while(nodeScan != stack->bottom) //或count != 0
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
    //链式栈建立及初始化
    LinkStack *stack = (LinkStack*)malloc(sizeof(LinkStack)); //记得为链式栈分配空间
    StackInit(stack);
    int i;
    for(i=0;i<10;i++) //往栈中压入10个元素
    {
        Push(stack,i+1);
    }
    //判断栈是否为空
    IsEmpty(stack);
    //栈遍历
    StackTraverse(stack);
    //取出并删除栈顶元素
    int value;
    Pop(stack,&value);
    //清空/销毁栈
    EmptyStack(stack);
    return 0;
}
