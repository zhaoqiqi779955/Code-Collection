#include<iostream>
using namespace std;
template <class T>
class Matrix
{
	T data[100][100];
	int m,n; 
public:
	Matrix(T (*p)[100],int mm,int nn)
	{
		m=mm;
		n=nn;
		for(int i=0;i<m;i++)
			for (int j=0;j<n;j++)
			{
				data[i][j]=p[i][j];
			}
	}
	void transport()
	{
		for(int i=0;i<m;i++)
			for(int j=0;j<n;j++)
				if(i<j||i>=n||j>=m)
				{
					T x;
					x=data[j][i];
					data[j][i]=data[i][j];
					data[i][j]=x;
				}
       int t=m;
	   m=n;
	   n=t;
	}
	void print()
	{
		for(int i=0;i<m;i++)
		{
			for(int j=0;j<n;j++)
				cout<<data[i][j]<<' ';
			cout<<endl;
		}
	}
};
int main()
{

	int t;
	cin>>t;
	while(t--)
	{
		char ch;
		int m,n;
		cin>>ch>>m>>n;
		if(ch=='I')
		{
			int a[100][100];
			for(int i=0;i<m;i++)
				for(int j=0;j<n;j++)
					cin>>a[i][j];
	
			Matrix<int> obj(a,m,n);
			obj.transport();
			obj.print();
		}
		else if(ch=='C')
		{
			char a[100][100];
			for(int i=0;i<m;i++)
				for(int j=0;j<n;j++)
					cin>>a[i][j];
			Matrix<char> obj(a,m,n);
			obj.transport();
			obj.print();
		}
		else if(ch=='D')
		{
			double a[100][100];
			for(int i=0;i<m;i++)
				for(int j=0;j<n;j++)
					cin>>a[i][j];
			Matrix<double> obj(a,m,n);
			obj.transport();
			obj.print();
		}
	}
}
