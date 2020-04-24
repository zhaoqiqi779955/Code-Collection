#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
#include<conio.h>
#define N 1200
void removesp(char a[]);
int tag=0; 
void input( char a[]);
void addup( char a[],char b[],char c[]);
char add(char x,char y);
int main()
{
	int t;
	int i=1;
	cin>>t;
	getchar();
	while(t-->0)
	{
	
	char a[N+1],b[N+1],c[N+2];
	input(a);
	input(b);
	printf("Case %d:\n",i++);
	cout<<a<<" + "<<b<<" = ";
	
addup(a,b,c);
  if(t>0) cout<<endl;
  }

 } 
 void input(char a[])
 {
 	
 	char ch;
 	int i=0;
 	while(1)
 	{
 		ch=getch();
 	if(i<N)	
	 if(ch>='0'&&ch<='9') { a[i++]=ch;	putchar(ch);}
     	if(ch=='\b') { a[i--]=' ';printf("\b \b");continue;}
 		if(ch=='\r')	break;
 
	 }
	 a[i]='\0';
	putchar('\n');
	
 }
 void addup( char a[],char b[],char c[])
 {
 	int i,j,k=N;
 	memset(c,' ',N+2);
 	i=strlen(a)-1;
 	j=strlen(b)-1;
 	while(i>=0&&j>=0)
	 
 c[k--]=add(a[i--],b[j--]);
 
 	while(i>=0) c[k--]=add(a[i--],'0');
 	while(j>=0) c[k--]=add(b[j--],'0');
 	if(tag==1) c[k]='1';
 c[N+1]='\0';
 removesp(c);
 

 }
 char add(char x,char y)
 {
 	
 	int z;
 
 	z=(x-48+y-48)+tag;
 	if(z>=10)
 	{
	 tag=1;
 	 return (z-10+48);
 	
   }
   else
	  {
	  	tag=0;
 	 	return (z+0x30);
 	 	
	  }
	  
 	
 }
 
 
 void removesp(char c[])
 {
 	int i=N;
 	while(c[i--]!=' ');
 
 	c[N+1]='\0';
 	puts(c+i+2);
 }
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
