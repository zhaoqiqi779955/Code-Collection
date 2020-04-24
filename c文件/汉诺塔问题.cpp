#include<stdio.h>
#include<stdlib.h>
void hanoi(int n,char A,char B,char C)
{
	if(n==1)
		printf("将编号为1的盘子从%c移到%c\n",A,C);
   else
	{
		printf("hanoi(%d,%c,%c,%c)\n",n-1,A,C,B);
		hanoi(n-1,A,C,B);
		printf("将编号为%d盘子从%c移到%c\n",n,A,C);
		printf("hanoi(%d,%c,%c,%c)\n",n-1,B,A,C);
		hanoi(n-1,B,A,C);
			
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	hanoi(n,'A','B','C');
	
 }
