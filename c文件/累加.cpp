#include<stdio.h>
int add(int n);
int main()
{
	int x;
	scanf("%d",&x);
	printf("%d",add(x));
	
}
int add(int n)
{

	int sum;
	if(n==1)
	return 1;
	sum=n+add(n-1);
	return sum;
	
}
