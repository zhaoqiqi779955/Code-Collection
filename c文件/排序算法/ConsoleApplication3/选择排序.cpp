#include<sort.h>
void SelectSort(int a[],int n)//a是参与排序数组，n是个数
{
	for (int i=0;i<n-1;i++)
	{
		int k=i;//k记录本轮排序最小值下标
		for (int j=i+1;j<n;j++)
		{
			if(a[j]<a[k]) k=j;
			
		}
		//交换
		int t=a[i];
		a[i]=a[k];
		a[k]=t;
	}
	

}
