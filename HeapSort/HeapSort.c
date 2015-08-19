#include <stdio.h>
#include <stdlib.h>

#define LEFTCHILD(i) (2*(i)+1)
#define PARENT(i) (((i)-1)/2)

typedef int ElementType;

void Swap(ElementType *a, ElementType *b)
{
	ElementType tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

void PercDown(ElementType A[], int i, int N)
{
	int child;
	ElementType tmp;

	for(tmp=A[i]; LEFTCHILD(i)<N; i=child)
	{
		child = LEFTCHILD(i);
		if(child!=N-1 && A[child+1]>A[child])
			++child;
		if(tmp < A[child])
			A[i] = A[child];
		else
			break;
	}
	A[i] = tmp;
}

void HeapSort(ElementType A[], int N)
{
	int i;

	for(i=PARENT(N-1); i>=0; --i)
		PercDown(A, i, N);
	for(i=N-1; i>0; --i)
	{
		Swap(&A[0], &A[i]);
		PercDown(A, 0, i);
	}
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

	HeapSort(a, N);

	printf("排序后的序列为：\n");
	PrintArray(a, N);
	printf("\n");
}