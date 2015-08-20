#include "CursorList.h"
#include <stdio.h>

extern struct Node CursorSpace[SpaceSize];	//游标链表的内存池，节点元素都在这个内存池中申请空间

void PrintList(const List L)
{
	Position pos;
	
	pos = CursorSpace[L].Next;
	while(pos != 0)
	{
		printf("%d  ", CursorSpace[pos].Element);
		pos = Advance(pos);
	}
	putchar('\n');
}

void main()
{
	List list;
	int i;

	InitializeCursorSpace();

	list = CursorAlloc();
	CursorSpace[list].Next = CursorAlloc();
	CursorSpace[CursorSpace[list].Next].Element = 0;
	CursorSpace[CursorSpace[list].Next].Next = 0;

	for(i=1; i<=15; ++i)
		Insert(i, list, CursorSpace[list].Next);
	PrintList(list);
	MakeEmpty(list);
	PrintList(list);
}