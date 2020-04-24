#include<iostream>
#include<iostream>
#include<memory.h>
#include<stdio.h>
using namespace std;
typedef long long ll;

ll r[30][30][30];
ll w(ll a,ll b,ll c)
{
   if(a<=0||b<=0||c<=0) return 1;
   else if(r[a][b][c]!=0) return r[a][b][c];
   else if(a>20||b>20||c>20)  return (w(20,20,20));
   else if(a<b&&b<c) r[a][b][c]=w(a,b,c-1)+w(a,b-1,c-1)-w(a,b-1,c);
   else r[a][b][c]=w(a-1,b,c)+w(a-1,b-1,c)+w(a-1,b,c-1)-w(a-1,b-1,c-1);
   return r[a][b][c];
}

int main()
{
	ll a,b,c;
	while(scanf("%lld%lld%lld",&a,&b,&c)==3)
	{
	 memset(r,0,sizeof(r));
	 
	 if(a==-1&&b==-1&&c==-1) break;
	 else printf("w(%lld, %lld, %lld) = %lld\n",a,b,c,w(a,b,c));
	
   } 
}
