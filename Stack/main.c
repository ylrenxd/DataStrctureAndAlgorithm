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

	S = CreateStack(50);	//����ʵ�ֵ�Stack��Ҫ��С����
	printf("������һ���ַ���:\n");
	scanf("%c", &c);
	while(c != '\n')
	{
		Push(c, S);
		scanf("%c", &c);
	}

	printf("��ת֮����ַ���Ϊ:\n");
	while(!IsEmpty(S))
	{
		str[i++] = Top(S);
		Pop(S);
	}
	str[i] = '\0';
	printf("%s\n", str);

	DisposeStack(S);
}