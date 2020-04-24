#include<myString.h>
#include<string.h>
#include<iostream>
using namespace std;
void getNext(char a[],int next[],int length);
int findStr(char a[],char b[])//a为主串，b为模式串
{
	int len1=strlen(a);
	int len2=strlen(b);
	int *next=new int [len2];
	getNext(b,next,len2);
	int i=0;
	int j=0;
	while(i<len1&&j<len2)
	{
		if (a[i]==b[j]||j==-1)
		{
			i++;
			j++;
		}
		else { j=next[j];}
	}
	delete [] next;
	if (j<len2)
	{
		cout<<"no match"<<endl;
	
	}
	else return i-len2;

}
void getNext(char a[],int next[],int length)
{
	int i=0,k=-1;
	next[0]=-1;
	while (i<length-1)
	{
		if (a[i]==a[k]||k==-1)
		{
			i++;
			k++;
			next[i]=k;
		}
		else {
			k=next[k];

		}
	}
	

}
void get_nextVal(char a[],int next[],int length)
{
	int i=0,k=-1;
	next[0]=-1;
	while (i<length-1)
	{
		if (a[i]==a[k]||k==-1)
		{
			i++;
			k++;
			if (a[i]==a[k])
			{
				next[i]=next[k];
			}
			else 
			 next[i]=k;
		}
		else {
			k=next[k];

		}
	}


}