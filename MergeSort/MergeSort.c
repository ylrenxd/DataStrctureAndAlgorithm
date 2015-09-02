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
	int LeftEnd = Rpos - 1;
	int i, j, k;

	i = Lpos, j = Rpos, k = Lpos;
	while(i<=LeftEnd && j<=RightEnd)
	{
		if(a[i] <= a[j])
			tmpArray[k++] = a[i++];
		else
			tmpArray[k++] = a[j++];
	}

	while(i <= LeftEnd)
		tmpArray[k++] = a[i++];
	while(j <= RightEnd)
		tmpArray[k++] = a[j++];

	for(k=Lpos; k<=RightEnd; ++k)
		a[k] = tmpArray[k];
}