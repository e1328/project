//DLink.h
#include<stdio.h>
#include<stdlib.h>


typedef struct _DNode
{
	int data;
	struct _DNode* pre;	//ǰ��ָ��
	struct _DNode* next; //���ָ��
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


	printf("search ��һ���ڵ�4:");
	DNode* pTmp = Search(&head, 4);
	printf("%d\n", pTmp->data);
	printf("search ���һ���ڵ�9:");
	pTmp = Search(&head, 9);
	printf("%d\n", pTmp->data);


	printf("ɾ����һ���ڵ�4:\n");
	if (Delete(&head, 4))
	{
		ShowDList(&head);
	}
	else
	{
		printf("Not Fount!!!\n");
	}
	printf("ɾ�����һ���ڵ�9:\n");
	if (Delete(&head, 9))
	{
		ShowDList(&head);
	}
	else
	{
		printf("Not Fount!!!\n");
	}
	Destroy(&head);		//��������
	return 0;
}
void InitList(DList plist)		//��ʼ��ͷ���
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
	DNode* pTmp = BuyNode(val);		//����һ���µĽڵ�
	pTmp->next = plist->next;
	pTmp->pre = plist;
	if (NULL != pTmp->next)		//������ж�һ�������٣����߿�������ȥ������ᷢ��ʲô
	{
		pTmp->next->pre = pTmp;		//��һ���ڵ��ǰ��ָ��pTmp
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
	DNode* pPre = plist;		//ǰ�����
	DNode* pCur = plist->next;	//��̽ڵ�
	while (NULL != pCur)
	{
		if (pCur->data == key)
		{
			if (NULL != pCur->next)		//���漰��ɾ�����һ���ڵ㣬��Ϊ�������һ���ڵ���˵pCur->nextΪ�գ�Ҳ��pCur->nextû��pre
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
