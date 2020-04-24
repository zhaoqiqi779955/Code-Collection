#include<stdio.h>
#include<string.h>
int main()
{
	char *city[5]={"Wuhan","Beijing","Tianjin","Guangzhou","Shanghai"};
	int i,j;
	char *p;
	for(i=0;i<4;i++)
	for(j=0;j<4;j++)
	if(strcmp(city[j],city[j+1])>0)
	{
		p=city[j];
		city[j]=city[j+1];
		city[j+1]=p;
	}
	  for(i=0;i<5;i++)
	puts(city[i]);

 } 
