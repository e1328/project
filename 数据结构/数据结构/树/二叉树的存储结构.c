/*二叉树的二叉链表结点结构定义*/
typedef int ElemeType;
typedef struct BiTNode //结点结构
{
    ElemeType data; //结点数据
    struct BiTNode *lchild; //左孩子指针
    struct BiTNode *rchild; //右孩子指针
}BiTNode,*BiTree;
