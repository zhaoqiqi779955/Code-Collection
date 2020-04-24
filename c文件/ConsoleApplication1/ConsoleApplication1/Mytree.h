#ifndef MYTREE_H
#define MYTREE_H
#include<iostream>
#include<stack>
#define SPACE 0
#include<queue>
#include<string>
using namespace std;
typedef struct BiTNode
{
	int data;
	BiTNode *left,*right;

} *BiTree,*BTNode ;
class Bitree{
private:
	BiTree Root;
	int i;//用于类内部全局变量
	int depth;//树深度
	int longestTrace;
	int APL;
	int weigh;
	int count;//用于统计元素个数
public:
	Bitree(string str )
	{
		i=0;
		depth=0;
		longestTrace=0;
		Root=createBiTree(str);
		count=0;
	}

	void reset_i(int k=0)//重置类成员变量i
	{
		i=k;
	}

	bool visit(BiTree p)
	{
		cout<<p->data<<' ';
		return true;
	}
	int getlongestTrace(int a[])
	{
		reset_i();
		obtainLT(Root,a,0);

		return longestTrace;

	}
	int get_APL(int a[])
	{
		APL=0;
		reset_i(0);
		obtainAPL(Root,a,0);
		return APL;

	}
	void obtainAPL(BiTree p,int a[],int track)
	{
		if (!p->left&&!p->right)
		{
			APL+=a[i]*track;
			i++;
			return;
		}
		else {
			track++;
			if(p->left)
				obtainAPL(p->left,a,track);
			if (p->right)
			{
				obtainAPL(p->right,a,track);
			}

		}
	}
	void obtainLT(BiTree p,int a[],int trace)
	{
		if (!p)
		{
			if(longestTrace<trace) longestTrace=trace;
			return;
		}
		else {
			trace+=a[i];
			i++;
			obtainLT(p->left,a,trace);
			obtainLT(p->right,a,trace);
		}

	}


	int getdepth()//获取树深度
	{
		return depth;
	}



	void finddepth(BiTree p,int level)
	{
		if(!p) {
			if(level>depth) depth=level;
			return;
		}
		else {
			level++;
			finddepth(p->left,level);
			finddepth(p->right,level);

		}
	}



	void PreorderTraverse(BiTree T)//先序递归实现
	{
		if(T) {
			visit(T);
			PreorderTraverse(T->left);
			PreorderTraverse(T->right);
		}
		else return;

	}
	void InorderTraverse(BiTree T)//中序
	{
		if(T) {

			InorderTraverse(T->left);
			cout<<T->data;
			InorderTraverse(T->right);
		}
		else return;

	}



	void PastorderTraverse(BiTree T)//后续
	{
		if(T) {
			PastorderTraverse(T->left);
			PastorderTraverse(T->right);
			cout<<T->data;

		}
		else return;

	}


	void PrintAtLevel(BiTree T) {//分层输出
		queue<BiTree>  myqueue;
		myqueue.push(T);
		while (!myqueue.empty()) {
			BiTree tmp = myqueue.front();
			if (tmp->left != NULL)
				myqueue.push(tmp->left);
			if (tmp->right != NULL)
				myqueue.push(tmp->right);
			cout << tmp->data;
			myqueue.pop();
		}
	}

	BiTree createBiTree(string str)//递归创建树
	{
		char ch;
		ch=str[i++];
		if (ch==SPACE)
		{
			return NULL;
		}
		BiTree T=new BiTNode;
		T->data=ch;
		T->left=createBiTree(str);
		T->right=createBiTree(str);
		return T;
	}

	Bitree(int a[],int n)//数组形式先序建树 索引位置从0开始
	{
		Root=NULL;
		int pos=1;
		int k=0;
		BiTree p,pnext=NULL;//p指向当前节点
		p=new BiTNode[1];
		if (!p)
		{
			exit(0);
		}
		if(n>0) Root=p;
		else return;
		p->data=a[pos];
		stack<int>  st;
		stack<BiTree> pointSt;//指针堆栈指向待分配空间
		while(pos)
		{
			p->data=a[pos];
			int left=pos*2;
			int right=pos*2+1;
			
			bool l=(left<=n&&a[left]!=SPACE);
			bool r=(right<=n&&a[right]!=SPACE);
			if (l) { pos=left;
			   p->left=new BiTNode[1];
			   pnext=p->left;
			}
			else p->left=NULL;
			if(r) {
				st.push(right);
				p->right=new BiTNode[1];
				if (!p->right) 
				{
						exit(0);
				}
				pointSt.push(p->right);
				

			}
			else p->right=NULL;
			if (!l)
			{
				if(!st.empty())
				{

					pos=st.top();
					pnext=pointSt.top();
					pointSt.pop();
					st.pop();

				}
				else pos=0;
			}
			p=pnext;
		} 
		
	
		
	}




	void Pre(BiTree T)//非递归形式先序遍历
	{
		BiTree p=T;
		stack<BiTree> st;
		while (p)
		{
			visit(p);
			BTNode q=p;
			if (q->left)
			{
				p=q->left;

			}
			if (q->right)
			{
				st.push(q->right);
			}
			if (!q->left)
			{
				if(!st.empty()){
					p=st.top();
					st.pop();
				}
				else {
					p=NULL;
				}
			}
		}
	}


	void inTravesre_ur1()
	{
		BiTree p=Root;
		stack<BiTree> st;
		stack<BiTree> track;
		st.push(p);
		track.push(NULL);

		while(!st.empty()){
			p=st.top();
			if (p!=track.top())
			{
				while(p->left){
					track.push(p);
					st.push(p->left);
					p=p->left;
				}
			}
			else track.pop();

			visit(p);
			st.pop();
			if(p->right) st.push(p->right);

		}
	}


	void inTraverse_ur2()
	{
		BiTree p=Root;
		stack<BiTree> st;
		st.push(p);

		while(!st.empty()){
			p=st.top();
			while (p)
			{
				st.push(p->left);
				p=p->left;
			}
			st.pop();

			if (!st.empty())
			{
				p=st.top();
				visit(p);
				st.pop();
				st.push(p->right);
			}
		}
	}


	BiTree getRoot()
	{
		return Root;
	}


};

#endif;











