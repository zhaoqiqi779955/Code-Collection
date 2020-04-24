#include<iostream>

#include<set>
#include<time.h>
#include "Head.h"
using namespace std;
int N=1;
int main()
{
	    
		int n=100000;
		cout<<"当规模为"<<n<<"时:"<<endl;
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
		cout<<"蛮力法用时"<<t1/N<<"毫秒"<<endl;
		cout<<"分治法用时"<<t2/N<<"毫秒"<<endl;

		
			
			
		
	
	
	
	
	
	
}