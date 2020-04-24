#include<iostream>
#define MAX_SIZE 50

using namespace std;
class Grapgh{
	int vexnum;
	//string vertex[MAX_SIZE];
	int matrix[MAX_SIZE][MAX_SIZE];
public:
	Grapgh(int vn,int mat[][MAX_SIZE])
	{
		vexnum=vn;
		/*for (int i=0;i<vexnum;i++)
		{
			vertex[i]=a[i];
		}*/
		for (int i=0;i<vexnum;i++)
		{
			for (int j=0;j<vexnum;j++)
			{
				matrix[i][j]=mat[i][j];
			}
		}
		
	}
	void Topological_Sort()
	{

		bool visit[MAX_SIZE];
		for (int i=0;i<vexnum;i++)
		{
			visit[i]=false;
		}
	
		while (1)
		{
			int count=0;
			for (int i=0;i<vexnum;i++)//找个点入度 i表示列
			{
				if(!visit[i])
				{
					int j;
					for (j=0;j<vexnum;j++)
					{
						if(matrix[j][i]!=0) break;
					}
					if (j<vexnum)
					{
						continue;
					}
					count++;
					cout<<i<<" ";
					visit[i]=true;
					//删除以i为尾的边
					for (int k=0;k<vexnum;k++)
					{
						matrix[i][k]=0;
					}
					/*for (int i=0;i<vexnum;i++)
					{
						for (int j=0;j<vexnum;j++)
						{
							cout<<matrix[i][j]<<" ";
						}
						cout<<endl;	
					}*/

				}
				
			}
			if (count==0)
			{
				break;
			}
		}
	}



};
int main()
{
	int t;
	cin>>t;
	while (t--)
	{
		int n;
	
		int matrix[MAX_SIZE][MAX_SIZE];
		cin>>n;

		for (int i=0;i<n;i++)
		{
			for (int j=0;j<n;j++)
			{
				cin>>matrix[i][j];
			}
		}

		Grapgh obj(n,matrix);
		obj.Topological_Sort();
		cout<<endl;

	}
}

