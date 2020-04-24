#include<iostream>
using namespace std;
struct link {
	int data;
	link *next;
	link *last;	
};

typedef struct link Node;
Node *create_list()
{
	Node *head,*tail,*pnew;
	head= new Node [1];
	head->next=NULL;
	head->last=NULL;

	tail=head;
	int n;
	cin>>n;
	while(n--)
	{
		pnew=new Node [1];
		if(pnew==NULL) cout<<"no sufficient memory";
		int d;
		cin>>d;
		pnew->data=d;
		tail->next=pnew;
		pnew->last=tail;
		tail=pnew;
	
	}
	return tail;
	
}
void display(Node *tail)
{
	Node *p=tail;
	while(p->last!=NULL)
	{
		cout<<p->data<<" ";
		p=p->last;
		
	}
	cout<<endl;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		Node *tail;
		tail=create_list();
		display(tail);
	}
	
	
	
	
	
	
	
	
	
	
}
