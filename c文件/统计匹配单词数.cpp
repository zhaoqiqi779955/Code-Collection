#include<stdio.h>
#include<iostream>
using namespace std;
#include<string.h>
int main()
{
	char a[1000];
	char b[100];
	gets(b);
	gets(a);
	int count=0;
	char *p=a;
	int len=strlen(a);
	a[len]=' ';
	for(int i=0;i<=len;i++) {
		if(a[i]==' ') {
			a[i]='\0';
			if(stricmp(p,b)==0) count++;
			p=&a[i+1];
		}
	}
	cout<<count;
}
