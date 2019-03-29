typedef struct BiTNode
{
    int data;
    struct BiTNode *lchild;
    struct BiTnode *rchild;
}BiTNode,*BiTree;

int SearchBST(BiTree T,int key,BiTree f,BiTree *p)
{
    if(!T)
    {
        *p = f;
        return 0;
    }
    else if(key == T->data)
    {
        *p = T;
        return 1;
    }
    else if(key < T->data)
        return SearchBST(T->lchild,key,T,p);
    else
        return SearchBST(T->rchild,key,T,p);
}
