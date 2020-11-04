
#ifndef MY_SORT
#define  MY_SORT
#include "toolkit.h"
template <typename T>
int partition(T a[], int low, int high)
{
	int i = low - 1;
	int x = a[high];
	for (int j = low; j < high; j++)
	{
		if (a[j] <= x) {
			i++;
			exchange(a[i], a[j]);
		}
	}
	exchange(a[i + 1], a[high]);
	return i + 1;
}
template <typename T>
void quick_sort(T a[], int low, int high)
{
	if (low >= high) return;
	int rd = randint(low, high+1);
	exchange(a[rd], a[high]);
	int mid = partition(a, low, high);
	quick_sort(a, low, mid - 1);
	quick_sort(a, mid+1, high);

}

void counting_sort(int a[], int b[], int k, int n);//k为最大排序值，默认下限为0，n为排序个数
void radix_sort(int a[], int n);
template <class T>
void insert_sort(T a[],int n)
{
	if(n<=1)
		return;
	for (int i = 1; i < n;i++)
	{

		T tem = a[i];
		int j;
		for ( j = i - 1; j >= 0;j--){
			if(a[j]>tem){
				a[j + 1] = a[j];
			}
			else
				break;
		}
		a[j + 1] = tem;
	}
}
template <class T>
void bubble_sort(T a[], int n)
{
	for (int i = 1; i < n; i++)
	{
		for (int j=0;j<n-i;j++)
		{
			if (a[j] > a[j + 1])
				swap(a[j], a[j + 1]);
		}
	}
}
#endif