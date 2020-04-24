#include<stdio.h>
int main()
{
	int h1,m1,s1,h2,m2,s2;
	scanf("%d:%d:%d",&h1,&m1,&s1);
	scanf("%d:%d:%d",&h2,&m2,&s2);
	int x,y,z,k=0,g=0;
	x=s2-s1;
	if(x<0) k=-1;
	y=m2-m1+k;
	if(y<0) g=-1;
	z=h2-h1+g;
	printf("%d:%d:%d",(z+24)%24,(y+60)%60,(x+60)%60);
	

return 0;
}
