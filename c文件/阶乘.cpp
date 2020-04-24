#include<stdio.h>
int jp( int n); 
int main()
{
	int n,x;
	scanf("%d",&n);
x=	jp(n);
printf("%d",x);
	
}
int jp(int n)
{
	int l;
	if(n==1)
	return 1;
	l=n*jp(n-1);
	return l;
	
}
