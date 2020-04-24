#include<stdio.h>
int main()
{
	int i,j,k=0,a[100],t,x;
loop:	scanf("%d",&x);
if(x!=0) 
{
	a[k]=x;
	k++;
	goto loop;
}
	/*int a[10];
	puts("please input the numbers");
	for(i=0;i<=k-1;i++)
	scanf("%d",&a[i]);*/
	for(j=1;j<k;j++)
	   for(i=0;i<k-1;i++)
	   
		if(a[i]<a[i+1])
	    {t=a[i];
	    a[i]=a[i+1];
	    a[i+1]=t;
	    } 
	  

   for(i=0;i<=9;i++)
   printf("%d ",a[i]);
 } 
