#include<sort.h>
void SelectSort(int a[],int n)//a�ǲ����������飬n�Ǹ���
{
	for (int i=0;i<n-1;i++)
	{
		int k=i;//k��¼����������Сֵ�±�
		for (int j=i+1;j<n;j++)
		{
			if(a[j]<a[k]) k=j;
			
		}
		//����
		int t=a[i];
		a[i]=a[k];
		a[k]=t;
	}
	

}
