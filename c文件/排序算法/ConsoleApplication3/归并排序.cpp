#include<sort.h>

void merge(int a[],int l,int r,int mid)//合并
{
	int i,j,k;
	int *p=new int [r-l+1];
	for (i=l;i<=r;i++)
	{
		p[i-l]=a[i];
	}
	i=l,j=mid+1,k=l;
	while(i<=mid&&j<=r)
	{
		if(p[i-l]<p[j-l]) {
			a[k]=p[i-l];
			i++;
		}
		else {
			a[k]=p[j-l];j++;
		}
		k++;


	}
	while (i<=mid)
	{
		a[k++]=p[i-l];
		i++;
	}
	while (j<=r)
	{
		a[k++]=p[j-l];
		j++;
	}
	
	delete [] p;

}
void merge_sort(int a[],int l,int r)//分治
{
	if (l>=r)
	{
		return;
	}
	int mid=(l+r)/2;
	merge_sort(a,l,mid);
	merge_sort(a,mid+1,r);
	merge(a,l,r,mid);
	
}
void merge_sort(int a[],int n)//重写
{
	merge_sort(a,0,n-1);
}