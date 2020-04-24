#include<stdio.h>
#include<iostream>
#define N 10
using namespace std;
void quick_sort(int a[],int , int );
int main(int argc, char *argv[]) 
{

	int a[N];
	int i,j;
	for(i=0;i<N;i++)
	 cin>>a[i];
	 quick_sort(a,0,N-1);
	 for(i=0;i<N;i++)
	 cout<<a[i]<<' ';
	
}
void quick_sort(int  a[],int b,int l) 
{
	
	
if(b<l)	{
	int x,i,j;
	i=b;j=l;x=a[b];
		
		while(i<j){
				while(a[j]>=x&&i<j)
					j--;
					if(i<j)
		  			a[i++]=a[j];
				while(a[i]<x&&i<j)
					i++;
				if(i<j)	a[j--]=a[i];
		
		
	}
	a[i]=x;
	quick_sort(a,b,i-1);
	quick_sort(a,i+1,l);
}
}




