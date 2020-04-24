#include<stdio.h>
#include<iostream>
using namespace std;
int main()
{
	int lng;
	//cin>>lng;
	int m;
	cin>>m;
	int b[50][2];
	int a[50][3];
	for(int i=0;i<m;i++)
	a[i][0]=1;
	for(int i=0;i<m;i++)
	  for(int j=1;j<3;j++)
	  cin>>a[i][j];
	  int n,w;
	  int e=0;
	  int k=0;
	  for(int i=0;i<m;i++){ 
	  	n=a[i][1];
	  	w=a[i][2];
	  	
	  	 if(a[i][0]) { //未合并的情况下； 
		 for(int j=i+1;j<m;j++)
	  	   if(a[j][0]) { 
			 if(a[j][2]>n&&a[j][1]<w) 
	  	   
			   if(n<=a[j][1]&&w>=a[j][2]) a[j][0]=0;
			    
			    else if(n>=a[j][1]&&w<=a[j][2]) {
			    	n=a[j][1];w=a[j][2];
			    	a[j][0]=0;
				}
				else if(a[j][2]>=n&&a[j][1]<n) {
					n=a[j][1];
					a[j][0]=0;
					
				}
				else if(a[j][2]>w&&a[j][1]<=w){
				 w=a[j][2];
				 a[j][0]=0;
				 }
			}
			b[e][0]=n;
			b[e][1]=w;	 
			cout<<'['<<b[e][0]<<","<<b[e][1]<<"]"<<endl;
			e++;
		
			
   }	  
}
	 
 
}
 
