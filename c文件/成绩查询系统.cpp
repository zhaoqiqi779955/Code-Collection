#include<stdio.h>
#include<string.h>
#define student stu
#define stc student[i].grade
struct scores 
{
	int Chinese;
	int math;
	int English;
};
struct studentsinformation 
{
	char number[12];
	char name[10];
	char sex; 
	struct scores grade;
};

typedef struct studentsinformation ss;
int main()
{
	char number[11];
	int i;
	ss student[10]={{"2018152110","赵启旗",'M',{90,90,90}}};
	strcpy(stu[1].number,"2018152114") ;
	strcpy(student[1].name,"李鑫");
	stu[1].sex='M';
	stu[1].grade.math=90;
	stu[1].grade.Chinese=100;
	stu[1].grade.English=100;
	puts("please input the retrieving name ");
	gets(number);
	for(i=0;i<10;i++)
	 if(!(strcmp(number,stu[i].name)))
	 {
	 	printf("   学号	  	姓名   性别	  语文	   数学	   英语\n");
		printf("%s     %s	 %c 	  %d 	   %d 	    %d",stu[i].number,stu[i].name,stu[i].sex,stc.Chinese,stc.math,stc.English) ;
		 break;
	 }
	 
	if(i>9) printf("no such a student");
 } 
 
