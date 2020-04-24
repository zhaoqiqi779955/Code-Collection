#include<iostream>
using namespace std;
#include "SqQueue.h"
int main()
{
	SqQueue<int> sq(10);
	for (int i=0;i<10;i++)
	{
		sq.insert(i);
	}
	for (int i=0;i<10;i++)
	{
		cout<<sq.delQueue();
	}
	cout<<endl;
	cout<<sq.queueLength();
}