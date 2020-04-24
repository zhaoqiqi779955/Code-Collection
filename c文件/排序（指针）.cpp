#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n,i,j,t;
	int *pi;
	scanf("%d",&n);
  pi=(int *)malloc(n*sizeof(int));
  if(pi==NULL)
  	{printf("no suffcient memory available");
  	exit(0);
  	}
  for(i=0;i<n;i++);
  scanf("%d",pi+i);
  /*
  for(i=0;i<n-1;i++)
  	for(j=i;j<n-2;j++)
  	{
  		if(*(pi+i)<*(pi+j+1))
  			{
  				t=*(pi+i);
  				*(pi+i)=*(pi+j+1);
  				*(pi+j+1)=t;
  				
			  }
  		
  	}*/
  for(i=0;i<n;i++)
   printf("%d ",*(pi+i));
   free(pi);
}


