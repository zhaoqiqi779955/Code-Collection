#include<stdio.h>
int sum(int x);
int main(void)
{
	
	int x,i,sum=0;
	scanf("%d",&x);
	if(x==0)
	  i=2;
	  else i=1;
	
	for(;i<=100;i++)
	{
		sum+=i++;
	}
	printf("%d",sum);
	
}

