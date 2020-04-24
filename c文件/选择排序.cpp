#include<stdio.h>
#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
  int t;
  cin>>t;
  while(t-->0) {
  	int a[100],n;
  	cin>>n;
  	for(int i=0;i<n;i++)
  	cin>>a[i];
  	int min,k;
  	for(int i=0;i<n-1;i++) {
	   min=a[i];
	   k=i;
  	  for(int j=i+1;j<n;j++) 
		if(a[j]<min) {
			min=a[j];
			k=j;
		}
		a[k]=a[i];
		a[i]=min;
		
		 for( k=0;k<n-1;k++)
		 cout<<a[k]<<" " ;
		 cout<<a[k]<<endl;
  }
}
}
