#include <iostream>
#include<head.h>
#include<string.h>
using namespace  std;
int main()
{
	char a[100];
	fget(a);
	char b[100];
	cin>>b;
	char *c=strstr(a,b);//返回a中包含b字符串的首位置
	if(c!=NULL) cout<<c;//strchr(char a[],char ch),strrchr(char a[],char ch)分别】找出a字符串的首次和最后一次出现ch的位置（指针）
		 
}