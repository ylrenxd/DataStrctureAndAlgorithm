#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "QueueList.h"

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

void RadixSort(int a[], int N, int UpLimit)	//UpLimit must be the power of 10
{
	int i, j, k, n, nRadix;
	Queue *queueArray;

	queueArray = (Queue*)malloc(10*sizeof(Queue));	//����10�������ռ�
	for(i=0; i<10; ++i)
		queueArray[i] = CreateQueue();

	for(k=1,j=0; j<(int)(log(1.*UpLimit)/log(10.)+0.5); k*=10,++j)
	{
		for(i=0; i<N; ++i)
		{
			nRadix = (a[i]/k) % 10;
			Enqueue(a[i], queueArray[nRadix]);
		}

		//��һ�������Ľ���Żص�������
		for(n=0,i=0; i<10; ++i)
		{
			while(!IsEmpty(queueArray[i]))
			{
				a[n++] = Front(queueArray[i]);
				Dequeue(queueArray[i]);
			}
		}

		printf("��%d������������Ϊ��\n", j+1);
		PrintArray(a, N);
		printf("\n");
	}

	for(i=0; i<10; ++i)
		DisposeQueue(queueArray[i]);
	free(queueArray);
}

enum { N = 100 };

void main()
{
	int i, a[N];

	srand(21845U);
	for(i=0; i<N; ++i)
		a[i] = rand() % 1000;

	printf("����ǰ������Ϊ��\n");
	PrintArray(a, N);
	printf("\n");

	RadixSort(a, N, 1000);

	printf("����������Ϊ��\n");
	PrintArray(a, N);
	printf("\n");
}