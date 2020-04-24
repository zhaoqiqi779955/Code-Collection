#include <iostream>
#include<limits.h>
#include<string>
using namespace std;
#define MAX 50000
#define  MAXSIZE 20
class graph
{
	int vexnum;
	string vex[MAXSIZE];
	int matrix[MAXSIZE][MAXSIZE];
public:
	graph(string v[],int n, int mat[][MAXSIZE])
	{
		vexnum=n;
		for (int i=0;i<vexnum;i++)
		{
			vex[i]=v[i];
		}
		for (int i=0;i<n;i++)
		{
			for (int j=0;j<n;j++)
			{
				matrix[i][j]=mat[i][j];
			}
		}

	}
	
	graph(int n, int mat[][MAXSIZE])
	{
		vexnum=n;
		for (int i=0;i<n;i++)
		{
			for (int j=0;j<n;j++)
			{
				matrix[i][j]=mat[i][j];
			}
		}

	}
	void Topo()
	{
		int count=0;
		int inDegree[MAXSIZE];
		bool visit[MAXSIZE];
		for (int i=0;i<vexnum;i++)
		{
			visit[i]=false;
			inDegree[i]=0;
		}
		for (int i=0;i<vexnum;i++)
		{
			for (int j=0;j<vexnum;j++)
			{
				if(matrix[j][i]) inDegree[i]++;
			}
		}
		bool flag;
		while (1)
		{
			flag=false;
			int i;
			for ( i=0;i<vexnum;i++)//Ѱ�����Ϊ0��
			{
				if(!visit[i]&&inDegree[i]==0){
					visit[i]=true;
					flag=true;
					break;
				}
			}
			if (!flag)
			{
				break;
			}
			cout<<i<<" ";
			for (int j=0;j<vexnum;j++)
			{
				if(matrix[i][j]) inDegree[j]--;
			}

		}
		
	}
	int getIndex(string v)
	{
		for (int i=0;i<vexnum;i++)
		{
			if (vex[i]==v)
			{
				return i;
			}
		}
		return -1;
	}
	void Dijkstra(string v)
	{
		int shortPath[MAXSIZE];//�洢����̽��㵽�������̾���
		bool visit[MAXSIZE];
		int fromVertex[MAXSIZE];
		int index=getIndex(v);
		for (int i=0;i<vexnum;i++)//��ʼ��
		{
			visit[i]=false;
			shortPath[i]=matrix[index][i];
			fromVertex[i]=index;
			
		}
		visit[index]=true;
		int count=1;//ͳ����̽������
		while (count<vexnum)
		{
			//�����·������һ��δ��������С�ĵ�
			int min,min_i;
			min=MAX;
			for (int i=0;i<vexnum;i++)
			{
				if(!visit[i]&&i!=index&&shortPath[i]!=0&&shortPath[i]<min)
				{
					min=shortPath[i];
					min_i=i;
				}
			}
			
			if(min==MAX)
			{
				break;
			}
			//����С������
			visit[min_i]=true;
			count++;
			//�ı��������Сֵ,�����shortPath
			for (int i=0;i<vexnum;i++)
			{
				if(i!=index) {
					int t=matrix[min_i][i]+shortPath[min_i];
					cout<<"t:"<<t<<" "<<shortPath[i]<<endl;;
					if(shortPath[min_i]!=0&&matrix[min_i][i]!=0) 
					{
						if(shortPath[i]==0||t<shortPath[i])
						fromVertex[i]=min_i;
						shortPath[i]=t;
					}
					

				}
				
			}
			
		}
		
		for (int i=0;i<vexnum;i++)
		{
			if(i!=index)
			{
				int t=fromVertex[i];
				cout<<vex[i]<<"<-";
				while (t!=index)
				{
					cout<<vex[t]<<"<-";
					t=fromVertex[t];
				}
				cout<<vex[index]<<endl;
			}
		}
	}
};
int main()
{
	int n;
	cin>>n;
	int mt[MAXSIZE][MAXSIZE];
	string str[MAXSIZE];
	/*for (int i=0;i<n;i++)
	{
		cin>>str[i];
	}*/
	for (int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>mt[i][j];
		}
	}
	graph obj(n,mt);
	obj.Topo();
}