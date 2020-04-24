#include<stdio.h>
int main()
{
	
	int n1,n2,c0=0,c1=0,c2=0,c3=0,c4=0,c5=0,c6=0,c7=0,c8=0,c9=0;
	int n,s,p;
	scanf("%d%d",&n1,&n2);
	
	for(n=n1;n<=n2;n++)
	{
		s=n;
	  do	{
				p=s%10;
		 switch(p)
	    	{
			
			case 0:c0++;
				break;
				case 1: c1++;
				break;
				case 2: c2++;
				break;
				case 3:c3++;
				break;
				case 4:c4++;
				break;
				case 5:c5++;
				break;
				case 6:c6++;
				break;
				case 7:c7++;
				break ;
				case 8:c8++;
				break;
				case 9:c9++;
		    	break;
		    	
					
		 } 
		 s=s/10;
 	   }while(s!=0);
 }
	 
	 printf("0:%d\n1:%d\n2:%d\n3:%d\n4:%d\n5:%d\n6:%d\n7:%d\n8:%d\n9:%d",c0,c1,c2,c3,c4,c5,c6,c7,c8,c9);
}
