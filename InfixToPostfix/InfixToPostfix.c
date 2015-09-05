#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "StackArray.h"

void InfixToPostfix(const char *infix, int length, char *postfix)
{
	int i, j;
	Stack stack;

	if(NULL==infix || length <0 || NULL==postfix)
	{
		return;
	}
	stack = CreateStack(50);
	for(j=0,i=0; i<length; ++i)
	{
		if(IsFull(stack))
			break;
		switch(infix[i])
		{
		case '+':
		case '-':
			while(!IsEmpty(stack) && Top(stack)!='(')
				postfix[j++] = TopAndPop(stack);
			Push(infix[i], stack);
			break;
		case '*':
		case '/':
		case '(':
			Push(infix[i], stack);
			break;
		case ')':
			if(IsEmpty(stack))
				break;
			while(Top(stack) != '(')
				postfix[j++] = TopAndPop(stack);
			Pop(stack);
			break;
		default:	//输入为操作数
			postfix[j++] = infix[i];
			break;
		}
	}
	while(!IsEmpty(stack))
		postfix[j++] = TopAndPop(stack);
	postfix[j] = '\0';
	DisposeStack(stack);
}

void main()
{
	char infix[50];
	char postfix[50];

	strncpy(infix, "", 50);
	strncpy(postfix, "", 50);

	fputs("请输入中缀表达式：", stdout);
	gets(infix);
	InfixToPostfix(infix, strlen(infix), postfix);
	fputs("后缀表达式为：", stdout);
	puts(postfix);
}