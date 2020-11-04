#include "toolkit.h"
#include<math.h>
#include<time.h>
#include<stdlib.h>
#include <iostream>
using std::cout;
using std::endl;
int randint(int min, int max)
{
	static clock_t last=0;
	
	clock_t now = clock();
	static unsigned int seed;
	if (now - last > 1000) {
		seed = now;
		last = now;
	}

	srand(seed);
	seed = rand() % (max - min) + min;
	return seed;
}
void randint(int a[], int n, int min, int max)//n为产生随机数的个数
{
	srand((unsigned)time(0));

	for (int i = 0; i < n; i++)
	{
		a[i] = rand()%(max - min) + min;
	}
	
}

int getBitNum(int n)
{
	int  k = 1;
	while (n>1)
	{
		k++;
		n=n >> 1;
	}
	return k;
}
Point_Vec::Point_Vec()
{

}
Point_Vec::Point_Vec(double xx, double yy)
{
	x = xx;
	y = yy;

}
Point_Vec Point_Vec::operator -(const Point_Vec& p)
{
	Point_Vec res(x - p.x, y - p.y);
	return res;
}
Point_Vec Point_Vec::operator +(const Point_Vec& p)
{
	Point_Vec res(x +p.x, y + p.y);
	return res;
}
double Point_Vec::operator *(const Point_Vec& p)
{
	double res=x * p.x+y * p.y;
	return res;
}
bool isInsideTriange(Point_Vec& p1, Point_Vec& p2, Point_Vec& p3, Point_Vec& s)
{
	Point_Vec h, u, v;
	h = s - p1;
	u = p2 - p1;
	v = p3 - p1;
	double y1, y2, x;
	x = u * v;
	y1 = u * h;
	y2 = v * h;
	double a, b, c;
	c = (u * u) * (v * v) - x * x;
	a = (y1 * (v * v) - x * y2) / c;
	b = ((u * u) * y2 - y1 * x) / c;
	if (c == 0) {
		cout << "not a triangle" << endl;
		return false;
	}
	if (a >=0 && b >= 0 && a + b <= 1) return true;
	else return false;


}

