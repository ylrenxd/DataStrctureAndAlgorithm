#include "QueueList.h"
#include <stdio.h>
#include <stdlib.h>

int IsEmpty(Queue Q)
{
	return Q->Front == NULL;
}

Queue CreateQueue()
{
	Queue Q;

	Q = (Queue)malloc(sizeof(struct QueueRecord));
	if(Q != NULL)
	{
		Q->Front = NULL;
		Q->Rear = NULL;
	}
	return Q;
}

void DisposeQueue(Queue Q)
{
	MakeEmpty(Q);
	free(Q);
}

void MakeEmpty(Queue Q)
{
	while(!IsEmpty(Q))
		Dequeue(Q);
	Q->Front = NULL;
	Q->Rear = NULL;
}

void Enqueue(ElementType X, Queue Q)
{
	PtrToNode tmpNode;

	tmpNode = (PtrToNode)malloc(sizeof(struct QueueNode));
	tmpNode->Element = X;
	tmpNode->Next = NULL;

	if(IsEmpty(Q))
	{
		Q->Front = tmpNode;
		Q->Rear = tmpNode;
	}
	else
	{
		Q->Rear->Next = tmpNode;
		Q->Rear = tmpNode;
	}
}

ElementType Front(Queue Q)
{
	if(!IsEmpty(Q))
		return Q->Front->Element;
	else
	{
		printf("Queue is empty!\n");
		return 0;
	}
}

void Dequeue(Queue Q)
{
	PtrToNode tmpPtr;

	if(!IsEmpty(Q))
	{
		tmpPtr = Q->Front;
		Q->Front = tmpPtr->Next;
		free(tmpPtr);
	}
	else
		printf("Queue is empty!\n");
}