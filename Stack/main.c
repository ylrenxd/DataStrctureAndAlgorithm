#define _CRT_SECURE_NO_WARNINGS
//#include "StackList.h"
#include "StackArray.h"
#include <stdio.h>

void main()
{
	Stack S;
	char c;
	char str[20];
	int i = 0;

	S = CreateStack(50);	//数组实现的Stack需要大小参数
	printf("请输入一个字符串:\n");
	scanf("%c", &c);
	while(c != '\n')
	{
		Push(c, S);
		scanf("%c", &c);
	}

	printf("反转之后的字符串为:\n");
	while(!IsEmpty(S))
	{
		str[i++] = Top(S);
		Pop(S);
	}
	str[i] = '\0';
	printf("%s\n", str);

	DisposeStack(S);
}