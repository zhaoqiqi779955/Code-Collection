#include<iostream>
using namespace std;
 class Ccube;
 class Cpoint
 {
 	int x,y,z;
 	public :
 		Cpoint(int x1,int y1,int z1)
 		{
 			x=x1;
 			y=y1;
 			z=z1;
		 }
		 Cpoint(){
		 }
		 
		friend Ccube;//未定义前不可调用类的操作如定义类 
		
 };
 class Ccube
 {
 	Cpoint *point;
 	public:
 		Ccube(Cpoint &c1,Cpoint &c2)
 		{
 			point=new Cpoint [2];
 			point[0]=c1;
 			point[1]=c2;
 			
		 }
		 int crash(Ccube &obj)
		 {
		 	int x1=point[0].x,y1=point[0].y,z1=point[0].z;
		 	int x2=point[1].x,y2=point[1].y,z2=point[1].z;
		 	int x3=obj.point[0].x,y3=obj.point[0].y,z3=obj.point[0].z;
			int x4=obj.point[1].x,y4=obj.point[1].y,z4=obj.point[1].z;
			int t;
			if(x1>x2) { t=x1;x1=x2;x2=t;
			} 
			if(y1>y2) {
				t=y1;y1=y2;y2=t;
			}
			if(x3>x4) {
				t=x3;x3=x4;x4=t;
			}
			if(y3>y4) {
				t=y3;y3=y4;y4=t;
			}
			if(z1>z2) {
				t=z1;z1=z2;z2=t;
			}
			if(z3>z4) {
				t=z3;z3=z4;z4=t;
			}
			if((x3-x2)*(x4-x1)<=0&&(y3-y2)*(y4-y1)<=0&&(z3-z2)*(z4-x1)<=0) return 1;
			else return 0;
		 }
		 ~Ccube()
		 {
		 	delete [] point;
		 }
 };
 int main()
 {
 	int t;
 	cin>>t;
 	while(t--)
 	{
 		int x1,y1,z1,x2,y2,z2;
 		cin>>x1>>y1>>z1>>x2>>y2>>z2;
 		Cpoint p1(x1,y1,z1);
 		Cpoint p2(x2,y2,z2);
 		Ccube c1(p1,p2);
 		cin>>x1>>y1>>z1>>x2>>y2>>z2;
 		Cpoint p3(x1,y1,z1);
 		Cpoint p4(x2,y2,z2);
 		Ccube c2(p3,p4);
 		if(c1.crash(c2)) cout<<"collide"<<endl;
 		else cout<<"have distance"<<endl;
 		
 		
	 }
 }
 
 
 
 
 
 
 
 
 
 
 
 
