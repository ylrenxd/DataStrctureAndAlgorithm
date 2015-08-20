#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct Node *PtrToNode;
struct Node
{
	int coef;
	int power;
	PtrToNode pNext;
};
typedef PtrToNode Polynomial;

//打印输出多项式
int PrintPolynomial(Polynomial poly)
{
	PtrToNode pTmp;

	if(poly==NULL)
		return 1;
	pTmp = poly->pNext;
	while(pTmp != NULL)
	{
		printf("%+d*x^%d", pTmp->coef, pTmp->power);
		pTmp = pTmp->pNext;
	}
	putchar('\n');
	return 0;
}

//删除多项式
void DeletePolynomial(Polynomial poly)
{
	if(poly != NULL)
	{
		DeletePolynomial(poly->pNext);
		free(poly);
	}
}

//多项式相加
Polynomial PolynomialAdd(Polynomial poly1, Polynomial poly2)
{
	PtrToNode pTmp1, pTmp2, pTmp3, pTmp4;
	Polynomial polyAdd;

	if(poly1==NULL || poly2==NULL)
		return NULL;

	polyAdd = (PtrToNode)malloc(sizeof(struct Node));
	polyAdd->pNext = NULL;

	pTmp1 = poly1->pNext;
	pTmp2 = poly2->pNext;
	pTmp3 = polyAdd;
	while(pTmp1!=NULL && pTmp2!=NULL)
	{
		pTmp4 = (PtrToNode)malloc(sizeof(struct Node));
		if(pTmp1->power == pTmp2->power)
		{
			pTmp4->coef = pTmp1->coef + pTmp2->coef;
			pTmp4->power = pTmp1->power;
			pTmp4->pNext = NULL;
			pTmp3->pNext = pTmp4;
			pTmp3 = pTmp4;
			pTmp1 = pTmp1->pNext;
			pTmp2 = pTmp2->pNext;
		}
		else if(pTmp1->power > pTmp2->power)
		{
			pTmp4->coef = pTmp1->coef;
			pTmp4->power = pTmp1->power;
			pTmp4->pNext = NULL;
			pTmp3->pNext = pTmp4;
			pTmp3 = pTmp4;
			pTmp1 = pTmp1->pNext;
		}
		else if(pTmp1->power < pTmp2->power)
		{
			pTmp4->coef = pTmp2->coef;
			pTmp4->power = pTmp2->power;
			pTmp4->pNext = NULL;
			pTmp3->pNext = pTmp4;
			pTmp3 = pTmp4;
			pTmp2 = pTmp2->pNext;
		}
	}

	while(pTmp1 != NULL)
	{
		pTmp4 = (PtrToNode)malloc(sizeof(struct Node));
		pTmp4->coef = pTmp1->coef;
		pTmp4->power = pTmp1->power;
		pTmp4->pNext = NULL;
		pTmp3->pNext = pTmp4;
		pTmp3 = pTmp4;
		pTmp1 = pTmp1->pNext;
	}

	while(pTmp2 != NULL)
	{
		pTmp4 = (PtrToNode)malloc(sizeof(struct Node));
		pTmp4->coef = pTmp2->coef;
		pTmp4->power = pTmp2->power;
		pTmp4->pNext = NULL;
		pTmp3->pNext = pTmp4;
		pTmp3 = pTmp4;
		pTmp2 = pTmp2->pNext;
	}
	return polyAdd;
}

//多项式相乘
Polynomial PolynomialMult(Polynomial poly1, Polynomial poly2)
{
	PtrToNode pTmp1, pTmp2, pTmp3, pTmp4;
	int i, j, M, N;
	Polynomial *polyArr;
	Polynomial polyM, polyN;

	if(poly1==NULL || poly2==NULL)
		return NULL;

	//比较两个多项式的元素个数
	pTmp1 = poly1->pNext;
	i = 0;
	while(pTmp1 != NULL)
	{
		++i;
		pTmp1 = pTmp1->pNext;
	}

	pTmp2 = poly2->pNext;
	j = 0;
	while(pTmp2 != NULL)
	{
		++j;
		pTmp2 = pTmp2->pNext;
	}

	if(i==0 || j==0)
		return NULL;

	if(i > j)
	{
		M = i;
		N = j;
		polyM = poly1;
		polyN = poly2;
	}
	else
	{
		M = j;
		N = i;
		polyM = poly2;
		polyN = poly1;
	}

	//构建多项式数组
	polyArr = (Polynomial*)malloc(N*sizeof(Polynomial));
	for(i=0; i<N; ++i)
	{
		polyArr[i] = (PtrToNode)malloc(sizeof(struct Node));
		polyArr[i]->pNext = NULL;
	}
	
	pTmp1 = polyN->pNext;
	for(i=0; i<N; ++i)
	{
		pTmp2 = polyM->pNext;
		pTmp3 = polyArr[i];
		for(j=0; j<M; ++j)
		{
			pTmp4 = (PtrToNode)malloc(sizeof(struct Node));
			pTmp4->coef = pTmp1->coef * pTmp2->coef;
			pTmp4->power = pTmp1->power + pTmp2->power;
			pTmp4->pNext = NULL;
			pTmp3->pNext = pTmp4;
			pTmp3 = pTmp4;
			pTmp2 = pTmp2->pNext;
		}
		pTmp1 = pTmp1->pNext;
	}

	if(N == 1)
		return polyArr[0];

	//多项式数组相加
	pTmp1 = polyArr[0];
	pTmp2 = polyArr[1];
	pTmp1 = PolynomialAdd(pTmp1, pTmp2);
	for(i=2; i<N; ++i)
	{
		pTmp2 = polyArr[i];
		pTmp3 = PolynomialAdd(pTmp1, pTmp2);
		DeletePolynomial(pTmp1);
		pTmp1 = pTmp3;
	}

	for(i=0; i<N; ++i)
		DeletePolynomial(polyArr[i]);
	free(polyArr);
	return pTmp1;
}

void main()
{
	Polynomial poly1, poly2, polyMult;
	PtrToNode pTmp1, pTmp2;
	int a, b;

	poly1 = (Polynomial)malloc(sizeof(struct Node));
	poly2 = (Polynomial)malloc(sizeof(struct Node));
	poly1->pNext = NULL;
	poly2->pNext = NULL;

	//多项式必须按幂数从大到小的顺序输入
	puts("Pelease input polynoimal1:");
	pTmp2 = poly1;
	while(2 == scanf("%d%d", &a, &b))
	{
		pTmp1 = (PtrToNode)malloc(sizeof(struct Node));
		pTmp1->coef = a;
		pTmp1->power = b;
		pTmp1->pNext = NULL;
		pTmp2->pNext = pTmp1;
		pTmp2 = pTmp1;
	}

	puts("Pelease input polynoimal2:");
	pTmp2 = poly2;
	while(2 == scanf("%d%d", &a, &b))
	{		
		pTmp1 = (PtrToNode)malloc(sizeof(struct Node));
		pTmp1->coef = a;
		pTmp1->power = b;
		pTmp1->pNext = NULL;
		pTmp2->pNext = pTmp1;
		pTmp2 = pTmp1;
	}

	PrintPolynomial(poly1);
	PrintPolynomial(poly2);

	polyMult = PolynomialMult(poly1, poly2);

	PrintPolynomial(polyMult);

	DeletePolynomial(poly1);
	DeletePolynomial(poly2);
	DeletePolynomial(polyMult);
}