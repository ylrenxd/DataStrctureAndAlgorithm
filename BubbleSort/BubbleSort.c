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

void BubbleSort(ElementType a[], int N)
{
	int i, j, flag;

	for(i=0; i<N-1; ++i)
	{
		flag = 0;
		for(j=1; j<N-i; ++j)
		{
			if(a[j] < a[j-1])
			{
				Swap(&a[j], &a[j-1]);
				flag = 1;
			}
		}
		if(flag != 1)
			break;
	}
}

enum { N = 100 };

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

void main()
{
	int i, a[N];

	srand(21845U);
	for(i=0; i<N; ++i)
		a[i] = rand() % 1000;

	printf("排序前的序列为：\n");
	PrintArray(a, N);
	printf("\n");

	BubbleSort(a, N);

	printf("排序后的序列为：\n");
	PrintArray(a, N);
	printf("\n");
}