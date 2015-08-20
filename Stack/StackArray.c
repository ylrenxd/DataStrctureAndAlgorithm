#include "StackArray.h"
#include <stdio.h>
#include <stdlib.h>

#define EmptyTOS -1
#define MinStackSize 5

struct StackRecord
{
	int Capacity;
	int TopOfStack;
	ElementType *Array;
};

int IsEmpty(Stack S)
{
	if(S != NULL)
		return S->TopOfStack == EmptyTOS;
	else
	{
		printf("Stack pointer is NULL!\n");
		return -1;
	}
}

int IsFull(Stack S)
{
	if(S != NULL)
		return S->TopOfStack == S->Capacity-1;
	else
	{
		printf("Stack pointer is NULL!\n");
		return -1;
	}
}

Stack CreateStack(int MaxElements)
{
	Stack S = NULL;

	if(MaxElements < MinStackSize)
		printf("Stack size is too small!\n");
	else
	{
		S = (Stack)malloc(sizeof(struct StackRecord));
		if(S == NULL)
			printf("malloc failure!\n");
		else
		{
			S->Capacity = MaxElements;
			S->Array = (ElementType*)malloc(MaxElements*sizeof(ElementType));
			if(S->Array == NULL)
			{
				printf("Stack array malloc failure!\n");
				free(S);
				S = NULL;
			}
			else
				MakeEmpty(S);
		}
	}
	return S;	
}

void DisposeStack(Stack S)
{
	if(S != NULL)
	{
		free(S->Array);
		free(S);
	}
	else
		printf("Stack pointer is NULL!\n");
}

void MakeEmpty(Stack S)
{
	if(S != NULL)
	{
		S->TopOfStack = EmptyTOS;
	}
	else
		printf("Stack pointer is NULL!\n");
}

void Push(ElementType X, Stack S)
{
	if(S != NULL)
	{
		if(!IsFull(S))
			S->Array[++(S->TopOfStack)] = X;
		else
			printf("Stack is Full!\n");
	}
	else
		printf("Stack pointer is NULL!\n");
}

ElementType Top(Stack S)
{
	if(S != NULL)
		if(!IsEmpty(S))
			return S->Array[S->TopOfStack];
		else
			printf("Stack is Empty!\n");
	else
		printf("Stack pointer is NULL!\n");
	return 0;
}

void Pop(Stack S)
{
	if(S != NULL)
		if(!IsEmpty(S))
			--(S->TopOfStack);
		else
			printf("Stack is Empty!\n");
	else
		printf("Stack pointer is NULL!\n");
}

ElementType TopAndPop(Stack S)
{
	if(S != NULL)
		if(!IsEmpty(S))
			return S->Array[S->TopOfStack--];
		else
			printf("Stack is Empty!\n");
	else
		printf("Stack pointer is NULL!\n");
	return 0;
}