#include<iostream>
using namespace std;
int main()
{
	int n,step;//采样个数,和步长
	cout<<"输入n和步长"<<endl;
	cin>>n>>step;
	cout<<"输入原始数据"<<endl;
	int * f=new int [n];
	for (int i=0;i<n;i++)
	{
		cin>>f[i];
	}

	int *fh,*frs,*e,*ers;
	fh=new int [n];
	frs=new int [n];
	e=new int [n];
	ers=new int [n];
	frs[0]=f[0];
	for (int i=1;i<n;i++)
	{
		fh[i]=frs[i-1];
		e[i]=f[i]-fh[i];
		if(e[i]>0)
			ers[i]=step;
		else  ers[i]=-step;
		frs[i]=fh[i]+ers[i];
	}
	cout<<"result: "<<endl;
	for (int i=0;i<n;i++)
	{
		cout<<frs[i]<<" ";
	}
	delete [] frs;
	delete [] f;
	delete [] e;
	delete [] ers;
	delete [] fh;
	
}