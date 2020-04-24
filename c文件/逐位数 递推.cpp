#include<iostream>
using namespace std;
bool div(int a[][30],int k,int n)//k为第k个逐位数，第n位 
{
	int sum=0;
	for(int i=1;i<=n;i++)
	{
		sum=sum*10+a[k][i];
		sum=sum%n;
	}
	if(sum%n==0) return true;
	else return false;
}
int main()
{
	int a[3000][30];
	int b[3000][30];
	int g=9;
	int n;
	cin>>n;
	for(int i=1;i<=g;i++)
		a[i][1]=i;
	for (int i=2;i<=n;i++)
	{
		int m=0;
		for(int j=1;j<=g;j++)
		{ 
	  		for (int d=0;d<=9;d++)
			{
				a[j][i]=d;
				if(div(a,j,i)) 
				{ 
					m++;
					for (int k=1;k<=i;k++)
					
						b[m][k]=a[j][k];
				}				

			}
			} 
			for (int j=1;j<=m;j++)//j为逐位数个数
				for (int k=1;k<=i;k++ )
					a[j][k]=b[j][k];
	
		g=m;
	}

   for(int i=1;i<=g;i++)
   {
   	cout<<i<<": ";
   	for(int j=1;j<=n;j++)
    	cout<<a[i][j];
    	cout<<endl;
	}
}
