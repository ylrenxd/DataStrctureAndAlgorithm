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
	for(i=0; i<length && InOrder[i]!=root; ++i);	//在中序序列中寻找根节点位置i

	_GetPostTraverse(PreOrder+1, InOrder, i, PostOrder, index);	//左子树
	_GetPostTraverse(PreOrder+1+i, InOrder+i+1, length-1-i, PostOrder, index);	//右子树
	PostOrder[(*index)++] = root;
}

//已知二叉树前序、中序遍历结果，求后序遍历结果
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
	for(i=0; i<length && InOrder[i]!=root; ++i);	//在中序序列中寻找根节点位置i

	_GetPreTraverse(PostOrder, InOrder, i, PreOrder, index);	//左子树
	_GetPreTraverse(PostOrder+i, InOrder+i+1, length-1-i, PreOrder, index);	//右子树
}

//已知二叉树后序、中序遍历结果，求前序遍历结果
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
	
	fputs("请输入前序遍历序列：", stdout);
	while(gets(PreOrder))
	{
		fputs("请输入中序遍历序列：", stdout);
		gets(InOrder);
		strcpy(PostOrder, InOrder);
		GetPostTraverse(PreOrder, InOrder, strlen(PreOrder), PostOrder);
		fputs("后续遍历序列为：", stdout);
		puts(PostOrder);

		strcpy(PreOrder, InOrder);
		GetPreTraverse(PostOrder, InOrder, strlen(PostOrder), PreOrder);
		fputs("反向验证，前序遍历序列为：", stdout);
		puts(PreOrder);
		fputs("\n请输入前序遍历序列：", stdout);
	}
}