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

//����ǰ������ķ�ʽ���������
void CreatBitree(BiTree *T)
{
    char c = '\0';
    scanf("%c",&c);
    if(c == '#') //�ս��
    {
        *T = NULL;
    }
    else
    {
        *T = (BiTNode*)malloc(sizeof(BiTNode));
        if(!T)
            exit(0);
        (*T)->data = c; //���ɸ����
        CreatBitree(&(*T)->lchild); //����������
        CreatBitree(&(*T)->rchild); //����������
    }
}

//��ӡ�ý�����ڲ���
void visit(char c,int level)
{
    printf("%cλ�ڵ�%d��\n",c,level);
}

//��������ǰ��ݹ����
void PreOrderTraverse(BiTree T,int level)
{
    if(T == NULL) //����
        return;
    visit(T->data,level); //����д�õĴ�ӡ����
    PreOrderTraverse(T->lchild,level+1);
    PreOrderTraverse(T->rchild,level+1);
}

int main()
{
    printf("�밴����������������Ľ�㣬�ս����#��ʾ���س�����\n");
    int level = 1;
    BiTree T = NULL;
    CreatBitree(&T);
    printf("�ö�������ǰ��������Ϊ��\n");
    PreOrderTraverse(T,level);
    printf("\n");
    return 0;
}
