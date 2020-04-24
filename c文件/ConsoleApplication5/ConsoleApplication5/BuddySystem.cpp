#include<iostream>
#include<list>
#include<vector>
#include<math.h>
using namespace std;

class Buddy_system
{
	char *zone_mem_map;//ָ���ʼ�������ܿռ�
	int m;//��ʼ�����������ܿռ�ȡ2�Ķ���
	vector<list<int> > block_free;//�洢�������Ϳ�����Ա���������
	vector<list<int> > block_occupied ;//��ռ������

public:
	Buddy_system(int n)
	{
		m=n;
		zone_mem_map=new char [(int)pow(2,m)];//��ʼ���������ڴ�ռ�
		block_occupied.resize(m+1);
		block_free.resize(m+1);
		block_free[m].push_back(0);
	}
	int get_n_index(int n)//��ȡ2��n����
	{
		return (int)(pow(2,n));
	}
	int get_index(int size)//��ȡsize����Ӧ�Ŀ��±�
	{
		int t=0;
		while (size>0)
		{
			size/=2;
			t++;
		}
		return t;

	}


	void request_memory(int size)//nΪ�����ڴ��С
	{
		if(size<0) {
			cout<<"size must be positive��"<<endl;
			return;
		}

		int index=get_index(size);
		cout<<index<<endl;
		if(index>m) {
			cout<<"insufficient memory!"<<endl;
			return;
		}

	
		for (int i=index;i<=m;i++)
		{
			if (!block_free[i].empty())
			{
				seperate(i,index);
				return;
			}
		}
		cout<<"insufficient memory!"<<endl;
		
	}


	void seperate(int index1,int index2)//��index1�ڴ��ȡһ������2��index2���ݿռ�
	{
		int adr=block_free[index1].back();//��ȡ��¼index1�ڴ������һ������ڴ��ַ
		for (int i=index1;i>index2;i--)
		{
			int n=get_n_index(i-1)+adr;
			block_free[i-1].push_back(n);

		}
		block_occupied[index2].push_back(adr);//�����һ��2��index2���ݴ�С�ռ䣻
		block_free[index1].pop_back();//�������ڴ��һ
	}


	void release_memory(int index)//�ͷ�2��index���ݴ�С�ڴ�
	{
		if(block_occupied[index].empty())
		{

			cout<<"the area remains free!"<<endl;
			return;
		}
		
		int adr=block_occupied[index].back();
		block_occupied[index].pop_back();
		for (int i=index;i<=m;i++)
		{
			
			list<int>::iterator it=find_buddy(i,cal_buddy(adr,i));
			if(it==block_free[i].end()){
				block_free[i].push_back(adr);

				break;
			}
			else{
				int adr1=*it;
				block_free[i].erase(it);
				if(adr>adr1) adr=adr1;

			}
		}
	}
	list<int>::iterator find_buddy(int index,int adr)
	{
		for (auto it=block_free[index].begin();it!=block_free[index].end();it++)
		{
			if (*it==adr)
			{
				return it;//���ػ���������
			}
		}
		return block_free[index].end();//û�л�鷵��
	}
	int cal_buddy(int adr,int index)//�����ַΪadr����СΪ2��index���ݵĻ���ַ
	{
		int rem=adr%get_n_index(index+1);
		if(rem==0) return (adr+get_n_index(index));
		else if(rem=get_n_index(index)) return get_n_index(index);
	}
	void show_state()//����ڴ�״̬
	{
		cout<<"free area:"<<endl;
		for (int i=0;i<=m;i++)
		{
			cout<<"2��"<<i<<"�η��洢����:"<<block_free[i].size()<<"��:  ";
			int size=get_n_index(i);
			list<int>::iterator it=block_free[i].begin();
			
			for (int j=1;it!=block_free[i].end();j++,it++)
			{
				
				cout<<"No"<<j<<":"<<*it<<"--"<<*it+size-1<<"("<<(void *)(zone_mem_map+*it)<<"--"<<(void *)(zone_mem_map+*it+size-1)<<")  ";
				
			}

			cout<<endl;
		}
		cout<<"occupied area:"<<endl;
		for (int i=0;i<=m;i++)
		{
			cout<<"2��"<<i<<"�η��洢����:"<<block_occupied[i].size()<<"��:  ";
			int size=get_n_index(i);
			list<int>::iterator it=block_occupied[i].begin();

			for (int j=1;it!=block_occupied[i].end();j++,it++)
			{
				cout<<"No"<<j<<":"<<*it<<"--"<<*it+size-1<<"("<<(void *)(zone_mem_map+*it)<<"--"<<(void *)(zone_mem_map+*it-1+size)<<")  ";
			}
			cout<<endl;
		}
	}

};
int main()
{
	int k;
	Buddy_system test(10);
	int t=5;
	while(t--)
	{
		
		cout<<"����������ռ�����"<<endl;
		int size;
		cin>>size;
		test.request_memory(size);
		test.show_state();
		cout<<"�������ͷŵĴ洢���С���ͣ�"<<endl;
		cin>>size;
		test.release_memory(size);
		test.show_state();
		cout<<endl<<endl;
	}


}