#include<iostream>
#include<iomanip>
#include"sort.h"
#include<time.h>
using namespace std;
int main()
{
	
	int n=10;//参与排序数个数
	int mag=100;//放大倍数
	while (n<=100000)
	{
		/*double time[5];//用于存储五种排序时间
		for (int i=0;i<5;i++)
		{
			time[i]=0;
		}*/
		int k=0;
		double time1=0,time2=0;
	
		while(k++<1){
			
			int *p=getArray(n);//生成随机数组
		
			/*cout<<"原始数据："<<endl;*/
			quick_sort(p,n);
			//time[0]+=test(SelectSort,p,n,mag);//选择排序
			//time[1]+=test(bubble_sort,p,n,mag);//冒泡排序
			//time[2]+=test(merge_sort,p,n,mag);//归并排序
			//time[3]+=test(quick_sort,p,n,mag);//快速排序
			//time[4]+=test(insert_sort,p,n,mag);//插入排序
			time1+=test(quick_sort,p,n,mag);
			
			time2+=test(quick_sort_improve,p,n,mag);
		
			delete [] p;
		
		
		

		//for (int i=0;i<5;i++)//输出排序平均时间
		//{
		//	cout<<fixed<<setprecision(5)<<time[i]*1.0/20<<endl;
		//}
		
		}
		cout<<"规模为"<<n<<"时:\n";
		cout<<fixed<<setprecision(5)<<time1<<endl;
		cout<<fixed<<setprecision(5)<<time2<<endl;
		n*=10;
		if(n<10000) mag/=10;
		else mag=1;
		
	}
	
	
	
}