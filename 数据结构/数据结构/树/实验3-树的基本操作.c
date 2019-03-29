#include <stdio.h>
#include <stdlib.h>

typedef char ElemType;
typedef struct BiTNode
{
    ElemType data;
    struct BiTNode *lchild;
    struct BiTNode *rchild;
}BiTNode,*BiTree;

int leafcount;
int allcount;

void CreateBiTree(BiTree *T)
{
    char c;
    scanf("%c",&c);
    if(c=='#')
        *T = NULL;
    else
    {
        *T = (BiTNode*)malloc(sizeof(BiTNode));
        if(!T)
            exit(0);
        (*T)->data = c;
        CreateBiTree(&(*T)->lchild);
        CreateBiTree(&(*T)->rchild);
    }
}

void InOrderTraverse(BiTree T)
{
    if(T == NULL)
        return;
    InOrderTraverse(T->lchild);
    printf("%c",T->data);
    allcount++;
    InOrderTraverse(T->rchild);
}

int IsEmpty_BiTree(BiTree *T)
{
    if(*T == NULL)
        return 1;
    else
        return 0;
}

void LevelOrderTraverse(BiTree T)
{
    int front = 0;
    int rear = 0;
    BiTree BiQueue[20];
    BiTree tempNode;
    if(!IsEmpty_BiTree(&T))
    {
        BiQueue[rear++] = T;
        while(front!=rear)
        {
            tempNode = BiQueue[front++];
            if(!IsEmpty_BiTree(&(tempNode->lchild)))
                BiQueue[rear++] = tempNode->lchild;
            if(!IsEmpty_BiTree(&(tempNode->rchild)))
                BiQueue[rear++] = tempNode->rchild;
            printf("%c",tempNode->data);
        }
    }
}

void Leafcount(BiTree T)
{
    if(T)
    {
        if(T->lchild==NULL&&T->rchild==NULL)
            leafcount++;
        Leafcount(T->lchild);
        Leafcount(T->rchild);
    }
}

int TreeDeep(BiTree T)
{
    int deep = 0;
    if(T)
    {
        int leftdeep = TreeDeep(T->lchild);
        int rightdeep = TreeDeep(T->rchild);
        deep = leftdeep+1 > rightdeep+1 ? leftdeep+1 : rightdeep+1;

    }
    return deep;
}

int main()
{
    BiTree T = NULL;
    CreateBiTree(&T);
    printf("中序遍历结果：");
    InOrderTraverse(T);
    printf("\n");
    Leafcount(T);
    printf("二叉树中结点个数：%d\n",allcount);
    printf("二叉树中叶子结点个数：%d\n",leafcount);
    int d = TreeDeep(T);
    printf("二叉树的高度：%d\n",d);
    return 0;
}
