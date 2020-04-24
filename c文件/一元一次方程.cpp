#include<iostream>
#include<iomanip>
#include<stdio.h>
#include<string.h>
using namespace std;
void add(char a[],int n,char ch)
{
    int len=strlen(a);
    a[len+1]='\0';
    for(int i=len;i>n;i--)
     a[i]=a[i-1];
     a[n]=ch;
 } 
int is(char c)
{
    if(c>='0'&&c<='9') return 1;
    else if(c=='+') return 2;
    else if(c=='-') return 3;
    else return 4;
    }
void transform(char a[],char ch)
{
    int len=strlen(a);

    
    
    int i=len-1;
    while(a[i]!='=') i--;
    if(a[i+1]=='+'&&a[i+1]=='-');
    else
     add(a,i+1,'+');
    if(a[0]=='+'||a[0]=='-') ;
    else add(a,0,'+');
    for(int i=len-1;i>0;i--)
     if(a[i]==ch)
      if(a[i-1]>='0'&&a[i-1]<='9') ;
      else add(a,i,'1'); 
      
     
    
}
int main()
{
    char a[100],ch;
    cin>>a;
    ;
    for(int i=0;a[i]!='\0';i++)
    if(a[i]=='='||a[i]=='+'||a[i]=='-'||a[i]>='0'&&a[i]<='9');
    else { ch=a[i];
    break;
    }


    
    transform(a,ch);
   //cout<<a;
   int  l1=0,l2=0,r2=0,r1=0;
    int len=strlen(a);

    int k;
    for(int i=0;i<len;i++)
     if(a[i]=='=') {
     	k=i;break;
     }
    int sum=0,t=1,s=0;
    for(int i=k-1;i>=0;i--)
      if(is(a[i])==1)
       {
       	 sum+=(a[i]-'0')*t;
       	 t=t*10;
        } 
     else if(is(a[i])==2) {
     	if(!s) l2+=sum;
     	else {
         l1+=sum;s=0;
         }
     	sum=0;
     	t=1;
     }
     else if(is(a[i])==3) {
     	if(!s) l2-=sum;
     	else  {
         l1-=sum;
         s=0;
      }
     	sum=0;t=1;
     }
     else s=1;	
     // µÈÊ½ÓÒ²à 
     sum=0,t=1,s=0;
     for(int i=len-1;i>k;i--)
     if(is(a[i])==1)
       {
       	 sum+=(a[i]-'0')*t;
       	 t=t*10;
        } 
     else if(is(a[i])==2) {
     	if(!s) r2+=sum;
     	else {
         r1+=sum;s=0;
             }
     	sum=0;
     	t=1;
     }
     else if(is(a[i])==3) {
     	if(!s) r2-=sum;
     	else  {
         r1-=sum;
         s=0;
      }
     	sum=0;t=1;
     }
     else s=1;	

     cout<<ch<<"="<<fixed<<setprecision(3)<<(r2-l2)*1.0/(l1-r1)+0.0;
 
     
    
    
 } 

