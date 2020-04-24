/*#include <iostream>
using namespace std;

class hashTable
{
	int *hash_base;
	int sizeindex;
public:

	hashTable(int size,int a[],int n)
	{
		sizeindex=size;
		hash_base=new int [sizeindex];
		for (int i=0;i<sizeindex;i++)
		{
			hash_base[i]=-1;
		}

		for(int i=0;i<n;i++)       
		{
			int value=a[i];
			int key=value%11;
			for (int s=0;1;s++)
			{
				
				int j=key+s*s;
				if (j>=sizeindex)
				{
					j-=sizeindex;
				}
				if(hash_base[j%sizeindex]==-1)
				{
					hash_base[j%sizeindex]=value;
					break;
				}
				j=key-s*s;
				if(j<0) j+=sizeindex;
				if(hash_base[j%sizeindex]==-1)
				{
					hash_base[j%sizeindex]=value;
					break;
				}
			}
		}


		for(int i=0;i<sizeindex;i++)
		{
			if(hash_base[i] == -1)
				cout<<"NULL";
			else
				cout<<hash_base[i];
			if(i != sizeindex-1)
				cout<<' ';
		}
		cout<<endl;

	}
	void search(int a[],int k)
	{
		int times;
		for(int i=0;i<k;i++)
		{
			times=0;
			int value=a[i];
			int key=value%11;
			int flag=0;
			if (hash_base[key]==value)
			{
				 cout<<1<<' '<<1<<' '<<key+1<<endl;
				 continue;
			}
			times++;
			for(int s=1;true;s++)        //hash²éÕÒ
			{
				times++;
				int j=key+s*s;
				if(j>=sizeindex) j-=sizeindex;
				if(hash_base[j%sizeindex] == value)
				{
					flag=1;
					   cout<<1<<' '<<times<<' '<<(j%sizeindex)+1<<endl;
					break;
				}
				else if(hash_base[j%sizeindex]==-1)
				{
					
					break;
				}
				times++;
				j=key-s*s;
				if (j<0)
				{
					j+=sizeindex;
				}
				if(hash_base[j%sizeindex] == value)
				{
					flag=1;
					cout<<1<<' '<<times<<' '<<(j%sizeindex)+1<<endl;
					break;
				}
				else if(hash_base[j%sizeindex]==-1)
				{

					break;
				}

			}
			if(flag==0)
				cout<<0<<' '<<times<<endl;
		}
	}
};

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int m,n;
		cin>>m>>n;
		int a[1000];
		for (int i=0;i<n;i++)
		{
			cin>>a[i];
		}
		hashTable hash(m,a,n);
		int k;
		cin>>k;
		for (int i=0;i<k;i++)
		{
			cin>>a[i];
		}
		hash.search(a,k);
	}

	return 0;
} */