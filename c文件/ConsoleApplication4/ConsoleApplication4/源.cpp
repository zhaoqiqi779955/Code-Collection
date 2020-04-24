#include<iostream>
#include<string>
using namespace std;
void get_next(string str,int  next[],int len)
{
	int i=0;
	int j=-1;
	next[0]=-1;
	while (i<len)
	{
		if (j==-1||str[i]==str[j])
		{
			i++;j++;
			next[i]=j;
		}
		else
		{
			j=next[j];
		}
	}
}
int KMP(string str,string T)
{
	int i=0,j=0;
	int len1=str.length();
	int len2=T.length();
	int *next=new int[len2];
	get_next(T,next,len2);
	while (i<len1&&j<len2)
	{
		if(j==-1||str[i]==T[j]) {
			i++;j++;
		}
		else j=next[j];
	}
	if(j>=len2) return i-len2;
	else
	{
		return -1;
	}
}

int main()
{
	int t;
	cin>>t;
	while (t--)
	{
		string T;
		cin>>T;
		int next[100];
		int len=T.length();
		get_next(T,next,len);
		for (int i=0;i<=len;i++)
		{
			cout<<next[i]<<" ";
		}
		cout<<endl;
		int max=0;
		for (int i=0;i<=len;i++)
		{
			if(next[i]>max) max=next[i];

		}
		
		if(max==0||max==-1) cout<<"empty";
		else cout<<max;
		cout<<endl;
	}
	
}