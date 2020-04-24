/*#include<iostream>
using namespace std;
void Shellinsert(int a[],int gap,int len)
{

	int i;
	for (i=0;i<gap;i++)
	{
		for (int j=i+gap;j<len;j=j+gap)
		{
			int tem=a[j];
			int k;
			for ( k=j-gap;k>=0;k=k-gap)
			{
				if (a[k]<tem)
				{
					a[k+gap]=a[k];
				}
				else break;
			}
			if(k>=0) a[k+gap]=tem;
			else a[k+gap]=tem;

		}
	}
	for (int i=0;i<len;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
}
void shell_sort(int a[],int len )
{
	int gap=len/2;
	while(gap>=1)
	{
		Shellinsert(a,gap,len);
		gap=gap/2;
	}

}
int main()
{
	int t;
	cin>>t;
	int a[100];
	while (t--)
	{
		int n;
		cin>>n;
		for (int i=0;i<n;i++)
		{
			cin>>a[i];

		}
		shell_sort(a,n);
		cout<<endl;
	}

}*/