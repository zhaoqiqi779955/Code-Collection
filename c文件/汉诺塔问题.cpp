#include<stdio.h>
#include<stdlib.h>
void hanoi(int n,char A,char B,char C)
{
	if(n==1)
		printf("�����Ϊ1�����Ӵ�%c�Ƶ�%c\n",A,C);
   else
	{
		printf("hanoi(%d,%c,%c,%c)\n",n-1,A,C,B);
		hanoi(n-1,A,C,B);
		printf("�����Ϊ%d���Ӵ�%c�Ƶ�%c\n",n,A,C);
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
