#include<stdio.h>
int main()
{
	double sum=0,d,t;
	int n,k,i;
	scanf("%lf",&d);
	n=-2;
	  do  {
	  	n=n+3;
	  	t=sum;
		sum+=1.0/n+1.0/(n+1)-1.0/(n+2);
		
		
	} while(sum<=d);
	printf("n>=%d\n",n);
	sum=sum-(1.0/n+1.0/(n+1)-1.0/(n+2));
	n=n-3;
	while(1)
	{
		if(sum+1.0/(n+2)>d) {
		
		printf("%d ",n+1);
		if(sum+1.0/(n+2)-1.0/(n+1)>d)
		 printf("%d",n);
		 printf("\n");
		if(sum+1.0/(n+2)<d) break;
		n=n-3;
		sum=sum-(1.0/n+1.0/(n+1)-1.0/(n+2));
	}
	
}
	
}
