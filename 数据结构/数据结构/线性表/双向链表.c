#include<stdio.h>
#include<stdlib.h>

typedef struct DNode
{
    int data;
    struct DNode *pre; //前驱指针
    struct DNode *next; //后继指针
}DNode,*DList;

void InitList(DList plist)
{
    if(NULL == plist)
        return;
    plist->next = NULL;
    plist->pre = NUll;
}

DNode* BuyNode(int val)
{
    DNode *pTmp = (DNode*)malloc(sizeof(DNode));
    pTmp->data = val;
    pTmp->next = NULL;
    pTmp->pre = NULL;
    return pTmp;
}

void InsertHead(DList plist,int val)
{
    DNode *pTmp = BuyNode(val);
    pTmp->next = plist->next;
    pTmp->pre = plist;
    if(NULL != pTmp->next)
        pTmp->next->pre = pTmp;
    plist->next = pTmp;
}

void InsertTail(DList plist,int val)
{
    DNode *pTmp = BuyNode(val);
    DNode *PCur = plist;
    while(NULL != pCur->netx)
        pCur = pCur->next;
    pTmp->pre = pCur;
    pCur->next = PTmp;
}

int GetListLen(DList plist)
{
    DNode *pTmp = plist->next;
    int iCount = 0;
    while(NULL != pTmp)
    {
        iCount++;
        pTmp = pTmp->next;
    }
    return iCount;
}

int Delete(DList plist,int key)
{
    DNode *pPre = plist; //前驱结点
    DNode *PCur = plist->next; //后继节点
    while(NULL != pCur)
    {
        if(pCur->data == key)
        {
            if(NULL != pCur->next)
                pCur->next->pre = pCur->pre;
            pCur->pre->next = pCur->next;
            return 1;
        }
        else
        {
            pPre = pCur;
            pCur = pCur->next;
        }
    }
    return 0;
}

DNode* Search(DList plist,int key)
{
    DNode *pCur = plist->next;
    while(NULL != pCur)
    {
        if(pCur->data == key)
            return pCur;
        pCur = pCur->next;
    }
    return NULL;
}

void Destory(DList plist)
{
    DNode *pTmp = plist->next;
    while(NULL != pTmp)
    {
        plist = pTmp->next;
        free(pTmp);
        pTmp = plist;
    }
}

void showDList(DList plist)
{
    DNode *pCur = plist->next;
    while(NULL != pCur)
    {
        printf("%d",pCur->data);
        pCur = pCur->next;
    }
    printf("\n");
}
