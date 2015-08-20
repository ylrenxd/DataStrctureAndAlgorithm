#include <stdio.h>
#include <stdlib.h>

//杨辉三角每一行元素的个数等于行号N(行号从1开始)，每一行元素的值相当于N-1的组合公式C(N-1,i)的展开,
//每一行开始的空元素位置个数为（最大行号-当前行号）个
void PrintYanghuiTriangle(int N)
{
	int *Array1, *Array2, *tmp;
	int i, j;

	if(N <= 0)
		return;
	Array1 = (int*)malloc(N*sizeof(int));
	Array2 = (int*)malloc(N*sizeof(int));

	if(N == 1)
		printf("1\n");
	else if(N == 2)
	{
		printf(" 1\n1 1\n");
	}
	else	//N > 2
	{
		for(j=0; j<N-1; ++j)
			printf(" ");
		printf("1\n");

		for(j=0; j<N-2; ++j)
			printf(" ");
		printf("1 1\n");

		Array1[0] = 1;
		Array1[1] = 1;

		for(i=3; i<=N; ++i)
		{
			Array2[0] = 1;	//第i行第一个元素
			for(j=1; j<=i-2; ++j)
				Array2[j] = Array1[j-1] + Array1[j];
			Array2[i-1] = 1;

			//打印输出本行结果
			for(j=0; j<N-i; ++j)
				printf(" ");
			for(j=0; j<i; ++j)
				printf("%d ", Array2[j]);
			printf("\n");

			tmp = Array1;
			Array1 = Array2;
			Array2 = tmp;
		}
	}

	free(Array1);
	free(Array2);
}

void main()
{
	int N;

	printf("请输入打印杨辉三角的行数(N>0)：");
	while(EOF != scanf_s("%d", &N))
	{
		PrintYanghuiTriangle(N);
		printf("请输入打印杨辉三角的行数：");
	}
}