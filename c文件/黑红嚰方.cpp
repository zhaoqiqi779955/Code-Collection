#include<stdio.h>
int main()
{
	char x;
	int y;
	
scanf("%c%d",&x,&y);

switch(x)
{


case 'A':printf("����");
break;
case 'B':printf("����");
break;
case 'C':printf("÷��");
break;
case 'D':printf("����") ;
}
switch(x)
{

case 'a':printf("����");
break;
case 'b':printf("����");
break;
case 'c':printf("÷��");
break;
case 'd':printf("����") ;
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

