#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

void ShellSort(ElementType a[], int N)
{
	int i, j, inc;
	ElementType tmp;

	for(inc=N/2; inc>=1; inc/=2)
	{
		for(i=inc; i<N; ++i)
		{
			tmp = a[i];
			for(j=i; j>=inc && tmp<a[j-inc]; j-=inc)
				a[j] = a[j-inc];
			a[j] = tmp;
		}
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

	ShellSort(a, N);

	printf("排序后的序列为：\n");
	PrintArray(a, N);
	printf("\n");
}