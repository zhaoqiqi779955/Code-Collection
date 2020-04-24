#define max 10000
#include<stdio.h>
#include<memory.h>
int main ()
{
	bool prime[max];
	int n;
	int i,j;//i指向最新质数 ，j用来循环计数 
	memset(prime,true,max*sizeof(bool));
	prime[0]=0;
	prime[1]=0;
	prime[2]=1;
	for(i=2;i<=max;i++)
	if(prime[i])
	for(j=2;i*j<=max;j++)
	prime[i*j]=0;
	scanf("%d",&n);
	if(prime[n]) printf("yes");
	else printf("no");
	

	
	
}
