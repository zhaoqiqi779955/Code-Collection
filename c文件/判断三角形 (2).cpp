#include<stdio.h>
#include<math.h>
int main()
{
	double a,b,c,d,e,f,g,h,s,i;
	scanf("%lf",&a);
	while(a--) 
	{
		scanf("%lf %lf %lf",&b,&c,&d);
		if(b+c>d&&b-c<d)
	{
		i=(b+c+d)/2.0;
		s=sqrt(i*(i-b)*(i-c)*(i-d));
		e=b*b+c*c-d*d;
		g=b*b+d*d-c*c;
		h=d*d+c*c-b*b;
		if(b==c&&c==d)
			printf("equilateral triangle, %.1lf\n",s);
		else if((fabs(e)<0.001)||(fabs(g)<0.001)||(fabs(h)<0.001))
		{
			if((fabs(b-c)<0.001)||(fabs(b-d)<0.001)||(fabs(c-d)<0.001))    
			printf("isosceles right triangle, %.1lf\n",s);
			else
			printf("right triangle, %.1lf\n",s);
		}
		else if(e<0||g<0||h<0)
		{
			if(b==c||b==d||c==d)
			{
				if(b==c&&b==d&&c==d)
				printf("equilateral triangle, %.1f\n",s);
				else
				printf("isosceles triangle, %.1f\n",s);
			}
			else
			printf("general triangle, %.1lf\n",s);
		}
		else if(e>0||g>0||h>0)
		{
			if(b==c||b==d||c==d)
			printf("isosceles triangle, %.1f\n",s);
			else
			printf("general triangle, %.1f\n",s);
			
		}
	}
	else
	printf("no triangle\n");
	}
	
	return 0;
}
