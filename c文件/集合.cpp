#include<stdio.h>
#include<iostream>
#include<memory.h>
using namespace std;

void pu(char a[],bool (*b)[2],int i,int n,int t);
int main()
{
	char c[10];
	char a[7]={'a','b','c','d','e','f'};
	bool b[6][2];
	memset(*b,0,12*sizeof(bool));
    for(int i=0;i<6;i++)
     b[i][1]=true;
     pu(a,b,0,6,0);
   
	
	
 } 
 void pu(char a[],bool (*b)[2],int i,int n,int t)
 {
 	static int y=0;
 	static char c[6];
 	if(i==n)  
 	{
 		y++;
	 
 	c[6]='\0';
 	cout<<'{'<<c<<'}'<<y<<endl;

 }
	else
	{
	
 	for(int j=0;j<2;j++)
 	{
	 if(b[i][j]) 
	 c[t]=a[i];

	else
	c[t]=' ';
	 pu(a,b,i+1,6,t+1);
}
 }

 }


