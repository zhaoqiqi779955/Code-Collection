#include"Head.h"
#include<windows.h>
#include<algorithm>
#include<set>
#include<vector>;
#include<time.h>
#include<math.h>
int sys=0;
using namespace std;
#define random(x) (rand()%x)
Point::Point(int xx,int yy)
{
	x=xx;
	y=yy;
}
double Point::calDistance(const Point &p) const
{
	double t=sqrt(pow(x-p.x,2)+pow(y-p.y,2));
	return t;
}
void Point::show() const
{

	cout<<"("<<x<<","<<y<<") "<<endl;
}
Point::Point()
{

}
//struct MyComp
//{
//	bool operator () (const Point &p1,const Point &p2)
//	{
//		if(p1.x==p2.x&&p1.y==p2.y) return true;
//		else return false;
//	}
//};
Point *	yieldPoints(int n)
{
	
	Point *p=new Point[n];
	set<Point> con;
	srand((int) (time(0)+sys++));
	//cout<<sys<<endl;
	while (con.size()<n)
	{
		
		int x,y;
		x=random(1000);
		y=random(1000);
		Point tem=Point(x,y);
		con.insert(tem);
		

	}
	int i=0;
	for (auto it=con.begin();it!=con.end();it++)
	{
		p[i]=*it;
		/*p[i].show();*/
		i++;
	}
	return p;

}

void findMinPointPair_enum(Point *points,int n)
{
	double min=points[0].calDistance(points[1]);
	int index1=0,index2=1;
	for (int i=0;i<n-1;i++)
	{
		for (int j=i+1;j<n;j++)
		{
			double res=points[i].calDistance(points[j]);
			if(res<min)
			{
				min=res;
				index1=i;
				index2=j;
			}
		}
	}
	cout<<"最小点对： ";
	points[index1].show();
	points[index2].show();
	cout<<"最小值"<<min<<endl;
}

minPair merge(Point *p,vector<int> &s1,vector<int> &s2,double d)//合并连个点集
{
	vector<sortPair> sp;
	auto it=s1.rbegin();
	int x0=p[*it].x;
	sortPair tem={p[*it],true};
	sp.push_back(tem);
	it++;
	while(it!=s1.rend())
	{
		if(p[*it].x>=x0-d) 
		{
			sortPair tem={p[*it],true};
			sp.push_back(tem);
		}
		else break;
		it++;
	}

	
	for (auto it=s2.begin();it!=s2.end();it++)
	{
		if(p[*it].x<=x0+d)
		{
			sortPair tem={p[*it],false};
			sp.push_back(tem);
		}
		else break;
	}


	sort(sp.begin(),sp.end()); //sort(sp) #对sp中点按照y升序排序
	minPair result;
	result.min=0;
	int i=0;
	while (i<sp.size())
	{
		if(sp[i].isleft)
		{

			int j=i-1;
			int count=0;
			while (j>=0&&count<3)//向下找三个
			{
				if(!sp[j].isleft)
				{
					double dis=sp[i].calDistance(sp[j]);
					if(dis<d) {
						d=dis;
						minPair tem={sp[i].p,sp[j].p,d};
						result=tem;
						
					}
					count++;
				}
				j--;
			}
			j=i+1;
			count=0;
			while (j<sp.size()&&count<3)
			{
				if(!sp[j].isleft)
				{
					double dis=sp[i].calDistance(sp[j]);
					if(dis<d) {
						d=dis;
						minPair tem={sp[i].p,sp[j].p,d};
						result=tem;
						
					}
					count++;
				}
				j++;
			}
		}
		i++;
	}
	return result;
	
}

minPair findMinPair(Point *p,vector<int> &index)//找寻当前集合下最小点对
{
	int n=index.size();

	if(n==2) { //当只有两个点时
		double min=p[index[0]].calDistance(p[index[1]]);
		minPair tem={p[index[0]],p[index[1]],min};
		return tem;

	}

	if(n==3){//当只有三个点时
		double d1,d2,d3;
		d1=p[index[0]].calDistance(p[index[1]]);
		d2=p[index[0]].calDistance(p[index[2]]);
		d3=p[index[1]].calDistance(p[index[2]]);
		double m1,m2,min;
		m1=d1<d2?d1:d2;
		m2=d1<d3?d1:d3;
		min=m1<m2?m1:m2;
		if(min==d1) {
			minPair tem={p[index[0]],p[index[1]],min};
			return tem;
		}
		else if (min==d2)
		{

			minPair tem={p[index[0]],p[index[2]],min};
			return tem;

		}
		else  {
			minPair tem={p[index[1]],p[index[2]],min};
			return tem;
		}

	}

	//大于三个点时
	int half=n/2;
	vector<int> s1,s2;
	 int i=0;
	auto it=index.begin();
	while (i<half)
	{
		s1.push_back(*it);
		i++;
		it++;
	}

	while (it!=index.end())
	{
		s2.push_back(*it);
		it++;
	}

	minPair mp1=findMinPair(p,s1);
	minPair mp2=findMinPair(p,s2);
	double d=mp1.min>mp2.min?mp2.min:mp1.min;
	minPair res=merge(p,s1,s2,d);
	if (res.min!=0) return res;
	else if(mp1.min<mp2.min) return mp1;
	else return mp2;

	


}

void findMinPointPair_divide(Point *p,int n)
{
	vector<int> index;
	for (int i=0;i<n;i++)
	{
		index.push_back(i);
	}
	minPair result=findMinPair(p,index);
	cout<<"最小点对: ";
	result.p1.show();
	result.p2.show();
	cout<<" "<<result.min<<endl;

}

