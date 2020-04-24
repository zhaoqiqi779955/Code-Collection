#include<stdio.h>
int main()
{
	int m,n,i=0,j=0,q,p;
	scanf("%d%d",&m,&n);
	if(m%2==1) i++;
	if(m>=2)
	 {
	 loop:  q=m/2,i++;
	 if(q>=1) goto loop;
	 if(n%2==1) j++;
	if(n>=2)
	 {
	 poop:  q=n/2,j++;
	 if(q>1) goto poop;
    }
}
printf("%d",i+j);
}
	  
	

