#include<iostream>
using namespace std;
void sort_insert(int a[],int len)
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


	for (int i=0;i<len;i++)
	{
		cout<<a[i]<<" ";
	}


}
int main()
{

	int a[100];
	for (int i=0;i<10;i++)
	{
		cin>>a[i];
	}
	sort_insert(a,10);



}