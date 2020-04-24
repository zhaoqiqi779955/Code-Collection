#include<stdio.h>
#include<math.h> 
int main()
{
	double da,a,b,c;
	
	scanf("%lf%lf%lf",&a,&b,&c);
	da=pow(b,2)-4*a*c;
	if(da<0)
	puts("no anwser");
	if(da==0)
		printf("%lf",-b/2/a);
	if(da>0)
		printf("x1=%lf x2=%lf",(-b+sqrt(da))/(4*a*c),(-b-sqrt(da))/(4*a*c));
}
