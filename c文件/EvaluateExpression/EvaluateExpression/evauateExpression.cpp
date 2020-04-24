#include<myString.h>
#include<iostream>
using namespace std;
#include<stack>
bool isdigit(char ch); 
bool isOperator(char ch);
bool isPrior(char ch1,char ch2);
double operate(double x,char op,double y);
double calculateString(char a[],int len);
bool strdel(char a[],int loc);
void preProcess(char a[])
{
	int k=0;
	for (int i=0;a[i]!='#';i++)//第一次加工,去非法字符
	{
		char ch=a[i];
		if(isOperator(ch)||ch=='#'||ch=='.'||isdigit(ch)) 
		{
			a[k]=ch;
			k++;
		}
		
	}
	a[k]='#';
	insert(a,0,'(');
	for (int i=1;a[i]!='#';i++)
	{
		char ch=a[i];
		if (ch=='-')
		{
			if(isOperator(a[i-1])||a[i-1]=='#')
			{
				insert(a,i,'(');
				insert(a,i+1,'0');
				for (i=i+3;isdigit(a[i])||a[i]=='.';i++)
				continue;
				insert(a,i,')');
			}

		}
	}
	strdel(a,0);
}
bool isOperator(char ch)
{
	if(ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='('||ch==')') return true;
	else return false;

}
 bool isdigit(char ch)
 {
	 if(ch>='0'&&ch<='9'||ch=='.')
		 return true;
	 else return false;
 }

bool strdel(char a[],int loc)//索引位置
{
	int len=0;
	while (a[len]!='#') len++;
	len++;
	if(loc>=len||loc<0) return false;
	for (int i=loc;i<len;i++)
	{
		a[i]=a[i+1];
	}
	
	return true;
}
double evaluateExpression(char str[])
{
	preProcess(str);
	stack<char> sign;//存储运算符号
	stack<double> digit;//存储操作数
	sign.push('#');
	char ch=str[0];//ch用于读取数字
	int i=0;//用于移动字符
	while (ch!='#')
	{
		if (ch=='(')
		{
			sign.push(ch);
		}
		else if (ch==')')
		{
			char op=sign.top();
			while(op!='(')
			{
				double x,y;
				y=digit.top();
				digit.pop();
				x=digit.top();
				digit.pop();
				double result=operate(x,op,y);
				digit.push(result);
				sign.pop();
				op=sign.top();
			}
			sign.pop();
		}
		else if(ch=='+'||ch=='-'||ch=='*'||ch=='/')
		{
			char top=sign.top();
			if(top!='#'&&top!='(')
			{

					if(isPrior(top,ch))
					{
						char op=sign.top();
						sign.pop();
						double x,y;
						y=digit.top();
						digit.pop();
						x=digit.top();
						digit.pop();
						double result=operate(x,op,y);
						digit.push(result);
						continue;
					}
					else {
						sign.push(ch);
						
					}
			}
			else sign.push(ch);

		}
		else if (ch>='0'&&ch<='9'||ch=='.')
		{
			char a[100];
			a[0]=ch;
			int k=1;
			i++;
			ch=str[i];
			while(ch>='0'&&ch<='9'||ch=='.')
			{
				a[k]=ch;
				i++;
				k++;
				ch=str[i];
			}
			double res=calculateString(a,k);
			i--;
			digit.push(res);
		}
		i++;
		ch=str[i];
	}
	while (sign.top()!='#')
	{
		char op=sign.top();
		sign.pop();
		double x,y;
		y=digit.top();
		digit.pop();
		x=digit.top();
		digit.pop();
		double result=operate(x,op,y);
		digit.push(result);
	}
	return digit.top();
	
}
bool isPrior(char ch1,char ch2)
{
	switch(ch1)
	{
	case '+':
		ch1=1;break;
	case '-':ch1=1;break;
	case '*':ch1=2;break;
	case '/':
		ch1=2;break;
	}
	switch(ch2)
	{
	case '+':
		ch2=1;break;
	case '-':
		ch2=1;break;
	case '*':
		ch2=2;break;
	case '/':
		ch2=2;break;
	}
	if(ch1<ch2) return false;
	else return true;
}
double operate(double x,char op,double y)
{
	double result=0;
	switch(op)
	{
		case '+':
			result=x+y;break;
		case '-':result=x-y;break;
		case '*':result=x*y;break;
		case '/':
			result=x/y;break;
	}
	return result;
}
double calculateString(char a[],int len)
{
	double sum=0;
	int i=0;
	while(i<len)
	{
		if(a[i]=='.') break;
		sum=sum*10+a[i]-'0';
		i++;
	}
	i++;
	double t=0.1;
	while (i<len)
	{
		sum+=(a[i]-'0')*t;
		t*=0.1;
		i++;
	}
	return sum;
}	
