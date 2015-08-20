#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int IsCorrent(int row, int col, int **Q, const int *pN)
{
	int r, c;

	for(r=row,c=0; c<*pN; ++c)	//判断行
		if(c!=col && Q[r][c]==1)
			return 0;
	for(c=col,r=0; r<*pN; ++r)	//判断列
		if(r!=row && Q[r][c]==1)
			return 0;
	for(r=row-1,c=col-1; r>=0 && c>=0; --r,--c)	//判断左上方
		if(Q[r][c]==1)
			return 0;
	for(r=row+1,c=col+1; r<*pN && c<*pN; ++r,++c)	//判断右下方
		if(Q[r][c]==1)
			return 0;
	for(r=row-1,c=col+1; r>=0 && c<*pN; --r,++c)	//判断右上方
		if(Q[r][c]==1)
			return 0;
	for(r=row+1,c=col-1; r<*pN && c>=0; ++r,--c)	//判断左下方
		if(Q[r][c]==1)
			return 0;
	return 1;
}

void Queen(int row, int **Q, const int *pN, int *pCount)
{
	int c, r;

	if(row == *pN)
	{
		for(r=0; r<*pN; ++r)
		{
			for(c=0; c<*pN; ++c)
				printf("%d ", Q[r][c]);
			printf("\n");
		}
		printf("\n");
		++(*pCount);
		return;
	}
	
	for(c=0; c<*pN; ++c)
	{
		if(IsCorrent(row, c, Q, pN))
		{
			Q[row][c] = 1;
			Queen(row+1, Q, pN, pCount);
			Q[row][c] = 0;
		}
	}
}

int PlaceQueenMethodNum(int N)
{
	int **Q;
	int i;
	int count = 0;

	Q = (int**)calloc(N, sizeof(int*));
	Q[0] = (int*)calloc(N*N, sizeof(int));
	for(i=1; i<N; ++i)
		Q[i] = Q[0] + i*N;

	Queen(0, Q, &N, &count);

	free(Q[0]);
	free(Q);
	return count;
}

void main()
{
	int N;

	while(1==scanf("%u", &N))
	{
		printf("%d\n", PlaceQueenMethodNum(N));
	}
}