//#include<iostream>
//using namespace std;
//void HeapAdjust(int a[],int s,int m)
//{
//	int rc=a[s];
//	for (int j=2*s;j<=m;j*=2)
//	{
//		if(j<m&&a[j]<a[j+1]) j++;
//		if(rc>a[j]) break;
//		a[s]=a[j];s=j;
//	}
//	a[s]=rc;
//}
//void heapSort(int a[],int n)//nÎª³¤¶È
//{
//	int i;
//	int tem;
//	for (i=n/2;i>0;i--)
//	{
//		HeapAdjust(a,i,n);
//	}
//	for (int i=n;i>1;i--)
//	{
//		tem=a[i];
//		a[i]=a[1];
//		a[1]=tem;
//		HeapAdjust(a,1,i-1);
//	}
//}
//int main()
//{
//
//	int a[100];
//	int n;
//	cin>>n;
//	for (int i=1;i<=n;i++)
//	{
//		cin>>a[i];
//	}
//	heapSort(a,n);
//	for (int i=1;i<=n;i++)
//	{
//		cout<<a[i]<<" ";
//	}
//}