#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100

typedef char ElemType;

typedef struct BiTNode
{
    ElemType data;
    struct BiTNode *lchild;
    struct BiTNode *rchild;
}BiTNode,*BiTree;

//按照前序输入的方式构造二叉树
void CreatBitree(BiTree *T)
{
    char c = '\0';
    scanf("%c",&c);
    if(c == '#') //空结点
    {
        *T = NULL;
    }
    else
    {
        *T = (BiTNode*)malloc(sizeof(BiTNode));
        if(!T)
            exit(0);
        (*T)->data = c; //生成根结点
        CreatBitree(&(*T)->lchild); //构造左子树
        CreatBitree(&(*T)->rchild); //构造右子树
    }
}

//二叉树的前序递归遍历
void PreOrderTraverse(BiTree T)
{
    if(T == NULL) //空树
        return;
    printf("%c",T->data); //显示结点数据
    PreOrderTraverse(T->lchild); //先序遍历左子树
    PreOrderTraverse(T->rchild); //再先序遍历右子树
}

//二叉树的中序递归遍历
void InOrderTraverse(BiTree T)
{
    if(T == NULL) //空树
        return;
    InOrderTraverse(T->lchild); //中序遍历左子树
    printf("%c",T->data); //显示结点数据
    InOrderTraverse(T->rchild); //最后中序遍历右子树
}

//二叉树的后序递归遍历
void PostOrderTraverse(BiTree T)
{
    if(T == NULL) //空树
        return;
    PostOrderTraverse(T->lchild); //先后序遍历左子树
    PostOrderTraverse(T->rchild); //再后序遍历右子树
    printf("%c",T->data); //显示结点数据
}

int main()
{
    printf("请按照先序输入二叉树的结点，空结点用#表示，回车结束\n");
    BiTree T = NULL;
    CreatBitree(&T);
    printf("该二叉树的前序遍历结果为：\n");
    PreOrderTraverse(T);
    printf("\n");
    printf("该二叉树的中序遍历结果为：\n");
    InOrderTraverse(T);
    printf("\n");
    printf("该二叉树的后序遍历结果为：\n");
    PostOrderTraverse(T);
    printf("\n");
    return 0;
}
