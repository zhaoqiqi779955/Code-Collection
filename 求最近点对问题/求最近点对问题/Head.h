#ifndef  HEAD
#define  HEAD
#include<iostream>
class Point
{
	
public:
	int x,y;
	Point(int xx,int yy);
	Point();
	double calDistance(const Point &p) const;
	void show () const;
	bool operator <(const Point &p) const
	{
		if(x<p.x) return true;
		if(x==p.x&&y<p.y) return true;
		else return false;
	}
	bool operator ==(const Point &p) const
	{
		if(p.x==x&&p.y==y) return true;
		else return false;
	}
	
	
	
};

Point *	yieldPoints(int n);//生成一个随机点数组

void findMinPointPair_enum(Point *points,int n);
void findMinPointPair_divide(Point *p,int n);
struct minPair
{
	Point p1,p2;//用于记录最小点对坐标
	double min;
} ;
struct sortPair
{
	Point p;
	bool isleft;
	bool operator <(const sortPair &p2) const
	{
		return p.y<p2.p.y;
	}
	double calDistance(const sortPair &sp) const
	{
		return p.calDistance(sp.p);
	}
};
#endif
