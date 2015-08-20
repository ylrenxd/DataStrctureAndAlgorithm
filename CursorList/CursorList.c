#include "CursorList.h"

struct Node CursorSpace[SpaceSize];

Position CursorAlloc()
{
	Position P;

	P = CursorSpace[0].Next;
	CursorSpace[0].Next = CursorSpace[P].Next;
	return P;
}

void CursorFree(Position P)
{
	CursorSpace[P].Next = CursorSpace[0].Next;
	CursorSpace[0].Next = P;
}

void InitializeCursorSpace()
{
	int i;
	
	for(i=0; i<=SpaceSize-2; ++i)
		CursorSpace[i].Next = i + 1;
	CursorSpace[SpaceSize-1].Next = 0;
}

List MakeEmpty(List L)
{
	Position pos;

	pos = CursorSpace[L].Next;
	while(pos != 0)
	{
		CursorSpace[pos].Element = 0;
		pos = CursorSpace[pos].Next;
	}
	return L;
}

int IsEmpty(const List L)
{
	return CursorSpace[L].Next==0 ? 1 : 0;
}

int IsLast(const Position P, const List L)
{
	return CursorSpace[P].Next==0 ? 1 : 0;
}

Position Find(ElementType X, const List L)
{
	Position pos;

	pos = CursorSpace[L].Next;
	while(pos != 0)
	{
		if(CursorSpace[pos].Element == X)
			return pos;
	}
	return 0;
}

void Delete(ElementType X, List L)
{
	Position pos, tmp;

	pos = FindPrevious(X, L);
	if(pos == 0)
		return;
	tmp = CursorSpace[pos].Next;
	CursorSpace[pos].Next = CursorSpace[tmp].Next;
	CursorFree(tmp);
}

Position FindPrevious(ElementType X, const List L)
{
	Position pos;
	
	pos = L;
	while(CursorSpace[pos].Next != 0)
	{
		if(CursorSpace[CursorSpace[pos].Next].Element == X)
			return pos;
	}
	return 0;
}

void Insert(ElementType X, List L, Position P)
{
	Position pos, prevPos;

	pos = CursorAlloc();
	CursorSpace[pos].Element = X;
	CursorSpace[pos].Next = P;
	prevPos = FindPrevious(CursorSpace[P].Element, L);
	CursorSpace[prevPos].Next = pos;
}

void DeleteList(List L)
{
	Position pos;

	pos = CursorSpace[L].Next;
	while(pos != 0)
	{
		CursorSpace[L].Next = CursorSpace[pos].Next;
		CursorFree(pos);
		pos = CursorSpace[L].Next;
	}
	CursorFree(L);
}

Position Header(const List L)
{
	return L;
}

Position First(const List L)
{
	return CursorSpace[L].Next;
}

Position Advance(const Position P)
{
	return CursorSpace[P].Next;
}

ElementType Retrieve(const Position P)
{
	return P!=0 ? CursorSpace[P].Element : -1;
}