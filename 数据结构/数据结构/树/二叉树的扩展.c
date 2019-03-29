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

//打印该结点所在层数
void visit(char c,int level)
{
    printf("%c位于第%d层\n",c,level);
}

//二叉树的前序递归遍历
void PreOrderTraverse(BiTree T,int level)
{
    if(T == NULL) //空树
        return;
    visit(T->data,level); //调用写好的打印方法
    PreOrderTraverse(T->lchild,level+1);
    PreOrderTraverse(T->rchild,level+1);
}

int main()
{
    printf("请按照先序输入二叉树的结点，空结点用#表示，回车结束\n");
    int level = 1;
    BiTree T = NULL;
    CreatBitree(&T);
    printf("该二叉树的前序遍历结果为：\n");
    PreOrderTraverse(T,level);
    printf("\n");
    return 0;
}
