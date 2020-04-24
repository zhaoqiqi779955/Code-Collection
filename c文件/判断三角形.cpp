#include<stdio.h>
#include<math.h>
int main()
{
	double a,b,c,t,f,s,p,e=0.001;
	int x,i=0;
	scanf("%d",&x);
	while(i<x)
	{
	
scanf("%lf%lf%lf",&a,&b,&c);
if(a<b)
{
t=a;
a=b;
b=t;
}
if(b<c)
{

t=b;
b=c;
c=t;
}
if(a<b)
{
t=a;
a=b;
b=t;
}
f=(a+b+c)/2;
if(a>=b+c)
{

printf("no triangle");
  putchar('\n');
continue;
}
 else if(fabs(a-b)<e&&fabs(a-c)<e)
          printf("equilateral triangle,");
      else 
	      if(fabs(a-b)<e||fabs(a-c)<e||fabs(b-c)<e)
                 if(fabs(a*a-b*b-c*c)<e)
                   printf("isosceles right triangle,");
                else 
                   printf("isosceles triangle, ");
      else if(fabs(a*a-b*b-c*c)>e)
              printf("general triangle,");
           else printf("right triangle,");
          
 p=f*(f-a)*(f-b)*(f-c);
 s=sqrt(p);
 if(a<a+b)
  printf("%.1lf",s);
   putchar('\n');
 
  i++;
  }
}
