#include<stdio.h> 
	int main()
	{
	int i,j,k,t;
	int a[10];
	puts("please input the numbers");
	for(i=0;i<=9;i++)
	scanf("%d",&a[i]);
	for(j=0;j<9;j++)
	   for(i=j+1;i<9;i++)
	   
		if(a[j]<a[i+1])
	    {t=a[j];
	    a[j]=a[i+1];
	    a[i+1]=t;
	    } 
	  

   for(k=0;k<=9;k++)
   printf("%d ",a[k]);
 } 
