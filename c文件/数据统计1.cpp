#include<iostream>
#include<memory.h>
using namespace std;
template <class T>
void count(T *p,int n)
{
	bool state[n];
	memset(state,0,n*sizeof(bool));
	T a[n];
	int sum[n];//用于计数 
	int k=0;//k用于统计不同数据个数 
	for(int i=0;i<n;i++)
	 sum[i]=0;
	for(int i=0;i<n;i++)
	{
		if(!state[i])
		{
			a[k]=p[i];
			for(int j=0;j<n;j++)
			if(p[j]==p[i]) { 
			sum[k]++;
			state[j]=1;
			}
			k++;
		}
	
	 } 
	 for(int i=0;i<k;i++)
	 cout<<a[i]<<' '<<sum[i]<<endl;
}
int main()
{
	int a[10];
	for(int i=0;i<10;i++)
	cin>>a[i];
	count(a,10);
}







