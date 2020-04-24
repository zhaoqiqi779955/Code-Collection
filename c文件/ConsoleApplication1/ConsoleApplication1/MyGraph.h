#include<iostream>
#include<vector>
using namespace std;
typedef struct  ArcNode//弧结点
{
	int adjvex;//指向的顶点下坐标
	ArcNode *nextArc;//下一条邻接边
	int *info;//边信息,如权
} ArcNode;
typedef struct VNode  //顶点
{
	char data;//数据
	ArcNode *first;//第一条边
} VNode;
class Graph
{
	vector<VNode> vexs;//存储顶点信息
	int vexnum,arcnum;//分别存储顶点数和弧数
	char kind;//图的种类
public:
	Graph(char type,vector<char>  &vex,vector<vector<char> > &arc)//后两个分别传递顶点跟边
	{
		kind=type;
		vexnum=vex.size();
		arcnum=arc.size();
		for (int i=0;i<vexnum;i++)//创建顶点
		{
			VNode *p=new VNode[1];
			p->data=vex[i];
			p->first=NULL;
			vexs.push_back(*p);
		}
		for (int i=0;i<arcnum;i++)
		{
			char ch1=arc[i][0];//弧尾顶点
			char ch2=arc[i][1];//弧头
			int loc=find(ch1);
			ArcNode *tem=new ArcNode[1];
			tem->adjvex=find(ch2);
			tem->info=0;
			tem->nextArc=NULL;
			ArcNode *p=findp(loc);
			if(!p) vexs[loc].first=tem;//
			else p->nextArc=tem;


		}
	}
	ArcNode * findp(int loc)//查顶点最后一条弧地址
	{
		ArcNode *p=vexs[loc].first;
		if (!p)
		{
			return NULL;
		}
		while (p->nextArc)
		{
			p=p->nextArc;
		}
		return p;
	}
	int find(char ch)
	{
		for (int i=0;i<vexnum;i++)
		{
			if(vexs[i].data==ch) return i;
		}
		return -1;
	}
	void show()
	{
		for (int i=0;i<vexnum;i++)
		{
			cout<<i<<" "<<vexs[i].data;
			ArcNode *p=vexs[i].first;
			while(p)
			{
				cout<<"-"<<p->adjvex;
				p=p->nextArc;
			}
			cout<<"-^";
		}
	}

};
