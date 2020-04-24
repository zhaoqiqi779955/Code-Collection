#include<iostream>
using namespace std;
int main()
{
	int i,j,n,r,t,s,a[100];
	cin>>n;
	for(int j=1;j<100;j++) a[j]=0;
	t=0;
	s=0;
	i=1;a[1]=1;
	while(a[1]<=9)
	{
		if(t==0&&i<n) i++;
		for(r=0,j=1;j<=i;j++)
		{
			r=r*10+a[j];r=r%i; 
		}
		if(r!=0)
		{
			a[i]=a[i]+1;
			t=1;
			while(a[i]>9&&i>1)
			{
				a[i]=0;i--;
				a[i]=a[i]+1;
				
			}
		}
		else t=0;
		if(t==0&&i==n)
		{
			s++;
			cout<<s<<": ";
			for(j=1;j<=n;j++)
			cout<<a[j];
			cout<<endl;
			a[i]=a[i]+1;
			
		}
	 } 
	 if(s==0) cout<<"ц╩спур╣╫"<<endl;
	 
}
