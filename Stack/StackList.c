#include "StackList.h"
#include <stdio.h>
#include <stdlib.h>

struct Node
{
	ElementType Element;
	PtrToNode Next;
};

int IsEmpty(Stack S)
{
	if(S != NULL)
		return S->Next == NULL;
	else
	{
		printf("Stack pointer is NULL!\n");
		return -1;
	}
}

Stack CreateStack()
{
	Stack S;

	S = (PtrToNode)malloc(sizeof(struct Node));
	if(S == NULL)
		printf("malloc failure!\n");
	else
		S->Next = NULL;
	return S;
}

void DisposeStack(Stack S)
{
	if(S != NULL)
	{
		MakeEmpty(S);
		free(S);
	}
	else
		printf("Stack pointer is NULL!\n");
}

void MakeEmpty(Stack S)
{
	if(S != NULL)
	{
		while(!IsEmpty(S))
			Pop(S);
	}
	else
		printf("Stack pointer is NULL!\n");
}

void Push(ElementType X, Stack S)
{
	PtrToNode tmpNode;

	tmpNode = (PtrToNode)malloc(sizeof(struct Node));
	if(tmpNode == NULL)
	{
		printf("malloc failure!\n");
	}
	else
	{
		tmpNode->Element = X;
		tmpNode->Next = S->Next;
		S->Next = tmpNode;
	}
}

ElementType Top(Stack S)
{
	if(S != NULL)
	{
		if(!IsEmpty(S))
			return S->Next->Element;
		else
			printf("Stack is empty!\n");
	}
	else
		printf("Stack pointer is NULL!\n");
	return 0;
}

void Pop(Stack S)
{
	PtrToNode tmpNode;

	if(S != NULL)
	{
		if(!IsEmpty(S))
		{
			tmpNode = S->Next;
			S->Next = tmpNode->Next;
			free(tmpNode);
		}
		else
			printf("Stack is empty!\n");
	}
	else
		printf("Stack pointer is NULL!\n");
}