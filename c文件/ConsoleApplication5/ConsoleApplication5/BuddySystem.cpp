#include<iostream>
#include<list>
#include<vector>
#include<math.h>
using namespace std;

class Buddy_system
{
	char *zone_mem_map;//指向初始可利用总空间
	int m;//初始化最大可利用总空间取2的对数
	vector<list<int> > block_free;//存储各种类型块的线性表（空闲区）
	vector<list<int> > block_occupied ;//（占用区）

public:
	Buddy_system(int n)
	{
		m=n;
		zone_mem_map=new char [(int)pow(2,m)];//初始化管理总内存空间
		block_occupied.resize(m+1);
		block_free.resize(m+1);
		block_free[m].push_back(0);
	}
	int get_n_index(int n)//获取2的n次幂
	{
		return (int)(pow(2,n));
	}
	int get_index(int size)//获取size所对应的块下标
	{
		int t=0;
		while (size>0)
		{
			size/=2;
			t++;
		}
		return t;

	}


	void request_memory(int size)//n为申请内存大小
	{
		if(size<0) {
			cout<<"size must be positive！"<<endl;
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


	void seperate(int index1,int index2)//将index1内存块取一块分配出2的index2次幂空间
	{
		int adr=block_free[index1].back();//获取记录index1内存块区的一块空闲内存地址
		for (int i=index1;i>index2;i--)
		{
			int n=get_n_index(i-1)+adr;
			block_free[i-1].push_back(n);

		}
		block_occupied[index2].push_back(adr);//分配出一块2的index2次幂大小空间；
		block_free[index1].pop_back();//空闲区内存减一
	}


	void release_memory(int index)//释放2的index次幂大小内存
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
				return it;//返回伙伴结点迭代器
			}
		}
		return block_free[index].end();//没有伙伴返回
	}
	int cal_buddy(int adr,int index)//计算地址为adr，大小为2的index次幂的伙伴地址
	{
		int rem=adr%get_n_index(index+1);
		if(rem==0) return (adr+get_n_index(index));
		else if(rem=get_n_index(index)) return get_n_index(index);
	}
	void show_state()//输出内存状态
	{
		cout<<"free area:"<<endl;
		for (int i=0;i<=m;i++)
		{
			cout<<"2的"<<i<<"次方存储块有:"<<block_free[i].size()<<"个:  ";
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
			cout<<"2的"<<i<<"次方存储块有:"<<block_occupied[i].size()<<"个:  ";
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
		
		cout<<"请输入申请空间数量"<<endl;
		int size;
		cin>>size;
		test.request_memory(size);
		test.show_state();
		cout<<"请输入释放的存储块大小类型："<<endl;
		cin>>size;
		test.release_memory(size);
		test.show_state();
		cout<<endl<<endl;
	}


}