#include<iostream>
using namespace std;
#include<string.h>
#include<memory.h>
struct poker {
	 char color[100];
	 char num[10];
		
};
int cp(char a[])
{   if(strcmp(a,"大王")==0) return 6;
    else if(strcmp(a,"小王")==0) return 5;
	else if(strcmp(a,"黑桃")==0) return 4;
	else if(strcmp(a,"红桃")==0) return 3;
	else if(strcmp(a,"梅花")==0) return 2;
	else return 1;
 } 
int cmpcolor(char a[],char b[])
{
	
	if(strcmp(a,b)==0) return 0;
	int ax,by;
	ax=cp(a);
	by=cp(b);
	if(ax>by) return 1;
	else return -1;
}
int cp1(char x[])
{
	
	if(strcmp(x,"A")==0) return 98;
	else if(strcmp(x,"10")==0) return 63;
	else if(strcmp(x,"J")==0) return 64;
	else if(strcmp(x,"Q")==0) return 65;
	else if(strcmp(x,"K")==0) return 66;
	else return x[0];
}
int cmpnum(char x[],char y[])
{   
    int v1=cp1(x),v2=cp1(y);
	if(strcmp(x,y)==0) return 0;
	
	else if(v1>v2) return 1;
	else return -1;
}
int cmp(poker x,poker y)
{
	
	if(cmpcolor(x.color,y.color)==1) return 1;
	else if(cmpcolor(x.color,y.color)==-1) return 0;
	else if(cmpnum(x.num,y.num)>=0) return 1;
	else return 0;
	
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		poker card[100];
		int n;
		cin>>n;
		for(int i=0;i<n;i++)
		{
			char str[20];
			cin>>str;
			strcpy(card[i].num,str+4);
			memcpy(card[i].color,str,4);
			card[i].color[4]='\0';
			
		  
		}
	
	
	for(int i=0;i<n;i++)
		 for(int j=0;j<n-1;j++)
		 
		 
		 if(!cmp(card[j],card[j+1]))
		 {
		 	poker f;
		 	f=card[j];
		 	card[j]=card[j+1];
		 	card[j+1]=f;
		 	
		 }
	  for(int i=0;i<n;i++)
	  { 
		cout<<card[i].color<<card[i].num; 
		
		 if(i<n-1) cout<<" ";
		 else cout<<endl; 
	
	  
	   
    }
}
}



