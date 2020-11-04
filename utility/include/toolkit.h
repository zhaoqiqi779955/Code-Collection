#ifndef MY_TOOL
#define  MY_TOOL
#include<iostream>
using std::cout;
using std::endl;

//����������
template <class T>
void swap(T& a, T& b)
{
	T tem = a;
	a = b;
	b = tem;


}
void  randint(int a[], int n, int min, int max);//nΪ����������ĸ���
int randint(int min, int max);
//��һ������λ��
int getBitNum(int n);

class Point_Vec
{
public:
	double x, y;
	Point_Vec(double xx, double yy);
	Point_Vec();
	Point_Vec operator -(const Point_Vec & p);
	Point_Vec operator +(const Point_Vec& p);
	double operator *(const Point_Vec& p);
};

template <typename T>
void show(T a[], int n)
{
	for (int i=0;i<n;i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}
bool isInsideTriange(Point_Vec& p1, Point_Vec& p2, Point_Vec& p3, Point_Vec& s);
#endif
