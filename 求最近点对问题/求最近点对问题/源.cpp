#include<iostream>

#include<set>
#include<time.h>
#include "Head.h"
using namespace std;
int N=1;
int main()
{
	    
		int n=100000;
		cout<<"����ģΪ"<<n<<"ʱ:"<<endl;
		int m=N;
		double t1=0,t2=0;
		while (m--)
		{
			Point *p=yieldPoints(n);
			
			
			time_t begin=clock();
			findMinPointPair_enum(p,n);
			time_t end=clock();
			t1+=end-begin;
			
			
			
			
			begin=clock();
			findMinPointPair_divide(p,n);
			end=clock();
			
		
			t2+=end-begin;
			
			delete [] p;
			
			
		}
		cout<<"��������ʱ"<<t1/N<<"����"<<endl;
		cout<<"���η���ʱ"<<t2/N<<"����"<<endl;

		
			
			
		
	
	
	
	
	
	
}