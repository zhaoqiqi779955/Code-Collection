#include<stdio.h>
#include<conio.h>
int main()
 {
 int x;
 scanf("%x",&x);
 printf("%x%x%x%x",x%16,x%(16*16)/16,x/(16*16)%16,x/(16*16*16));
 }
