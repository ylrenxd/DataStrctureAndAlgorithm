#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

void Swap(ElementType *a, ElementType *b)
{
	ElementType tmp;
	
	tmp = *a;
	*a = *b;
	*b = tmp;
}

void SelectionSort(ElementType a[], int N)
{
	int i, j, min;

	for(i=0; i<N-1; ++i)
	{
		min = i;
		for(j=i+1; j<N; ++j)
			if(a[j] < a[min])
				min = j;
		if(min != i)
			Swap(&a[i], &a[min]);
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

	SelectionSort(a, N);

	printf("排序后的序列为：\n");
	PrintArray(a, N);
	printf("\n");
}