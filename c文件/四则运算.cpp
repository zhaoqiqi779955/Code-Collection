#include<iostream>
#include<string.h>
#define N 1000
using namespace std;
void display(char a[])
{
	for(int i=0;i<1000;i++)
	cout<<a[i];
	cout<<endl;
}
void multiply(const char a1[],const char b1[],char c[])
{
	char a[N],b[N];
	for(int i=0;i<1000;i++)
	c[i]=0;
	for(int i=0;i<N;i++)
	{
		a[i]=a1[i]-48;
		b[i]=b1[i]-48;
	}
	
	for(int i=N-1;i>=0;i--)
	{
		int k=i;
		for(int j=N-1;j>=0&&k>=0;j--)
		{
			c[k]+=a[i]*b[j];
			k--;
		}
	
	
		int carry=0;
		for(int i=N-1;i>=0;i--)
		{
			int t=c[i]+carry;
			if(t>=10) {
				carry=t/10;
			    c[i]=t%10;
			}
			else
			{
				carry=0;
				c[i]=t;
			}
		}
	}
	for(int i=0;i<N;i++)
	c[i]+=48;
 } 

void  add(const char str1[],const char str2[],char str3[])//str3为结果 既定1000位 
{
	int carry=0;
	for(int i=999;i>=0;i--)
	{
		int t=str1[i]-48+str2[i]-48+carry;
		if(t>=10)
		{
			str3[i]=t-10+48;
			carry=1;
		}
		else {
			str3[i]=t+48;
			carry=0;
		}
	}
	
}
void complement(const char a[],char b[])//b是补码（负数） 
{
	for(int i=999;i>0;i--)
	{
		b[i]='9'-a[i]+48;
	 } 
	 if(a[0]=='0') b[0]='9';
	 else b[0]='0';
	 char c[1000];
	 for(int i=0;i<999;i++)
	 c[i]='0';
	 c[999]='1';
	 
	 add(b,c,b);

}
class Calculate
{
	char data[1000];
	public:
	Calculate(char str[]="0")
	{
		for(int i=0;i<1000;i++)
		data[i]=str[i];
	}
	
	Calculate operator +(const Calculate &obj)
	{
		char tem[1000];
		add(data,obj.data,tem);
		return Calculate(tem);
	}
	Calculate operator -(const Calculate &obj)
	{
		char re[1000];
		complement(obj.data,re);
		add(re,data,re);
		return Calculate(re);
	}
	Calculate operator *(const Calculate &obj)
	{
		char c[1000];
		multiply(data,obj.data,c);
		return Calculate(c);
		
	 } 
 	void display()
 	{
 		for(int i=0;i<1000;i++)
		cout<<data[i];
		cout<<endl;
 	}
	void show()
	{
		if(data[0]!='0') 
		{
		   cout<<'-';
		   char c[1000];
		   complement(data,c);
		   int i=0;
		   while(c[i]=='0') i++;
		   while(i<1000)
		   {
		   	cout<<c[i];
		   	i++;
		   }
		}
		else
		{
			int i=0;
		   while(data[i]=='0'&&i<999) i++;
		   while(i<1000)
		   {
		   	cout<<data[i];
		   	i++;
		   }
		}
		
	}
 } ;
 void input(char str1[])
 {
 	char str[1000];
 	cin>>str;
 	int len=strlen(str);
	for(int i=0;i<1000;i++)
	 str1[i]='0';
	
		if(str[0]=='-')
		{
			int i=999;
			for(int j=len-1;j>0;i--,j--)
			{
				str1[i]=str[j];
			}
		
		  complement(str1,str1);
		 
		}
		else if(str[0]=='+')
		{
			int i=999;
			for(int j=len-1;j>0;i--,j--)
			{
				str1[i]=str[j];
			}
		}
		else {
				int i=999;
			for(int j=len-1;j>=0;i--,j--)
			{
				str1[i]=str[j];
			}
		}
}
	  
 int main()
 {
 	char str[1000];
 	input(str);
 	Calculate obj(str);
 	input(str);
 	Calculate obj1(str);
 	Calculate obj2=obj1*obj;
 	obj2.show();
 	
 
 }
 
 
 
 
 
 
 
 
 
 
 
 
