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

//��������ǰ��ݹ����
void PreOrderTraverse(BiTree T)
{
    if(T == NULL) //����
        return;
    printf("%c",T->data); //��ʾ�������
    PreOrderTraverse(T->lchild); //�������������
    PreOrderTraverse(T->rchild); //���������������
}

//������������ݹ����
void InOrderTraverse(BiTree T)
{
    if(T == NULL) //����
        return;
    InOrderTraverse(T->lchild); //�������������
    printf("%c",T->data); //��ʾ�������
    InOrderTraverse(T->rchild); //����������������
}

//�������ĺ���ݹ����
void PostOrderTraverse(BiTree T)
{
    if(T == NULL) //����
        return;
    PostOrderTraverse(T->lchild); //�Ⱥ������������
    PostOrderTraverse(T->rchild); //�ٺ������������
    printf("%c",T->data); //��ʾ�������
}

int main()
{
    printf("�밴����������������Ľ�㣬�ս����#��ʾ���س�����\n");
    BiTree T = NULL;
    CreatBitree(&T);
    printf("�ö�������ǰ��������Ϊ��\n");
    PreOrderTraverse(T);
    printf("\n");
    printf("�ö�����������������Ϊ��\n");
    InOrderTraverse(T);
    printf("\n");
    printf("�ö������ĺ���������Ϊ��\n");
    PostOrderTraverse(T);
    printf("\n");
    return 0;
}
