#include<iostream>
#include<memory.h>
using namespace std;
template <class T>
void count(T *p,int n)
{
	//����һ�γ��ֵ��������ڻ�׼�Ƚ� 
	bool state[n];
	memset(state,0,n*sizeof(bool));
	int sum[n];//���ڼ��� ��0���ʾ��λ���ظ�ͳ�� 

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
				state[j]=1;//ͳ�ƹ������ݾ���Ϊ1���������ɸѡ 
			}
		
		}
	
	 } 
	 for(int i=0;i<n;i++)
	  if(sum[i])	//sum[i]�������ʾ��λ���ǵ�һ�γ��ֵ�λ�� 
	 cout<<p[i]<<' '<<sum[i]<<endl;
}
int main()
{
	int a[10];
	for(int i=0;i<10;i++)
	cin>>a[i];
	count(a,10);
}







