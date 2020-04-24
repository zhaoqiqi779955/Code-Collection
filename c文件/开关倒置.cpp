#include<stdio.h>
#include<string.h>

struct sudentinf 
{
	char no[20],name[9],sex;
	unsigned int age;
	unsigned int classno;
	float grade;
	
	
};

int main()
{
	struct sudentinf student1={"2018152110","ÕÔÆôÆì",'ÄĞ',20,90.0},stu2;
memcpy(&stu2,&student1,sizeof(struct sudentinf));
	printf("%s",stu2.no);
	
 } 
