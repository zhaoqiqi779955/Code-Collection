#include<sort.h>
void insert_sort(int a[],int begin,int end)
{
	int i,j;
	for (i=begin;i<=end;i++)
	{
		int t=a[i];
		for (j=i-1;j>=begin;j--)
		{
			if (a[j]>t)
			{
				a[j+1]=a[j];
			}
			else break;
		}
		a[j+1]=t;
	}

}
void insert_sort(int a[],int len)
{
	int i,j;
	for (i=1;i<len;i++)
	{
		int t=a[i];
		for (j=i-1;j>=0;j--)
		{
			if (a[j]>t)
			{
				a[j+1]=a[j];
			}
			else break;
		}
		a[j+1]=t;
	}


}
