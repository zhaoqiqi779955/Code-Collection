#include<stdio.h>
#define N 100
#include<memory.h>
int maxbit(int a[],int n)
{
	int max=a[0];
	for(int i=1;i<n;i++)
	if(max<a[i]) max=a[i];
	int k=1;
	while(max>=10)
	{   k++;
		max/=10;
	}
	return k;
    
 } 
int main()
{
	int count[10];
	int resort[N];
	int a[N];
	int n,i;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	scanf("%d",&a[i]);
	int maxb=maxbit(a,n);
	int t=1;
	while(maxb-->0)
	{
		memset(count,0,sizeof(count));
	
	  for(i=0;i<n;i++)
	  {
	  	int x=a[i]/t%10;
	  	count[x]++;
	  }
	  	for(int j=1;j<10;j++)
	  	count[j]=count[j]+count[j-1];
	for(i=n-1;i>=0;i--)
	 
	{
			int x=a[i]/t%10;
			resort[count[x]-1]=a[i];
			count[x]--;
			
		 
		  }
	 for(int i=0;i<n;i++)
	 a[i]=resort[i];
		t*=10;
	}
	 
  for(i=0;i<n;i++)
  printf("%d ",a[i]);	  
	
	
	
}
