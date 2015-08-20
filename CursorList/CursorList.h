#ifndef _CURSOR_LIST_H_
#define _CURSOR_LIST_H_

#define SpaceSize 512
typedef int ElementType;

typedef int PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

struct Node
{
	ElementType Element;
	Position Next;
};

void InitializeCursorSpace();
Position CursorAlloc();
void CursorFree(Position P);
List MakeEmpty(List L);
int IsEmpty(const List L);
int IsLast(const Position P, const List L);
Position Find(ElementType X, const List L);
void Delete(ElementType X, List L);
Position FindPrevious(ElementType X, const List L);
void Insert(ElementType X, List L, Position P);
void DeleteList(List L);
Position Header(const List L);
Position First(const List L);
Position Advance(const Position P);
ElementType Retrieve(const Position P);

#endif