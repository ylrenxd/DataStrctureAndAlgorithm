#include <stdio.h>
#include <stdlib.h>

//�������ÿһ��Ԫ�صĸ��������к�N(�кŴ�1��ʼ)��ÿһ��Ԫ�ص�ֵ�൱��N-1����Ϲ�ʽC(N-1,i)��չ��,
//ÿһ�п�ʼ�Ŀ�Ԫ��λ�ø���Ϊ������к�-��ǰ�кţ���
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
			Array2[0] = 1;	//��i�е�һ��Ԫ��
			for(j=1; j<=i-2; ++j)
				Array2[j] = Array1[j-1] + Array1[j];
			Array2[i-1] = 1;

			//��ӡ������н��
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

	printf("�������ӡ������ǵ�����(N>0)��");
	while(EOF != scanf_s("%d", &N))
	{
		PrintYanghuiTriangle(N);
		printf("�������ӡ������ǵ�������");
	}
}