/*#include<iostream>
#include<stack>
#include<queue>
#include<string>
using namespace std;
typedef struct BiTNode
{
	char  data;
	BiTNode *left,*right;
	bool flag;

} * BiTree ;
class Tree
{
	BiTree root;
	int i;
public:
	Tree(string str){
		i=0;
		root=createBiTree(str);
	}
	BiTree createBiTree(string str)
	{
		char ch=str[i];
		i++;
		if (ch=='#')
		{
			return NULL;
		}
		
		BiTree tem=new BiTNode;
		tem->data=ch;
		tem->flag=false;
		tem->left=createBiTree(str);
		tem->right=createBiTree(str);
		

		return tem;

	}

	void preOrder()
	{
		preOrederTraverse_N(root);
	}
	void preOrederTraverse(BiTree T)
	{
		if (!T)
		{
			return ;
		}
		visit(T);
		preOrederTraverse(T->left);
		preOrederTraverse(T->right);
	}
	void pastOreder()
	{
		pastOrederTraverse_N(root);
	}
	void preOrederTraverse_N(BiTree T)
	{
		stack<BiTree> st;
		BiTree p=T;
		while (p)
		{
			visit(p);
			p->flag=true;
			if(p->right) st.push(p->right);
			p=p->left;

		}
		
		while (!st.empty())
		{
			BiTree tem=st.top();
			st.pop();
			while (tem)
			{
				visit(tem);
				if(tem->right) st.push(tem->right);
				tem=tem->left;
			}

		}
	}
	void pastOrederTraverse_N(BiTree T)//∫Û–Ú∑«µ›πÈ
	{
		stack<BiTree> st;
		
		while (T)
		{
			st.push(T);
			T=T->left;
		}
		while (!st.empty())
		{
			BiTree p=st.top();
			if (!p->right||p->right->flag)
			{
				visit(p);
				p->flag=true;
				st.pop();
				continue;
			}
			else
			{
				p=p->right;
				while (p)
				{
					st.push(p);
					p=p->left;
				}
			}
		}
	}
	void inOrder()
	{
		inOrdertraverse(root);
	}

	void inOrdertraverse(BiTree T)
	{
		BiTree p=T;
		stack<BiTree> st;
		while (p)
		{
			st.push(p);
			p=p->left;
		}
		while (!st.empty())
		{
			BiTree p=st.top();
			visit(p);
			st.pop();
			if(!p->right||p->right->flag) continue;
			p=p->right;
			while (p)
			{
				st.push(p);
				p=p->left;
			}
		}
	}

	int get_deepth()
	{
		return deepth(root);
	}

	int deepth(BiTree T)
	{
	  if(!T) return 0;
	  int x=deepth(T->left)+1;
	  int y=deepth(T->right)+1;
	  if(x>y) return x;
	  else
	  {
		   return y;
	  }
	}
	bool isEqual(Tree t)
	{
		return equal(root,t.root);
	}
	bool equal(BiTree T1,BiTree T2)
	{
		if(!T1&&!T2) return true;
		if(!T1&&T2||!T2&&T1) return false;                                                        
		if(T1->data!=T2->data)  return false;
		else 
		{
			bool t1=equal(T1->left,T2->left);
			bool t2=equal(T1->right,T2->right);
			return t1&&t2;
		}
	}
	void layTraverse(BiTree T)
	{
		BiTree p=T;
		queue<BiTree> que;
		que.push(T);
		while (!que.empty())
		{
			BiTree p=que.front();
			que.pop();
			visit(p);
			if(p->left) que.push(p->left);
			if (p->right)
			{
				que.push(p->right);
			}
		}
	}

	void lay()
	{
		layTraverse(root);
	}

	void visit(BiTree T)
	{

		cout<<T->data<<" ";
		T->flag=true;
	}
	
};
int main()
{
	string str;
	cin>>str;
	Tree obj1(str);
	cin>>str;
	Tree obj2(str);
	cout<<obj1.isEqual(obj2);
		
}*/