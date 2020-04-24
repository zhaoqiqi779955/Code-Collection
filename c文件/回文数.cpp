#include<stdio.h>
int main()
{
	int t,n,i,j,a[10];
	scanf("%d",&t);
	while(t-->0)
	{
		i=0;
		scanf("%d",&n);
		while(n!=0)
		{
			a[i++]=n%10;
			n/=10;
			
		}
		i--;
	
		for(j=0;j<=i;j++,i--)
		  if(a[i]!=a[j])
		   break;
		 
		   if(j>=i)
		   printf("Yes\n");
		   else printf("No\n");
		 
		
		
	}
}
