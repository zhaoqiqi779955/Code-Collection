#include<stdio.h>
#include<math.h>
int main()
{
	int x,i,k,flag;
	puts("please input a number\n");
	loop:scanf("%d",&x);
	flag=1;
	for(i=2;i<=sqrt(x);i++)
	   if(x%i==0)
	   {flag=0;
	   break; 
	   } 
	   
	   if(flag==1)
	   printf("%d是素数\n",x);
	   else printf("%d不是素数\n",x);
	   goto loop;
	   return 0;
	
 } 
