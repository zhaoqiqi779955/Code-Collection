#include<stdio.h>

int main()
{
	int a[4],i;
	a[0]=0+0+0+1;
	a[1]=1+0+0+1;
	a[2]=1+1+0+1;
	a[3]=1+0+1+0;

	for(i=0;i<4;i++)
	if(a[i]>=3)
	printf("%c",i+'A');
  }
