#include<iostream>
#include<vector>
using namespace std;
typedef struct  ArcNode//�����
{
	int adjvex;//ָ��Ķ���������
	ArcNode *nextArc;//��һ���ڽӱ�
	int *info;//����Ϣ,��Ȩ
} ArcNode;
typedef struct VNode  //����
{
	char data;//����
	ArcNode *first;//��һ����
} VNode;
class Graph
{
	vector<VNode> vexs;//�洢������Ϣ
	int vexnum,arcnum;//�ֱ�洢�������ͻ���
	char kind;//ͼ������
public:
	Graph(char type,vector<char>  &vex,vector<vector<char> > &arc)//�������ֱ𴫵ݶ������
	{
		kind=type;
		vexnum=vex.size();
		arcnum=arc.size();
		for (int i=0;i<vexnum;i++)//��������
		{
			VNode *p=new VNode[1];
			p->data=vex[i];
			p->first=NULL;
			vexs.push_back(*p);
		}
		for (int i=0;i<arcnum;i++)
		{
			char ch1=arc[i][0];//��β����
			char ch2=arc[i][1];//��ͷ
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
	ArcNode * findp(int loc)//�鶥�����һ������ַ
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
