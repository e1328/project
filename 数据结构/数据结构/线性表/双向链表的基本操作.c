//DLink.h
#include<stdio.h>
#include<stdlib.h>


typedef struct _DNode
{
	int data;
	struct _DNode* pre;	//前驱指针
	struct _DNode* next; //后继指针
}DNode, *DList;
void InitList(DList plist);
void InsertHead(DList plist, int val);
void InsertTail(DList plist, int val);
bool Delete(DList plist, int key);
DNode* Search(DList plist, int key);
int GetListLen(DList plist);
void Destroy(DList plist);
DNode* BuyNode(int val);
void ShowDList(DList plist);

//DLink.c
#include "test.h"
int main()
{
	DNode head;
	InitList(&head);
	for (int i = 1; i < 5; ++i)
	{
		InsertHead(&head, i);
	}
	ShowDList(&head);
	printf("DList length is %d \n", GetListLen(&head));
	for (int i = 6; i < 10; ++i)
	{
		InsertTail(&head, i);
	}
	ShowDList(&head);
	printf("DList length is %d \n", GetListLen(&head));


	printf("search 第一个节点4:");
	DNode* pTmp = Search(&head, 4);
	printf("%d\n", pTmp->data);
	printf("search 最后一个节点9:");
	pTmp = Search(&head, 9);
	printf("%d\n", pTmp->data);


	printf("删除第一个节点4:\n");
	if (Delete(&head, 4))
	{
		ShowDList(&head);
	}
	else
	{
		printf("Not Fount!!!\n");
	}
	printf("删除最后一个节点9:\n");
	if (Delete(&head, 9))
	{
		ShowDList(&head);
	}
	else
	{
		printf("Not Fount!!!\n");
	}
	Destroy(&head);		//销毁链表
	return 0;
}
void InitList(DList plist)		//初始化头结点
{
	if (NULL == plist)
		return;
	plist->next = NULL;
	plist->pre = NULL;
}
DNode* BuyNode(int val)
{
	DNode* pTmp = (DNode*)malloc(sizeof(DNode));
	pTmp->data = val;
	pTmp->next = NULL;
	pTmp->pre = NULL;
	return pTmp;
}
void ShowDList(DList plist)
{
	DNode* pCur = plist->next;
	while (NULL != pCur)
	{
		printf("%5d", pCur->data);
		pCur = pCur->next;
	}
	printf("\n");
}
void InsertHead(DList plist, int val)
{
	DNode* pTmp = BuyNode(val);		//申请一个新的节点
	pTmp->next = plist->next;
	pTmp->pre = plist;
	if (NULL != pTmp->next)		//这里的判断一定不能少，读者可以试想去掉这个会发生什么
	{
		pTmp->next->pre = pTmp;		//后一个节点的前驱指向pTmp
	}
	plist->next = pTmp;
}
void InsertTail(DList plist, int val)
{
	DNode* pTmp = BuyNode(val);
	DNode* pCur = plist;
	while (NULL != pCur->next)
	{
		pCur = pCur->next;
	}
	pTmp->pre = pCur;
	pCur->next = pTmp;
}
bool Delete(DList plist, int key)
{
	DNode* pPre = plist;		//前驱结点
	DNode* pCur = plist->next;	//后继节点
	while (NULL != pCur)
	{
		if (pCur->data == key)
		{
			if (NULL != pCur->next)		//这涉及到删除最后一个节点，因为对于最后一个节点来说pCur->next为空，也即pCur->next没有pre
			{
				pCur->next->pre = pCur->pre;
			}
			pCur->pre->next = pCur->next;
			return true;
		}
		else
		{
			pPre = pCur;
			pCur = pCur->next;
		}
	}
	return false;
}
DNode* Search(DList plist, int key)
{
	DNode* pCur = plist->next;
	while (NULL != pCur)
	{
		if (pCur->data == key)
		{
			return pCur;
		}
		pCur = pCur->next;
	}
	return NULL;
}
int GetListLen(DList plist)
{
	DNode* pTmp = plist->next;
	int iCount = 0;
	while (NULL != pTmp)
	{
		++iCount;
		pTmp = pTmp->next;
	}
	return iCount;
}
void Destroy(DList plist)
{
	DNode* pTmp = plist->next;
	while (NULL != pTmp)
	{
		plist = pTmp->next;
		free(pTmp);
		pTmp = plist;
	}
}
