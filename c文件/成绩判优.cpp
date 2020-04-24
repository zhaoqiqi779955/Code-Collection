#include<stdio.h>
int main()
{
	int n,t;
	scanf("%d",&n);
	t=n/10;
	switch(t)
	{
		case 10 : puts("great");
		break;
		case 9: puts("good");
		break;
		case 8:puts("A");
		break;
		case 7: puts("B");
		break;
		case 6: puts("C");
		break;
		default:puts("fail");
		
			}
			
}
