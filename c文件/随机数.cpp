#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
	char a[10];
	gets(a);
	char *p=&a[5];

	puts(p);
	
}
