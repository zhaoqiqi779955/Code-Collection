#include<iostream>
using namespace std;
class Tr
{
	int x;
	public:
		Tr(int b=10)
		{
			x=b;
			cout<<"constructing"<<endl;
		}
	~Tr()
	{
		cout<<"destructing"<<endl;
	}
	
};
int main()
{
	int x;
	cin>>x;
	Tr *p=new Tr [5];
	delete [] p;
}
