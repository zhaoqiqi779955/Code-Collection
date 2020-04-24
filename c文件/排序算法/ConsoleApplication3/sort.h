#ifndef SORT_H
#define SORT_H
#include<iostream>
using namespace std;
void show(int a[],int n);
void show(int a[],int begin,int end);
int * getArray(int n);
void quick_sort(int a[],int low,int high);//øÏÀŸ≈≈–Ú
void quick_sort(int a[],int n);
void SelectSort(int a[],int n);//—°‘Ò≈≈–Ú
void bubble_sort(int a[],int n);//√∞≈›≈≈–Ú
void merge_sort(int a[],int n);//πÈ≤¢≈≈–Ú
void insert_sort(int a[],int len);//≤Â»Î≈≈–Ú
double test( void (*sort)(int a[],int n),int a[],int n,int mag);//≤‚ ‘Ãÿ∂®≈≈–ÚÀ„∑®ÀŸ∂»
void quick_sort_improve(int a[],int left,int right);
void quick_sort_improve(int a[],int n);
void insert_sort(int a[],int begin,int end);
#endif
