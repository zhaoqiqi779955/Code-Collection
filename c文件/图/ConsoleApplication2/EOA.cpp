/*#include<iostream>
#include<vector>
#include<stack>
using namespace std;
typedef struct ArcNode
{
	int weight;
	int adjvex;
} arcNode;
typedef struct  
{
	string data;
	vector<arcNode> adjarc;//�ڽӱ�

} vertex;
class Graph
{
	int vexnum;
	int arcnum;
	vector<int> ve;//��¼��ʱ�����翪ʼʱ��
	stack<int> top_sort_stack;//����������
	vector<vertex> vex;

public:
	Graph(int vn,int arcn,int a[][3])
	{
		vexnum=vn;
		arcnum=arcn;
		vex.resize(vn);
		for (int i=0;i<arcn;i++)
		{
			int x=a[i][0];
			int y=a[i][1];
			int weight=a[i][2];
			arcNode tem={weight,y};
			vex[x].adjarc.push_back(tem);

		}
	}

	void TopologicalOrder()
	{
		int count=0;//���ڼ����Ӷ��ж��Ƿ��л�
		vector<int> indegree(vexnum);//��¼�������
		//��ʼ�����
		for (int i=0;i<vexnum;i++)
		{
			for (int j=0;j<vex[i].adjarc.size();j++)
			{
				indegree[vex[i].adjarc[j].adjvex]++;
			}
		}
		stack<int> zero_indegree;//�洢���Ϊ���
		for (int i=0;i<vexnum;i++)
		{
			if(indegree[i]==0) zero_indegree.push(i);
		}
		ve.resize(vexnum);
		while (!zero_indegree.empty())
		{
			int x=zero_indegree.top();

			zero_indegree.pop();
			top_sort_stack.push(x);
			count++;
			for (int i=0;i<vex[x].adjarc.size();i++)
			{
				int k=vex[x].adjarc[i].adjvex;
				indegree[k]--;//��ȼ�һ
				if (indegree[k]==0)
				{
					zero_indegree.push(k);
				}
				if (ve[x]+vex[x].adjarc[i].weight>ve[k])
				{
					ve[k]=ve[x]+vex[x].adjarc[i].weight;
				}

			}

		}
		for (int i=0;i<vexnum;i++)
		{
			cout<<ve[i]<<" ";
		}
		cout<<endl;
	}


	void criticalPath()
	{
		int j=top_sort_stack.top();
		vector<int> vl(vexnum);//���¼�����ʼʱ��
		for (int i=0;i<vexnum;i++)
		{
			vl[i]=ve[j];
		}
		while(!top_sort_stack.empty())
		{

			int j=top_sort_stack.top();
			top_sort_stack.pop();
			for (int i=0;i<vex[j].adjarc.size();i++)
			{
				int k=vex[j].adjarc[i].adjvex;
				int weight=vex[j].adjarc[i].weight;
				if (vl[k]-weight<vl[j])
				{
					vl[j]=vl[k]-weight;
				}
			}
		}

		//���������ʱ��
		for (int i=0;i<vexnum;i++)
		{
			cout<<vl[i]<<" ";
		}
		cout<<endl;
	}

};

int main()
{
	int n,m;
	cin>>n>>m;
	int a[100][3];
	for (int i=0;i<m;i++)
	{
		for (int j=0;j<3;j++)
		{
			cin>>a[i][j];
		}
	}
	Graph obj(n,m,a);
	obj.TopologicalOrder();
	obj.criticalPath();

}*/