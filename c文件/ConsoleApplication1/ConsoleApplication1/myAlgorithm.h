#ifndef myAlgorithm_h
#define  myAlgorithm_h
template <typename T>
void swap(T *p1,T *p2)
{
	int t=*p1;
	*p1=*p2;
	*p2=t;
}
void radixSort(int a[],int n);

template <typename T>
void permutation(T a[],int k,int n)
{
	static int count=1;
	cout<<count<<": ";
	count++;
	for (int i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
	if(k==n) return;
	for (int i=k+1;i<n;i++)
	{
		swap(&a[i],&a[k]);
		permutation(a,k+1,n);
		swap(&a[i],&a[k]);
	}
}
#endif