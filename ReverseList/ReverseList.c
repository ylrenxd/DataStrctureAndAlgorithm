//#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct Node *PtrToNode;
struct Node
{
	int element;
	PtrToNode pNext;
};
typedef PtrToNode List;

void ReverseList(List L)
{
	PtrToNode pTmp1, pTmp2, pTmp3;

	if(L==NULL || L->pNext == NULL)
		return;
	pTmp1 = L->pNext;
	pTmp2 = pTmp1->pNext;
	if(pTmp2 == NULL)
		return;
	do{
		pTmp3 = pTmp2->pNext;
		pTmp2->pNext = pTmp1;
		pTmp1 = pTmp2;
		pTmp2 = pTmp3;
	}while(pTmp2 != NULL);
	L->pNext->pNext = NULL;
	L->pNext = pTmp1;
}

void PrintList(List L)
{
	PtrToNode pTmp;

	if(L == NULL)
		return;
	pTmp = L->pNext;
	while(pTmp != NULL)
	{
		printf("%d ", pTmp->element);
		pTmp = pTmp->pNext;
	}
	putchar('\n');
}

void main()
{
	List list;
	PtrToNode pTmp, pTail;
	int i, N = 20;

	list = (List)malloc(sizeof(struct Node));
	list->pNext = NULL;
	srand(21845U);
	pTail = list;
	for(i=0; i<N; ++i)
	{
		pTmp = (PtrToNode)malloc(sizeof(struct Node));
		pTmp->element = rand()%1000;
		pTmp->pNext = NULL;
		pTail->pNext = pTmp;
		pTail = pTmp;
	}

	PrintList(list);
	ReverseList(list);
	PrintList(list);

	pTmp = list->pNext;
	while(pTmp != NULL)
	{
		list->pNext = pTmp->pNext;
		free(pTmp);
		pTmp = list->pNext;
	}
	free(list);
}