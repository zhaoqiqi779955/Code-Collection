#include<iostream>
#include<memory.h>
using namespace std;
template <class T>
void count(T *p,int n)
{
	//将第一次出现的数据用于基准比较 
	bool state[n];
	memset(state,0,n*sizeof(bool));
	int sum[n];//用于计数 ，0则表示该位置重复统计 

	for(int i=0;i<n;i++)
	 sum[i]=0;
	for(int i=0;i<n;i++)
	{
		if(!state[i])
		{
			
			for(int j=0;j<n;j++)
			if(!state[j])
				if(p[j]==p[i]) { 
				sum[i]++;
				state[j]=1;//统计过的数据均置为1，方便后续筛选 
			}
		
		}
	
	 } 
	 for(int i=0;i<n;i++)
	  if(sum[i])	//sum[i]非零则表示该位就是第一次出现的位置 
	 cout<<p[i]<<' '<<sum[i]<<endl;
}
int main()
{
	int a[10];
	for(int i=0;i<10;i++)
	cin>>a[i];
	count(a,10);
}







