#include<iostream>
#include<string>
#include<time.h>
#include<math.h>
#include"sort.h"
int sys=0;
#define  random(x) (rand()%x)//�����
using namespace std;
void show(int a[],int n)
{
	int flag=0;
	for (int i=0;i<n;i++)
	{
		flag++;
		cout<<a[i];
		if(flag==20) {
			flag=1;
			cout<<endl;
		}
		else cout<<" ";
	}
	cout<<endl;
}
void show(int a[],int begin,int end)
{
	int flag=0;
	for (int i=0;i<begin;i++)
	{
		flag++;
		
		cout<<a[i];
		if(flag==20) {
			flag=1;
			cout<<endl;
		}
		else cout<<" ";
		if(i==end) cout<<" | ";
	}
	cout<<endl;
}

double test( void (*sort)(int a[],int n),int a[],int n,int mag)//magΪ�Ŵ���
{
	time_t start,end;
	int *tem=new int [n];

	//�������
	start=clock();
	for (int i=0;i<mag;i++)
	{
		for (int j=0;j<n;j++)
		{
			tem[j]=a[j];
		}
	}
	end=clock();
	time_t gap=end-start;
	
	start=clock();
	for (int j=0;j<mag;j++)
	{
		sort(a,n);
		
		for (int i=0;i<n;i++)//��֤ÿ���������ݷֲ������ͬ
		{
			a[i]=tem[i];
		}
		
	}
	end=clock();
	time_t dur=end-start-gap;//��ȥ���ƴ��������
	
	delete [] tem;
	
	return (double) dur/mag;
	
}
int *getArray(int n)//������������飬����n��Ԫ��
{
	int *p=new int [n];
	int seed=(int) time(0);
	srand(seed+sys++);
	for (int i=0;i<n;i++)
	{
		p[i]=random(1000);
	} 
	return p;
}

