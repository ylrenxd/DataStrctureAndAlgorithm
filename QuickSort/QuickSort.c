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

ElementType Median3(ElementType a[], int left, int right)
{
	int media;

	media = (left + right)/2;
	if(a[left] > a[media])
		Swap(&a[left], &a[media]);
	if(a[left] > a[right])
		Swap(&a[left], &a[right]);
	if(a[media] > a[right])
		Swap(&a[media], &a[right]);

	Swap(&a[media], &a[right-1]);
	return a[right-1];
}

void QSort(ElementType a[], int left, int right)
{
	int i, j;
	ElementType pivot;

	if(right-left+1 > 10)
	{
		pivot = Median3(a, left, right);
		i = left;
		j = right - 1;
		while(1)
		{
			while(a[++i] < pivot);
			while(a[--j] > pivot);
			if(i < j)
				Swap(&a[i], &a[j]);
			else
				break;
		}
		Swap(&a[i], &a[right-1]);
		QSort(a, left, i-1);
		QSort(a, i+1, right);
	}
	else	//对于小数组，直接采用插入排序
		InsertionSort(a+left, right-left+1);
}

void QuickSort(ElementType a[], int N)
{
	QSort(a, 0, N-1);
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

	QuickSort(a, N);

	printf("排序后的序列为：\n");
	PrintArray(a, N);
	printf("\n");
}