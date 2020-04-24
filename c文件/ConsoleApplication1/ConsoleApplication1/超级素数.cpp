#include<iostream>
#include<math.h>
using namespace std;
bool isprime(int a[][5000],int j,int n)//第j个数，第n位数
{
	if(n==1&&a[1][j]==1) return false;
	int sum=0;
	for(int i=n;i>=1;i--)
		sum=sum*10+a[i][j];
	int k=sqrt(sum);
	for(int i=2;i<=k;i++)
		if(sum%i==0) return false;
	return true;
}
/*int main()
{
	int m;
	cin>>m;
	int a[12][5000],b[12][5000];
	int g=4,n;//用于统计下一层素数个数
	int t=10;
	a[1][1]=2;
	a[1][2]=3;
	a[1][3]=5;
	a[1][4]=7;

	for(int i=2;i<=m;i++)
	{
		n=0;


		for(int j=1;j<=g;j++)
		{



			for(int d=1;d<=9;d++)
			{
				a[i][j]=d;
				if(isprime(a,j,i)) 
				{
					n++;
					for(int k=1;k<=i;k++)
						b[k][n]=a[k][j];

				}

			}

		}
		for (int j=1;j<=n;j++)
		{
			for(int k=1;k<=i;k++)
				a[k][j]=b[k][j];
		}
		g=n;
	}

	cout<<"共"<<g<<"个"<<endl;
	for(int j=1;j<=g;j++)
	{
		for(int i=m;i>=1;i--)
			cout<<a[i][j];
		cout<<endl;
	}

}*/