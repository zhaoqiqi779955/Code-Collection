#include<stdio.h>
#include<memory.h>
#include<math.h>
int main()
{
	int i,j,a[10000],t,k,s;
	double n;
	scanf("%lf",&n);
	memset(a,0,10000*sizeof(int));
	for(i=2;i<10000;i++)
	a[i-2]=i;
	j=0;//记录t下标; 
	t=a[j];//t记录质数 
	while(t!=0)
  	{
  		k=j;
  		a[k++]=t;
  		for(i=j+1;a[i]!=0;i++)
		 if(a[i]%t!=0)
		 {
		 	a[k++]=a[i];
		 }
		 memset(a+k,0,4*sizeof(int));
  		j++;
  		t=a[j];
	  }
	  s=0;
	  for(i=(int)(n/log(n)*0.8-1);i<n/log(n)*1.2-1;i++)
	  if(n==a[i])
	   s=1;
	   if(s) printf("yes");
	       else printf("no");
	    
	  
}

