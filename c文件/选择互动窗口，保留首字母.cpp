#include<iostream>
using namespace std;
char getfirst()
{
	int ch=getchar();
	while(getchar()!='\n')
	 continue;
	return ch;
}
char get_choice()
{
	int ch;
	printf("Enter the letter of your choice\n");
	printf("a. advivce		b.bell\nc. count		q. quit\n");
	ch=getfirst();
	while((ch<'a'||ch>'c')&&ch!='q')
	{
		printf("Please respond with a,b,c,or q\n");
		ch=getfirst();
	}
	return  ch;
}

int main()
{
    char ch;
    ch=get_choice();
	
	
}

