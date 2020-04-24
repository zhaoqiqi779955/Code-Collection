#include<iostream>
using namespace std;

typedef struct BTNode
{
	BTNode *left;
	BTNode *right;
	int data;
} *BiTree;
class Tree{
	BiTree root;
public:
	Tree()
	{

	}
	bool insert(int x)
	{
		return insert_data(root,x);
	}
	bool insert_data(BiTree &T,int data)
	{
		BiTree p;
		if(T==NULL) {
			T=new BTNode[1];
			T->data=data;
			T->left=NULL;
			T->right=NULL;
			return true;

		}
		else if(data>T->data)
		{
			return insert_data(T->right,data);
		}
		else
			return insert_data(T->left,data);
	}
	bool search(BiTree T,int data)
	{
		if(T==NULL) return false;
		else if(T->data<data) return search(T->right,data);
		else return search(T->left,data);
	}
	bool delete_data(int data)
	{
		BiTree p=root;
		while (p)
		{
			if(p->data==data) break;
			else if(p->data<data) p=p->right;
			else p=p->left;
			
		}
		if(p==NULL) return false;
		if(!p->left){
			p=p->right;
		}
		else if(!p->right)
		{
			p=p->left;
		}
		else
		{
			BiTree q=p->left,s=NULL;
			while (q->right)
			{
				s=q;
				q=q->right;
			}
			p->data=q->data;
			if(s)
			   s->right=q->left;
			else p->left=q->left;
			delete q;
			
		}
	}
	void show()
	{
		PreOrderTraverse(root);
		cout<<endl;
	}
	void PreOrderTraverse(BiTree T)
	{

		if(!T) return;
		else{
			PreOrderTraverse(T->left);
			visit(T);
			PreOrderTraverse(T->right);
		}
	}
	void visit(BiTree T)
	{
		cout<<T->data<<" ";
	}

};



int main()
{
	int x;
	Tree tree;
	while((cin>>x)!=NULL)
	{
		tree.insert(x);
	}
	tree.show();
	
	int y;
	cin>>y;
	cout<<y<<endl;;
	tree.delete_data(3);
	tree.show();
}