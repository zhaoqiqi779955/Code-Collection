#include<sort.h>
#include<vector>
using namespace std;
void quick_sort(int a[],int n)
{

	quick_sort(a,0,n-1);
}
void quick_sort(int a[],int low,int high)
{
	if(low>=high) return;
	int tem=a[low];
	int p=low,q=high;
	
	while (p<q)
	{
		while(a[q]>=tem&&q>p) q--;
		if (p<q)
		{
			a[p]=a[q];
			p++;
		}
		while (a[p]<tem&&p<q) p++;
		if (p<q)
		{
			a[q]=a[p];
			q--;
		}

	}
	
	a[p]=tem;
	
	quick_sort(a,low,p-1);
	quick_sort(a,p+1,high);


}
void quick_sort_improve(int a[],int n)
{

	quick_sort_improve(a,0,n-1);
}
void swap(int a [],int i,int j)
{
	int tem=a[i];
	a[i]=a[j];
	a[j]=tem;

}
void select_loc(int a[],int low,int high)
{
	
	int mid=(low+high)/2;
	if(a[mid]>a[low]) swap(a,mid,low);
	if(a[low]>a[high]) swap(a,low,high);
	if(a[mid]>a[low]) swap(a,mid,low);
	
}
void quick_sort_improve(int a[],int low,int high)
{
	if(high-low<8){
		insert_sort(a,low,high);
		return;
	}
	select_loc(a,low,high);
	int tem=a[low];
	int p=low,q=high-1;

	while (p<q)
	{
		while(a[q]>=tem&&q>p) q--;
		if (p<q)
		{
			a[p]=a[q];
			p++;
		}
		while (a[p]<tem&&p<q) p++;
		if (p<q)
		{
			a[q]=a[p];
			q--;
		}

	}

	a[p]=tem;

	quick_sort(a,low,p-1);
	quick_sort(a,p+1,high);

}