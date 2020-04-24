#include<iostream>
#include<string>
#include<map>
using namespace std;
int main()
{
	multimap<string,string> mp;
	typedef multimap<string,string> mutiM;
	mp.insert(make_pair(string("ÂíÍ¥¾ı"),"20"));
	mp.insert(make_pair("ÂíÍ¥¾ı","100"));
	typedef multimap<string,string>::iterator name;
	 pair<name,name> it=mp.equal_range("ÂíÍ¥¾ı");
	 while (it.first!=it.second)
	 {
		 cout<<it.first->second<<endl;
		 it.first++;
	 }

}



