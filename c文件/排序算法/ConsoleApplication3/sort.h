#ifndef SORT_H
#define SORT_H
#include<iostream>
using namespace std;
void show(int a[],int n);
void show(int a[],int begin,int end);
int * getArray(int n);
void quick_sort(int a[],int low,int high);//��������
void quick_sort(int a[],int n);
void SelectSort(int a[],int n);//ѡ������
void bubble_sort(int a[],int n);//ð������
void merge_sort(int a[],int n);//�鲢����
void insert_sort(int a[],int len);//��������
double test( void (*sort)(int a[],int n),int a[],int n,int mag);//�����ض������㷨�ٶ�
void quick_sort_improve(int a[],int left,int right);
void quick_sort_improve(int a[],int n);
void insert_sort(int a[],int begin,int end);
#endif
