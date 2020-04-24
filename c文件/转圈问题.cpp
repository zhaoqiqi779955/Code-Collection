#include<stdio.h>
#include<iostream>
using namespace std;
int main()
{
	bool a[20];
	int gap;
	int k;
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	 a[i]=1;
	 cin>>gap;
	 int count=0;
	 int i=1;
	  k=0;
	 while(count<n)
	 {  i++;
	   if(i>n) i=1;
	 	if(a[i]) k++;
	 	if(k==gap) {
	 		a[i]=0;
	 		cout<<i<<" ";
	 		k=0;
	 		count++;
		 }
	 }
}
