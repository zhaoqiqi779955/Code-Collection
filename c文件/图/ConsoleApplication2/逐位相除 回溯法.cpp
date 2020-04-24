#include<iostream>
using namespace std;
bool div(int a[],int n)
{
	int sum=0;
	for(int i=1;i<=n;i++)
	{
		sum=sum*10+a[i];
		sum=sum%n;
	}
	if(sum%n==0) return true;
	else return false;
}
int main()
{
	int a[100];
	int n;
	int flag=1;
	cin>>n;
	for(int i=0;i<100;i++)
		a[i]=0;
	a[1]=1;
	int bit=1;
	while(a[1]<=9)
	{
		if(div(a,bit))
		{
			if(bit==n)
			{
				for(int i=1;i<=n;i++)
					cout<<a[i];
				cout<<endl;
				a[bit]++;
			}
			else bit++;
		}
		else {
			
				a[bit]=a[bit]+1;
				if(a[bit]>9&&bit>1) { a[bit]=0;bit--;a[bit]++;}
			
			
		}

	}
}