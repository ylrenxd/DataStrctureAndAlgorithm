#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct Node *PtrToNode;
struct Node
{
	char value;
	PtrToNode pLeft;
	PtrToNode pRight;
};

#define EmptyTOS (-1)
struct StackRecord
{
	int capacity;
	int TopOfStack;
	PtrToNode *pData;
};
typedef struct StackRecord *Stack;

Stack CreateStack(int MaxSize)
{
	Stack S;

	if(MaxSize < 2)
		return NULL;
	S = (Stack)malloc(sizeof(struct StackRecord));
	S->capacity = MaxSize;
	S->TopOfStack = EmptyTOS;
	S->pData = (PtrToNode*)malloc(MaxSize*sizeof(PtrToNode));
	return S;
}

void DisposeStack(Stack S)
{
	if(S == NULL)
		return;
	if(S->pData != NULL)
		free(S->pData);
	free(S);
}

void MakeEmpty(Stack S)
{
	S->TopOfStack = EmptyTOS;
}

int IsEmpty(Stack S)
{
	return (S->TopOfStack==EmptyTOS) ? 1 : 0;
}

int IsFull(Stack S)
{
	return (S->TopOfStack==S->capacity-1) ? 1 : 0;
}

int Push(Stack S, PtrToNode pNode)
{
	if(IsFull(S))
		return 1;
	S->pData[++(S->TopOfStack)] = pNode;
	return 0;
}

PtrToNode Pop(Stack S)
{
	if(IsEmpty(S))
		return NULL;
	return S->pData[(S->TopOfStack)--];
}

PtrToNode Top(Stack S)
{
	if(IsEmpty(S))
		return NULL;
	return S->pData[S->TopOfStack];
}

//输入为后缀表达式
PtrToNode CreateExprTree(const char *ExprStr)
{
	int i = 0;
	Stack S;
	PtrToNode pTmp;

	S = CreateStack(50);
	while(ExprStr[i] != '\0')
	{
		pTmp = (PtrToNode)malloc(sizeof(struct Node));
		if(ExprStr[i]!='+' && ExprStr[i]!='-' && ExprStr[i]!='*' && ExprStr[i]!='/')
		{
			pTmp->value = ExprStr[i];
			pTmp->pLeft = NULL;
			pTmp->pRight = NULL;
			Push(S, pTmp);
		}
		else
		{
			pTmp->value = ExprStr[i];
			pTmp->pRight = Pop(S);
			pTmp->pLeft = Pop(S);
			Push(S, pTmp);
		}
		++i;
	}
	pTmp = Pop(S);
	DisposeStack(S);
	return pTmp;
}

void DeleteTree(PtrToNode root)
{
	if(root == NULL)
		return;
	if(root->pLeft != NULL)
		DeleteTree(root->pLeft);
	if(root->pRight != NULL)
		DeleteTree(root->pRight);
	free(root);
}

//打印中缀表达式
void PrintExprTree(PtrToNode root)
{
	if(root == NULL)
		return;
	if((root->value=='*' || root->value=='/') && (root->pLeft->value=='+' || root->pLeft->value=='-'))
		putchar('(');
	PrintExprTree(root->pLeft);
	if((root->value=='*' || root->value=='/') && (root->pLeft->value=='+' || root->pLeft->value=='-'))
		putchar(')');

	putchar(root->value);

	if((root->value=='*' || root->value=='/') && (root->pRight->value=='+' || root->pRight->value=='-'))
		putchar('(');
	PrintExprTree(root->pRight);
	if((root->value=='*' || root->value=='/') && (root->pRight->value=='+' || root->pRight->value=='-'))
		putchar(')');
}

void main()
{
	char a[50];
	PtrToNode pNode;

	fputs("请输入后缀表达式: ", stdout);
	scanf("%s", a);
	pNode = CreateExprTree(a);
	fputs("中缀表达式为: ", stdout);
	PrintExprTree(pNode);
	putchar('\n');
	DeleteTree(pNode);
}