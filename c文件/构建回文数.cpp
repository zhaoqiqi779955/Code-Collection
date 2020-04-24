#include<stdio.h>
#include<iostream>
#include<math.h>
int prime(int n);
void f(int t,int n,int sd,int ju,int a,int b);
using namespace std;
int main()
{
	int a,b;
  cin>>a>>b;
	int t=1,p;
	p=a;
	if(b%10==0) b=b-1;
	while(p>=10) 
	{
		t=t*10;
		p=p/10;
	} 
  	while(t<b)
	 {
	 	f(1,t,0,0,a,b);
	 	 t=t*10;
	 }
	 
	
	
}
void f(int t,int n,int sd,int ju,int a,int b)
{
	int sum;
  if(t==n) 
  {
  	 for(int i=0;i<10;i++)
  	 {
  	 	 sum=sd+i*t;
  	 	 if(sum>=a&&sum<=b)
  	 	  if(prime(sum))
  	 	 cout<<sum<<endl;
	   }
  }
 else if(t>n) 
   {
   	 if(sd>=a&&sd<=b) 
   	  if(prime(sd))
   	   cout<<sd<<endl;
   }
    else 
   {
   	  if(ju) 
   	   {
   	   	 sum=sd;
   	   	 f(t*10,n/10,sum,1,a,b);
		}
   
     for(int i=1;i<10;i++)
      {
	  
        sum=t*i+n*i+sd;
        f(t*10,n/10,sum,1,a,b);
	}
  } 

}
int prime(int n)
{
	for(int i=2;i<=sqrt(n);i++)
	 if(n%i==0) return 0;
	 return 1;
	
}
