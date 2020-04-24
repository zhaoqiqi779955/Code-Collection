#include<iostream>
using namespace std;
int divide(int x,int y) throw(int)
{
	try{
		if(y==0) throw y;
	}
	 catch(int x)
	 {
	 	cout<<"division by zero"<<endl;
	 	cout<<"ÇëÖØÐÂÊäÈë"<<endl;
	 
	 	cin>>x>>y;
	 	cout<<divide(x,y);
	 	
	 }
	return (x/y); 
 } 
 int main()
 {
 	int x,y;
 	cin>>x>>y;
 	divide(x,y);
 }
