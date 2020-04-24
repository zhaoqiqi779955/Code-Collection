#include<iostream>
#include<myhead.h>
using namespace std;
int main()
{
	char a[100];
	a[99]='\0';
	int i=0;
	char ch;
	while ((ch=getchar())!='#')
	{
		a[i]=ch;
		i++;
	}
	a[i]='#';
	double x=evaluateExpression(a);
	cout<<x;
}