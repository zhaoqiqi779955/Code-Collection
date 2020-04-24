#include<iostream>
using namespace std;

int getnumber()
{
	int num;
	while(scanf("%d",&num)!=1)
	{
		cout<<"your input was not a number"<<endl;
		scanf("%*s");
	}
	return num;
}
struct linklist
{
	int data;
	linklist *next;
};
typedef struct linklist Node;
Node *createlist()
{
	Node *head,*pnew,*tail;
	head=new Node[1];
	tail=head;
	head->next=NULL;
	int n;
	cin>>n;
	while(n--)
	{
		int data;
		cin>>data;
		pnew=new Node [1];
		if(pnew==NULL) cout<<"no sufficient memory";
		pnew->data=data;
		tail->next=pnew;
		tail=pnew;
	}
	tail->next=NULL;
	return head; //一定要返回头指针，并且最后一个节点的next要为空，方便后续访问；
	 
}

void display(const Node * const head)
{
	Node *p=head->next;
	   while(p!=NULL) 
	   {
	    cout<<p->data<<" ";
	    p=p->next;
	  }
	  cout<<endl;

}
void insert(Node *const head,int loc,Node *pnew)
{
	Node *p=head;
	Node *p1;
	int i=0;
	while(i<loc&&p->next!=NULL) 
	{
		p1=p;
	 p=p->next;
	 i++;
   } 
    cout<<i<<endl;
	if(i==loc) cout<<"ok"<<endl;
	else  {
	    cout<<"fault"<<endl;
	    return;
      }
	pnew->next=p;
	p1->next=pnew;
	
}
void deleteNode(Node *head,int loc)
{
	Node *p=head;
	Node *p1;
	int i=0;
	while(i<loc&&p->next!=NULL)
	{
		p1=p;
		p=p->next;
		i++;
		
	}
	if(i!=loc) {
		cout<<"fault"<<endl;
		return;
	}
	p1->next=p->next;
	delete p;
}
void deletelist(Node *head)
{
	Node *p=head;
	Node *p1;
	while(p->next!=NULL) {
		p1=p;
		p=p->next;
		delete p1;
	}
	delete p1;
	delete head;
		
 } 
int main()
{
	Node  *const head=createlist();
	display(head);
	int loc;
	cout<<"new data"<<endl;
	Node *pnew=new Node [1];
	int data;
	data=getnumber();
	pnew->data=data;
	pnew->next=NULL;
	cout<<"input location"<<endl;
	loc=getnumber();
	insert(head,loc,pnew);
	display(head);
	cout<<"input delete location"<<endl;
	loc=getnumber();
	deleteNode(head,loc);
	display(head);
	deletelist(head);
	display(head);
}








