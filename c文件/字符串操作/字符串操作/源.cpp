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
	char *c=strstr(a,b);//����a�а���b�ַ�������λ��
	if(c!=NULL) cout<<c;//strchr(char a[],char ch),strrchr(char a[],char ch)�ֱ��ҳ�a�ַ������״κ����һ�γ���ch��λ�ã�ָ�룩
		 
}