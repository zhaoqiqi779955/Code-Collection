#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
struct link//����ṹ�� 
{
	int data;
	struct link *next;
};
typedef struct link Node;
Node *createlink();//���������� 
void insert(Node *head,int i,Node *pnew);//���뺯�� 
int main()
{
	Node *p,*pn,*head;
	int i;
	p=createlink();
	head=p;//ͷָ�� 
	p=p->next;
	while(p!=NULL)
	{
	
	printf("%d ",p->data);
	p=p->next;
	
	}
	printf("\n");
	pn=(Node*)malloc(sizeof(Node));//��������ڵ� 
	if(pn==NULL)
	{
		printf("no enough memory");
		exit(0);
	}
	printf("input the  data\n");
	scanf("%d",&pn->data);
	puts("input locate");
	scanf("%d",&i) ;
	insert(head,i,pn);
		p=head;
	p=p->next;
	while(p!=NULL)
	{
	
	printf("%d ",p->data);
	p=p->next;
	
	}
	
	
 } 
 Node *createlink()//�������� 
{
	 Node *head ,*tail,*pnew;
	 int score;
	head=(Node*)malloc(sizeof(Node));
	if(head==NULL)
	{
		printf("no enough memory");
	 		exit(0);
		 
	}
	head->next=NULL;
	tail=head;
	printf("input the data\n");//���� 
	while(1)
	{
		
		scanf("%d",&score);
		
		pnew=(Node*)malloc(sizeof(Node));
		if(pnew==NULL)
		{
			printf("no enough memory");
	 		exit(0);
		 
		}
		pnew->data=score;
		pnew->next=NULL;
		tail->next=pnew;
		tail=pnew;
			if(getchar()=='\n')
		 break;
	}
	return (head);
		
		
	}
	void insert(Node *head,int i,Node *pnew)//���� 
	{
		int j;
		Node *ps;
		ps=head;
		for(j=0;j<i&&ps!=NULL;j++)
		ps=ps->next;
		if(ps==NULL)
		{
		
		printf("no this node");
		return;
	  }
		pnew->next=ps->next;
		ps->next=pnew;
		
		
		
	}
	   	  
	 
	 	
 
