#ifndef myString_h
#define myString_h
#define  END '#'//������
#include<string>
using namespace std;
bool insert(char a[],int loc,char ch);//����λ��,��0��ʼ
bool delchr(char a[],int loc);//����λ��
int strlen(char a[],char end);
double evaluateExpression(char str[]);
int findStr(char a[],char b[]);
string findRepeat(string a);
#endif