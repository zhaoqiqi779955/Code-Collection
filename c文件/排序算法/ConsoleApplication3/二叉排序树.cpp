/*#include<iostream>
using namespace std;
template <class T>
struct Node//未知类型存在时切忌不可使用typedef
{
	T key;
	Node *left,*right;
};

template <class T>
class BST
{
	Node<T> *root;
public:
	BST()
	{
		root=NULL;
	}
	Node<T> *search_BST(Node<T> *N,T key)
	{
		if(!N) return NULL;
		else {
			if(isEquivalent(key,N)==0)
			{
				return N;
			}
			else if(isEquivalent(key,N)==-1) 
				search_BST(N->left,key);
			else search_BST(N->right,key);
		}
	}

	bool insert_BST(Node<T> *N,T key)
	{
		Node<T> *pnew=new Node<T>;
		pnew->key=key;
		pnew->left=NULL;
		pnew->right=NULL;
		if(N==NULL)
		{
			root=pnew;
			return true;
		}
		Node<T> *p,*q=N;
		bool flag=true;
		p=N;
		while(p)
		{
			q=p;
			if (isEquivalent(key,p)==0)
			{
				return false;
			}
			else if (isEquivalent(key,p)==-1)
			{
				p=p->left;
				flag=true;
			}
			else if(isEquivalent(key,p)==1)
			{
				p=p->right;
				flag=false;
			}
		}
		if(flag) q->left=pnew;
		else q->right=pnew;
		return true;
	}

	int isEquivalent(T key,Node<T> *p)
	{
		if(p->key<key) return 1;
		else if(p->key>key) return -1;
		else  return 0;
	}

	bool delete_BST(Node* &N,int key)
	{
		if(!N) return false;
		else if(isEquivalent(key,N)==-1) return delete_BST(N->left,key);
		else if(isEquivalent(key,N)==1) return delete_BST(N->right,key);
		else delete_Node(N);
		
	}
	void delete_Node(Node*& p)
	{
		Node *q=p;
		if(!p->right)
		{
			p=p->left;
			delete p;
		}
		else if(!p->left)
		{
			p=p->right;
			delete q;

		}
		else
		{
			Node *s=p->left;
			while (s->right)
			{
				q=s;
				s=s->right;
			}
			p->key=s->key;
			if(q!=p)
			 q->right=s->left;
			else q->left=s->left;
		}
	}

	Node<T> *crate_BST(T a[],int n)
	{
		for (int i=0;i<n;i++)
		{
			insert_BST(root,a[i]);
		}
		return root;
	}


	void show()
	{
		InorderTraverse(root);
	}


	void InorderTraverse(Node<T> *p)
	{
		if(p==NULL) return;
		if (p->left)
		InorderTraverse(p->left);
		cout<<p->key<<" ";
		if (p->right)
		InorderTraverse(p->right);

	}
	
};

int main()
{
	int a[100];
	int n;
	cin>>n;
	for (int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	BST<int> obj;
	obj.crate_BST(a,n);
	obj.show();
}*/