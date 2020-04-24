#ifndef myString_h
#define myString_h
#define  END '#'//结束符
#include<string>
using namespace std;
bool insert(char a[],int loc,char ch);//索引位置,从0开始
bool delchr(char a[],int loc);//索引位置
int strlen(char a[],char end);
double evaluateExpression(char str[]);
int findStr(char a[],char b[]);
string findRepeat(string a);
#endif