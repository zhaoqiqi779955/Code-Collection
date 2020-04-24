/*#include<iostream>
#include<string>
#include<limits>
#include<list>
using namespace std;
#define  MAXSIZE 100
typedef struct arcNode
{
	int vex;//依赖的顶点索引
	int weight;
	arcNode *nextArc;
};

typedef struct vexNode
{
	string name;
	arcNode *firarc;
} ;
typedef struct edge
{
	int v1,v2;
	int weight;
	friend bool operator<(edge e1,edge e2)
	{
		return e1.weight<e2.weight;
	}
};
class Graph
{
	int vexnum;//点数量
	int arcnum;//边数量
	bool visit[MAXSIZE];
	vexNode vex[MAXSIZE];
	list<edge> list_edge;
public:
	Graph(string v[],int n)
	{
		for (int i=0;i<MAXSIZE;i++)
		{
			vex[i].firarc=NULL;

		}
		vexnum=n;
		for (int i=0;i<n;i++)
		{
			vex[i].name=v[i];
		}
		arcnum=0;
	}
	void insert(string v1,string v2,int weight)
	{
		int x1,x2;
		x1=getindex_vex(v1);//获取顶点下标
		x2=getindex_vex(v2);
		arcNode *tem=new arcNode;
		arcNode *head1=vex[x1].firarc;
		arcNode *head2=vex[x2].firarc;
		tem->vex=x2;
		tem->weight=weight;
		tem->nextArc=vex[x1].firarc;
		vex[x1].firarc=tem;
		tem=new arcNode;
		tem->vex=x1;
		tem->weight=weight;
		tem->nextArc=vex[x2].firarc;
		vex[x2].firarc=tem;
	}
	void insert_k(string v1,string v2,int weight)
	{
		int x1,x2;
		x1=getindex_vex(v1);//获取顶点下标
		x2=getindex_vex(v2);
		edge tem={x1,x2,weight};
		list_edge.push_back(tem);
		arcnum++;
	}

	void prim(string v)
	{
		int totalpath=0;
		int index=getindex_vex(v);
		int minDistance[MAXSIZE][2];//记录集合U到各点的距离最小值,和U中到个V顶点的顶点
		int min_i,min_w;//分别记录权值最小顶点的下标，和最小权值
		int count=1;
		for (int i=0;i<vexnum;i++)
		{
			visit[i]=false;
			minDistance[i][0]=INT_MAX;
			minDistance[i][1]=index;
		}
		visit[index]=true;
		arcNode *p=vex[index].firarc;
		min_w=INT_MAX;
		while (p)//初始化
		{
			minDistance[p->vex][0]=p->weight;
			if (p->weight<min_w)
			{
				min_w=p->weight;
				min_i=p->vex;
			}
			p=p->nextArc;
		}
		while (count<vexnum)
		{
			cout<<vex[minDistance[min_i][1]].name<<" "<<vex[min_i].name<<" "<<min_w<<endl;
			totalpath+=min_w;
			visit[min_i]=true;
			count++;
			//更新minDistance
			p=vex[min_i].firarc;
			while (p)
			{
				int i=p->vex;
				if(!visit[i]&&p->weight<minDistance[i][0]) {
					minDistance[i][0]=p->weight;
					minDistance[i][1]=min_i;
				}
				p=p->nextArc;
				
			}
			min_w=INT_MAX;
			for (int i=0;i<vexnum;i++)
			{
				if (!visit[i]&&minDistance[i][0]<=min_w)
				{
					min_w=minDistance[i][0];
					min_i=i;
				}
			}
			
		}
		cout<<totalpath<<endl;
		
	}
	void krusl()
	{
		list_edge.sort();
		int visit[MAXSIZE];
		for (int i=0;i<vexnum;i++)
		{
			visit[i]=i;
		}
		list<edge>::iterator it=list_edge.begin();
		for (int i=0;i<arcnum;i++,it++)
		{
			
			int x1=it->v1;
			int x2=it->v2;
			if (visit[x1]==visit[x2])
			{
				continue;
			}
			int weight=it->weight;
			if (x1>x2)//保证x1<x2;
			{
				int t=x1;
				x1=x2;
				x2=t;
			}
			//输出边
			cout<<vex[x1].name<<" "<<vex[x2].name<<" "<<weight<<endl;
			int set=visit[x2];
			//合并两个集合
			for (int i=0;i<vexnum;i++)
			{
				if (visit[i]==set)
				{
					visit[i]=visit[x1];
				}
			}
			int flag=true;
			for (int i=0;i<vexnum;i++)
			{
				if (visit[i]!=0)
				{
					flag=false;
					break;
				}
			}
			if(flag) break;
		}

	}
	
	int getindex_vex(string v)
	{
		for (int i=0;i<vexnum;i++)
		{
			if (v==vex[i].name)
				return i;
			
		}
		return -1;
	}
};
int main()
{
	
	int n;
	string v[MAXSIZE];
	string v1, v2;
	cin>>n;
	for (int i=0;i<n;i++)
	{
		cin>>v[i];

	}
	Graph obj(v,n);
	cin>>n;
	for (int i=0;i<n;i++)
	{
		int weight;
		cin>>v1>>v2>>weight;
		obj.insert(v1,v2,weight);
		obj.insert_k(v1,v2,weight);
	}
	cin>>v1;
	obj.prim(v1);
	cout<<endl;
    obj.krusl();


}*/