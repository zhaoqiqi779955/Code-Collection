#include<iostream>
using namespace std;
#include<string.h>
int main()
{
	int y1,y2,m1,m2,d1,d2;
	int y,m,d;
	cin>>y1>>m1>>d1>>y2>>m2>>d2;

	y=y1;m=m1;d=d1;
	int a[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
	int t=0,count=0;
	while(y<=y2)
	{
		if(y%4==0&&y%100!=0||y%400==0) a[2]=29;
		else a[2]=28;
		while(m<=12)
		{
			int days=a[m];
			while(d<=days)
			{
				if(y==y2&&m==m2&&d==d2) {
					t=1;
					break;
				}
				printf("%d %d %d\n",y,m,d);
				count++;
				d++;
				
			}
			if(t) break;
			m++;
			d=1;
		}
		if(t) break;
		y++;
		m=1;
	 } 
	 cout<<count;
}
