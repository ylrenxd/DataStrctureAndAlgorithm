#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

typedef int ElementType;

static void Swap(ElementType *a, ElementType *b)
{
	ElementType tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

static void InsertionSort(ElementType a[], unsigned long N)
{
	unsigned long i, j;
	ElementType tmp;

	for(i=1; i<N; ++i)
	{
		tmp = a[i];
		for(j=i; j>=1 && tmp<a[j-1]; --j)
			a[j] = a[j-1];
		a[j] = tmp;
	}
}

static ElementType Median3(ElementType a[], unsigned long left, unsigned long right)
{
	unsigned long media;

	media = (left + right)/2;
	if(a[left] > a[media])
		Swap(&a[left], &a[media]);
	if(a[left] > a[right])
		Swap(&a[left], &a[right]);
	if(a[media] > a[right])
		Swap(&a[media], &a[right]);

	Swap(&a[media], &a[right-1]);
	return a[right-1];
}

static void QSort(ElementType a[], unsigned long left, unsigned long right)
{
	unsigned long i, j;
	ElementType pivot;

	if(right-left+1 > 10)
	{
		pivot = Median3(a, left, right);
		i = left;
		j = right - 1;
		while(1)
		{
			while(a[++i] < pivot);
			while(a[--j] > pivot);
			if(i < j)
				Swap(&a[i], &a[j]);
			else
				break;
		}
		Swap(&a[i], &a[right-1]);
		QSort(a, left, i-1);
		QSort(a, i+1, right);
	}
	else	//对于小数组，直接采用插入排序
		InsertionSort(a+left, right-left+1);
}

void QuickSort(ElementType a[], unsigned long N)
{
	QSort(a, 0, N-1);
}

const unsigned long NUM = 1<<25;	//32*sizeof(long)Mb

//注：必须使用Release模式进行运行比较
int main()
{
	int *a = new int[NUM];
	cout<<"正在初始化数据...\n";
	srand(21845U);
	for(unsigned long i=0; i<NUM; ++i)
		a[i] = rand();

	clock_t s, t;

	cout<<"std::sort()开始排序...\n";
	s = clock();
	sort(a, a+NUM);
	t = clock();
	cout<<"std::sort()函数所用时间为："
		<<(t-s)/(double)CLOCKS_PER_SEC<<endl;

	vector<int> va(a, a+NUM);

	cout<<"\n正在初始化数据...\n";
	srand(21845U);
	for(unsigned long i=0; i<NUM; ++i)
		a[i] = rand();
	cout<<"QuickSort()开始排序...\n";
	s = clock();
	QuickSort(a, NUM);
	t = clock();
	cout<<"QuickSort()函数所用时间为："
		<<(t-s)/(double)CLOCKS_PER_SEC<<endl;

	cout<<"\n验证排序结果...\n";
	unsigned long i;
	for(i=0; i<NUM; ++i)
		if(va[i] != a[i])
			break;
	if(i != NUM)
		cout<<"排序结果不相同!"<<endl;
	else
		cout<<"排序结果相同!"<<endl;

	delete[] a;
	system("pause");
	return 0;
}