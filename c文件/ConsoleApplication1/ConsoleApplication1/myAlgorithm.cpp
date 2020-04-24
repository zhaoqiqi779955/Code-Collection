#include"myAlgorithm.h"
#include<vector>
#include<queue>
using namespace  std;
int digitk(int n,int b)//b为当前位
{
	int t=n/b;
	t=t%10;
	return t;

}
void radixSort(int a[],int n)
{
	queue<int> que[10];
	
	int max=a[0];
	for (int i=0;i<n;i++)
	{
		if(a[i]>max) max=a[i];
	}
	int t=1,k=1;//求最高位k
	while (max>=10)
	{
		max=max/10;
		k=k*10;
	}
	while (t<=k)
	{
		for (int i=0;i<n;i++)
		{
			int h=digitk(a[i],t);
			que[h].push(a[i]);
		}
		int i=0;
		for (int j=0;j<10;j++)
		{
			while (!que[j].empty())
			{
				a[i++]=que[j].front();
				que[j].pop();
			}
		}
		t++;
	}
	
	
}