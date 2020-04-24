#include<iostream>
using namespace std;
struct point
{
	int x,y;
};
void getpoint(point *a)
{
	cin>>a->x>>a->y;

}



int f(point j,point a,point b)
{
	int x=j.x;
	int y=j.y;
	
	double s;
	int x1=a.x,y1=a.y,x2=b.x,y2=b.y;
	if(x1==x2) s=x-x1;
	else {
	   double k;
	   k=1.0*(y2-y1)/(x2-x1);
	   s=k*(x-x1)+y1-y; 
	    
	 }

	return s;
}

int main()
{
   int t;
   cin>>t;
   while(t--)
   {
   	  point a,b,c,d;
   	  getpoint(&a);
   	  getpoint(&b);
   	  getpoint(&c);
   	  getpoint(&d);
   	 
   	  double s1,s2,s3,s4;
   	  s1=f(a,c,d);
   	  s2=f(b,c,d);
   	  s3=f(c,a,b);
   	  s4=f(d,a,b);
   	  if(s1*s2<=0&&s3*s4<=0) cout<<"intersect"<<endl;
   	  else cout<<"disjoint"<<endl;
   	  
   	 
   	   
   }
 } 
