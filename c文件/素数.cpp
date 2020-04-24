#include<stdio.h> 
#include<math.h>
int con(int x);
int main(void)
{
	int i=3,a,b,p,z,j;
	scanf("%d",&j);
for(;i<=j/2;i++)
 {a=2*i;
   for(p=2;p<=a/2;p++)
   {
        z=a-p;
        if(con(p)&con(z))
       {

       /*printf("%d组合：%d %d\n",a,p,z);*/
      break;
        }
    }
     if(p>a/2)
      printf("no");
   }
   if(a>=j)
   printf("%d精度内满足",j);
 }
    

int con(int x)
{int y=2,w;
w=sqrt(x);
for(;y<=w;y++)
if(x%y==0) 
break;

if(y>w)
return 1;
else return 0;

}
