#include<stdio.h>
#include<iostream>
#include<math.h>
int count=0;
int f=0;
void trs(int p[],int k,int n,int s,int q);
int prime(int n);
using namespace std;
int main()
{ 
 
    
	int n,k;
	cin>>n>>k;
	int a[30];
	for(int i=0;i<n;i++)
	cin>>a[i];
	trs(a,k,n,0,0);
	cout<<count;
		
     
	}
 int prime(int n)
 {  
 	int k=sqrt(n);
 	int flag=1;
 	for(int i=2;i<=k;i++)
 	  if(n%i==0) 
	   {
	   flag=0;break;
        }
 	  if(flag) return 1;
 	  else return 0;
 	 
   
 }
 void trs(int p[],int k,int n, int s,int q)//表示从n个数中挑取看k个数 ，s表示现在已挑取个数，q用来实现从原UN集合向后取一个数 
 { 
 	static int t[20];
 	if(s==k) 
 	 { 
 	   
 	 	int sum=0;
 	 	for(int i=0;i<k;i++)
 	 	cout<<t[i]<<" ";
		 cout<<endl;
   }
	  
 	 else 
 	   for(int i=q;i<=n-k+s;i++)
 	  {
 	  	t[s]=p[i];
 	  	trs(p,k,n,s+1,i+1);
 	  	
	   }
}
	   
	   
	   
	   
	   
	   
	   
	   
	   
	   
	   
	   
	   
	   
	   
	   
	   
	   
	   
	   
	   
	   
	   
	   
	   
	   
	   
	   
	   
	   
	   
	   
 
