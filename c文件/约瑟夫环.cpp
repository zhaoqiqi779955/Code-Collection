#include<iostream>
using namespace std;
struct Node
{
	int loc;
	Node *next;
 };
 int main()
 {
 	int n,interval;
 	cin>>n>>interval;
 	Node *p= new Node [n];
 	for(int i=0;i<n;i++)
 	{ 
 	 p[i].loc=i+1;
 	 p[i].next=p+(i+1)%n;
    }
    Node *p1=p;
    int i=0;
    int k=0;
    while(p1!=p1->next)
    {
    	
       	p1=p1->next;
    	i++;
    	k++;
    	if(i==interval-1) {
    		cout<<p1->next->loc<<" ";
    		p1->next=p1->next->next;
    		i=0;
		}
	  // if(k==40) break;
	}
	cout<<p1->loc<<endl;
 	
 }
 
