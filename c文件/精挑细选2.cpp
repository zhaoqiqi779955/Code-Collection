#include<stdio.h>
int main()
{
	int t;
	int len,wid;
	
	long int num;
	scanf("%d",&t);
	while(t-->0)
	{
		int len1=0,wid1=0;
		long int num1=0;
		int n;
		scanf("%d",&n);
		while(n-->0)
		{
			scanf("%d%d%d",&len,&wid,&num);
			if(len1<len)
			{
				len1=len;
				wid1=wid;
				num1=num;
				
			}
			else if(len1==len)
			 		if(wid1>wid)
			 			{
				len1=len;
				wid1=wid;
				num1=num;
				
			}
			 		else if(wid==wid1)
			 				if(num>num1)
			 					{
									len1=len;
									wid1=wid;
									num1=num;
				
								}
			 				
		}
		printf("%ld\n",num1);
	}
}
