#include<iostream>
#include<iomanip>
#include"sort.h"
#include<time.h>
using namespace std;
int main()
{
	
	int n=10;//��������������
	int mag=100;//�Ŵ���
	while (n<=100000)
	{
		/*double time[5];//���ڴ洢��������ʱ��
		for (int i=0;i<5;i++)
		{
			time[i]=0;
		}*/
		int k=0;
		double time1=0,time2=0;
	
		while(k++<1){
			
			int *p=getArray(n);//�����������
		
			/*cout<<"ԭʼ���ݣ�"<<endl;*/
			quick_sort(p,n);
			//time[0]+=test(SelectSort,p,n,mag);//ѡ������
			//time[1]+=test(bubble_sort,p,n,mag);//ð������
			//time[2]+=test(merge_sort,p,n,mag);//�鲢����
			//time[3]+=test(quick_sort,p,n,mag);//��������
			//time[4]+=test(insert_sort,p,n,mag);//��������
			time1+=test(quick_sort,p,n,mag);
			
			time2+=test(quick_sort_improve,p,n,mag);
		
			delete [] p;
		
		
		

		//for (int i=0;i<5;i++)//�������ƽ��ʱ��
		//{
		//	cout<<fixed<<setprecision(5)<<time[i]*1.0/20<<endl;
		//}
		
		}
		cout<<"��ģΪ"<<n<<"ʱ:\n";
		cout<<fixed<<setprecision(5)<<time1<<endl;
		cout<<fixed<<setprecision(5)<<time2<<endl;
		n*=10;
		if(n<10000) mag/=10;
		else mag=1;
		
	}
	
	
	
}