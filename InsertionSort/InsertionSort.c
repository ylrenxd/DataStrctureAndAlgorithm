#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

void InsertionSort(ElementType a[], int N)
{
	int i, j;
	ElementType tmp;

	for(i=1; i<N; ++i)
	{
		tmp = a[i];
		for(j=i; j>=1 && tmp<a[j-1]; --j)
			a[j] = a[j-1];
		a[j] = tmp;
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

	InsertionSort(a, N);

	printf("排序后的序列为：\n");
	PrintArray(a, N);
	printf("\n");
}