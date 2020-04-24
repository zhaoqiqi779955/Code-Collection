#include<stdio.h>
int main()
{
	char x;
	int y;
	
scanf("%c%d",&x,&y);

switch(x)
{


case 'A':printf("ºÚÌÒ");
break;
case 'B':printf("ºìÌÒ");
break;
case 'C':printf("Ã·»¨");
break;
case 'D':printf("·½¿é") ;
}
switch(x)
{

case 'a':printf("ºÚÌÒ");
break;
case 'b':printf("ºìÌÒ");
break;
case 'c':printf("Ã·»¨");
break;
case 'd':printf("·½¿é") ;
}
if(y>1&&y<=10)
printf("%d",y);
else switch(y)
{
	case 11:printf("J");
	break;
	case 12:printf("Q");
	break;
	case 13:printf("K");
	break;
	case 1:printf("A");
	break;
}
  
} 

