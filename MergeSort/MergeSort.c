#include <stdio.h>
#include <stdlib.h>

#define FatalError(x) printf(x)

typedef int ElementType;

void MSort(ElementType a[], ElementType tmpArray[], int Left, int Right);
void Merge(ElementType a[], ElementType tmpArray[], int Lpos, int Rpos, int RightEnd);

void MergeSort(ElementType a[], int N)
{
	ElementType *tmpArray;

	tmpArray = (ElementType*)malloc(N*sizeof(ElementType));
	if(NULL != tmpArray)
	{
		MSort(a, tmpArray, 0, N-1);
		free(tmpArray);
	}
	else
		FatalError("No space for tmp array!\n");
}

void PrintArray(int a[], int N)
{
	int i;
	for(i=0; i<N; ++i)
	{
		printf("%d\t", a[i]);
		if((i+1)%10 == 0)
			printf("\n");
	}
}

enum { N = 100 };

void main()
{
	int i, a[N];

	srand(21845U);
	for(i=0; i<N; ++i)
		a[i] = rand() % 1000;

	printf("排序前的序列为：\n");
	PrintArray(a, N);
	printf("\n");

	MergeSort(a, N);

	printf("排序后的序列为：\n");
	PrintArray(a, N);
	printf("\n");
}

void MSort(ElementType a[], ElementType tmpArray[], int Left, int Right)
{
	int Center;

	if(Left < Right)
	{
		Center = (Left + Right)/2;
		MSort(a, tmpArray, Left, Center);
		MSort(a, tmpArray, Center+1, Right);
		Merge(a, tmpArray, Left, Center+1, Right);
	}
}

void Merge(ElementType a[], ElementType tmpArray[], int Lpos, int Rpos, int RightEnd)
{
	int i, LeftEnd, NumElements, TmpPos;

	LeftEnd = Rpos - 1;
	TmpPos = Lpos;
	NumElements = RightEnd - Lpos + 1;

	while(Lpos<=LeftEnd && Rpos<=RightEnd)
	{
		if(a[Lpos] <= a[Rpos])
			tmpArray[TmpPos++] = a[Lpos++];
		else
			tmpArray[TmpPos++] = a[Rpos++];
	}

	while(Lpos <= LeftEnd)
		tmpArray[TmpPos++] = a[Lpos++];
	while(Rpos <= RightEnd)
		tmpArray[TmpPos++] = a[Rpos++];

	for(i=0; i<NumElements; ++i,--RightEnd)
		a[RightEnd] = tmpArray[RightEnd];
}