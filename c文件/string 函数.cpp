#include<stdio.h>
#include<string.h>
int main()
{
	char str1[20]="i love you",str2[20];
loop:	puts("enter your password");
gets(str2);
if(strcmp(str1,str2)==0)
   puts("welcome to windows");
   else goto loop;

	
	
	
 } 
