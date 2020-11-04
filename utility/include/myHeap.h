#ifndef HEAP_MINE
#define HEAP_MINE
#include"toolkit.h"
#include<iostream>
using std::cout;
using std::cin;
using std::endl;
template <class T>
class MaxHeap {	
protected:
	int size;
	T arr[1000];
public:
	
	MaxHeap(T a[],int size)
	{
		this->size = size;
		
		for (int i=0;i<size;i++)
		{
			arr[i] = a[i];
		}
	
	}
	
    void max_heapify(int i)//ά����������
	{
		int max_i=i;//������Ԫ���±�
		int left = 2 * i+1;
		int right = 2 * i + 2;
		if (left <size && arr[max_i] < arr[left]) {
			max_i = left;
		}
		if (right <size && arr[max_i] < arr[right]) {
			max_i = right;
		}
		if(max_i == i) return;
		else {
			exchange(arr[i], arr[max_i]);
				max_heapify(max_i);
		}

	}
	 void build_max_heap()//��������
	{
		for(int i=(size-1)/2;i>=0;i--)
		{
			max_heapify(i);
		}
	}
	 void heap_sort()//������
	{
		build_max_heap();
		int s = size;
		while(size>1)
		{
			exchange(arr[0], arr[size-1]);
			size--;
			max_heapify(0);
		}
		size = s;
		

	}
	 void show()
	 {
		 for (int i=0;i<size;i++)
		 {
			 cout << arr[i] << " ";
		 }
		 cout << endl;
	 }
	

};

template <typename T>
class PriorityQueue :public MaxHeap<T>
{
	//arr[0:size-1]
public:
	PriorityQueue(T a[], int size) : MaxHeap<T>(a, size) {

		//build_max_heap();
	}
	void max_heap_insert(T x)
	{
		this->size++;
		this->arr[this->size - 1] = x;
		int i = this->size - 1;
		int p = parent(i);
		while (i > 0 && this->arr[p] < this->arr[i])
		{
			exchange(this->arr[i], this->arr[p]);
			i = p;
			p = parent(i);
		}

	}
	int parent(int i) { return (i - 1) / 2; }

	T heap_extract_max()
	{
		if (this->size < 1) {
			cout << "heap underflow" << endl;
		}
		this->size--;
		exchange(this->arr[0], this->arr[this->size]);
		this->max_heapify(0);
		return this->arr[this->size];
	}
	void heap_increase_key(int i, T key) {
		if (key < this->arr[i]) {
			cout << "key is smaller than arr[i]" << endl;
			return;
		}
		int p = parent(i);
		while (i > 0 && this->arr[p] < this->arr[i])
		{
			exchange(this->arr[i], this->arr[p]);
			i = p;
			p = parent(i);
		}

	}
};

#endif 

