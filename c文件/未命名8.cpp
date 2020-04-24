#include<iostream>
using namespace std;
#include<math.h>
class Point
{
	
	public:
		
	  Point() {;};
	  Point(int a,int b)  {
	  	x=a;
	  	y=b;
		}
	
	 ~Point(){
        printf("point clear\n");
    }
	 	
	 void setxy(int x,int y)
	 {
	 	 this->x=x;
	 	 this->y=y;
	 }
	 
	 int getx()
	 {
	 	return x;	
	 }
	 
	 int gety()
	 {
	 	return y;
	 }
private: int x,y; 
	
};

class Circle
{
	int x,y,r;
	public:
		Circle(int x,int y,int r)
		{
			this->x=x;
			this->y=y;
			this->r=r;
			
		}
		int contain( int a,int b)
		{
			double s=pow(double(a-x),2)+pow(double (b-y),2);
			s=sqrt(s);
			if(s>r) return 0;
			else return 1;
			
		}
		~Circle()
		{
			x=0;y=0;
			cout<<"circle clear"<<endl;
		}
};
int main()
{
	int x,y;
	cin>>x>>y;
	Point p(x,y);
	int n;
	cin>>n;
	Point *nm=new Point [n];
	for(int i=0;i<n;i++)
	  {
	  	cin>>x>>y;
	  	nm[i].setxy(x,y);
	  }
	  int r;
	  cin>>x>>y>>r;
	  Circle cir(x,y,r);
	  if(cir.contain(x,y)) cout<<"in"<<endl;
	  else cout<<"out"<<endl;
	  for(int i=0;i<n;i++)
	  {
	  
	    if(cir.contain(nm[i].getx(),nm[i].gety()))
		 cout<<"in"<<endl;
	   else cout<<"out"<<endl;
	  }
	  return 0;
	}




