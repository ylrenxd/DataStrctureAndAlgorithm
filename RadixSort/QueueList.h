#ifndef _QUEUELIST_H_
#define _QUEUELIST_H_

typedef int ElementType;

typedef struct QueueNode *PtrToNode;
struct QueueNode
{
	ElementType Element;
	PtrToNode Next;
};

struct QueueRecord
{
	PtrToNode Front;
	PtrToNode Rear;
};
typedef struct QueueRecord *Queue;

int IsEmpty(Queue Q);
Queue CreateQueue();
void DisposeQueue(Queue Q);
void MakeEmpty(Queue Q);
void Enqueue(ElementType X, Queue Q);
ElementType Front(Queue Q);
void Dequeue(Queue Q);

#endif