#include<iostream>
#include<iomanip>
using namespace std;
#include<string.h>
#include<math.h>
class CTriangle
{
	double x,y,z;
	char type[50];
	public:
     	CTriangle(double a,double b,double c)
     	{
     		x=a;
     		y=b;
     		z=c;
		 }
		void judge()
		{
			
		 double a,b,c,s,t,f,p,e=0.001;
         a=x;b=y;c=z;
        
	    if(a<b)
			{t=a;a=b;b=t;}
     	if(b<c)
        	{t=b;b=c;c=t;}
		if(a<b)
		{
			t=a;a=b;b=t;
		}
		f=(a+b+c)/2;
		s=sqrt(f*(f-a)*(f-b)*(f-c));
	
		if(a>=b+c)
			 strcpy(type,"no triangle");
        else if(fabs(a-b)<e&&fabs(a-c)<e)
          strcpy(type,"equilateral triangle");
      else 
	      if(fabs(a-b)<e||fabs(a-c)<e||fabs(b-c)<e)
                 if(fabs(a*a-b*b-c*c)<e)
                   strcpy(type,"isosceles right triangle");
                else 
                   strcpy(type,"isosceles triangle");
      else if(fabs(a*a-b*b-c*c)>e)
              strcpy(type,"general triangle");
           else strcpy(type,"right triangle");
           
			if(strcmp(type,"no triangle")==0) cout<<"no triangle"<<endl;
			else cout<<type<<", "<<fixed<<setprecision(1)<<s<<endl;
			}
		
         ~CTriangle()
         {
         	x=y=z=0;
         	strcpy(type,"none");
		 }
	};
	
	int main()
	{
		
		int t;
		cin>>t;
		while(t--)
		{
			double x,y,z;
			cin>>x>>y>>z;
			CTriangle  ct(x,y,z);
			ct.judge();
		}
	 } 

