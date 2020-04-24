#include<stdio.h>
#include<stdlib.h>
int main(void) 
{
	int n,t,*pi,i,j;
	puts("input the number of students");
	scanf("%d",&n);
	pi=(int *)malloc(n*sizeof(int));
	if(pi==0)
	{
	
	printf("there is insufficient memory");
	exit(0);
	}
	puts("input the scores of students");
for(i=0;i<n;i++)
scanf("%d",pi+i);
for(i=1;i<n;i++)
  for(j=0;j<n-1;j++)
  if(*(pi+j)<*(pi+j+1))
  {
  	t=*(pi+j);
  	*(pi+j)=*(pi+j+1);
  	*(pi+j+1)=t;
  }
puts("Rank:");
for(i=0;i<n;i++)
	printf("%d\n",*(pi+i));
printf("max:\n%d\nmin:\n%d",*(pi),*(pi+n-1));
free(pi);
return 0;

}
