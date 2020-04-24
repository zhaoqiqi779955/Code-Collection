#include<sort.h>
void bubble_sort(int a[],int n)
{
	for (int i=0;i<n-1;i++)
	{
		for (int j=i;j<n-1;j++)
		{
			if(a[j]>a[j+1]){
				int t=a[j];
				a[j]=a[i];
				a[i]=t;
			}
		}
	}
}