#include<stdio.h>
struct tube{
	int len;
	int width;
	long int number;
} tb[10];
typedef struct tube tu;
int main()
{
	
	int t,n,i,j,k;
	int y;
	long int z;

	scanf("%d",&t);
	while(t-->0)
	{
		scanf("%d",&n);
		 
		for(i=0;i<n;i++)
		{
			scanf("%d%d%ld",&tb[10].len,&y,&z);
	
		tb[i].width=y;
		tb[i].number=z;	
			
		}
		k=0;
		for(i=1;i<n;i++)
			if(tb[k].len<tb[i].len)
			 k=i;
			 else if(tb[k].len==tb[i].len)
			       {
				   if(tb[k].width>tb[i].width)
			       k=i;
			       else if(tb[k].width==tb[i].width)
			         		if(tb[k].number<tb[i].number)
			         		k=i;
			         	}
			         	
		        
	printf("%ld",tb[k].number);
	if(t>0)
	printf("\n")	;	         		
			
		
	}
	
	
 } 
