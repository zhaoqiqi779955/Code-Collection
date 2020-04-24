#include<stdio.h>
int main()
{
	int m,n,i=0,j=0,q,p;
	scanf("%d%d",&m,&n);
	if(m%2==1) i++;
	if(m>=2) 
	{
		while(m/2>=1)
		{
			i++;
			m=m/2;
		}
	}
	if(n%2==1) j++;
	if(n>=2) 
	{
		while(n/2>=1)
		{
			i++;
			n=n/2;
		}
	}

printf("%d",i+j);
}
