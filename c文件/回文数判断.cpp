#include<stdio.h>
#include<iostream>
#include<math.h>
bool hu(int n);
using namespace std;
int prime(int n);
int main()
{
	int n;
	cin>>n;
  hu(n);
}
bool hu(int n)
{
	int x=n,y=0;
	while(x!=0)
	{
		int r=x%10;
		y=y*10+r;
		x=x/10;
		
	}
	cout<<y;
}
