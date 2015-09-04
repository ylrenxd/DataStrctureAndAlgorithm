#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void _GetPostTraverse(const char *PreOrder, const char *InOrder, int length, char *PostOrder, int *index)
{
	char root;
	int i;

	if(0 == length)
		return;
	root = *PreOrder;
	for(i=0; i<length && InOrder[i]!=root; ++i);	//������������Ѱ�Ҹ��ڵ�λ��i

	_GetPostTraverse(PreOrder+1, InOrder, i, PostOrder, index);	//������
	_GetPostTraverse(PreOrder+1+i, InOrder+i+1, length-1-i, PostOrder, index);	//������
	PostOrder[(*index)++] = root;
}

//��֪������ǰ�������������������������
void GetPostTraverse(const char *PreOrder, const char *InOrder, int length, char *PostOrder)
{
	int index = 0;

	if(NULL == PostOrder)
		return;
	_GetPostTraverse(PreOrder, InOrder, length, PostOrder, &index);
	PostOrder[index] = '\0';
}

static void _GetPreTraverse(const char *PostOrder, const char *InOrder, int length, char *PreOrder, int *index)
{
	char root;
	int i;

	if(0 == length)
		return;
	root = PostOrder[length-1];
	PreOrder[(*index)++] = root;
	for(i=0; i<length && InOrder[i]!=root; ++i);	//������������Ѱ�Ҹ��ڵ�λ��i

	_GetPreTraverse(PostOrder, InOrder, i, PreOrder, index);	//������
	_GetPreTraverse(PostOrder+i, InOrder+i+1, length-1-i, PreOrder, index);	//������
}

//��֪������������������������ǰ��������
void GetPreTraverse(const char *PostOrder, const char *InOrder, int length, char *PreOrder)
{
	int index = 0;

	if(NULL == PreOrder)
		return;
	_GetPreTraverse(PostOrder, InOrder, length, PreOrder, &index);
	PreOrder[index] = '\0';
}

void main()
{
	char PreOrder[27];
	char InOrder[27];
	char PostOrder[27];
	
	fputs("������ǰ��������У�", stdout);
	while(gets(PreOrder))
	{
		fputs("����������������У�", stdout);
		gets(InOrder);
		strcpy(PostOrder, InOrder);
		GetPostTraverse(PreOrder, InOrder, strlen(PreOrder), PostOrder);
		fputs("������������Ϊ��", stdout);
		puts(PostOrder);

		strcpy(PreOrder, InOrder);
		GetPreTraverse(PostOrder, InOrder, strlen(PostOrder), PreOrder);
		fputs("������֤��ǰ���������Ϊ��", stdout);
		puts(PreOrder);
		fputs("\n������ǰ��������У�", stdout);
	}
}