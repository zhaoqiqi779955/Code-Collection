#include "sort.h"
//计数排序
void counting_sort(int a[], int b[], int k, int n)//k为最大排序值，默认下限为0，n为排序个数
{
	int* c = new int[k + 1];
	for (int i = 0; i <=k; i++)
	{
		c[i] = 0;

	}
	for (int i = 0; i < n; i++)
	{
		c[a[i]] += 1;
	}
	for (int i = 1; i <= k; i++)
	{
		c[i] = c[i] + c[i - 1];
	}
	for (int i = n - 1; i >= 0; i--)
	{
		b[c[a[i]]-1]=a[i];
		c[a[i]] -= 1;
	}
	delete [] c;
}
void radix_sort(int a[], int n)
{
	
}