#pragma once
#ifndef MYLIST
#define  MYLIST
#include <iostream>
template <class T>
struct  node
{
	node* next;
	T key;

};
template <class T>
class linkedList
{
 public:
	 
	node<T> * head;
	linkedList()
	{
		head = new node<T>;
		head->next = NULL;
	}
	
	bool empty()
	{
		if (!head->next) return true;
		else return true;
	}
	void insert(T key)
	{
		node<T>* tem = new node<T>;
		tem->key = key;
		tem->next = head->next;
		head->next = tem;
	}
	void show()
	{
		node<T>* p = head;
		while (p->next)
		{
			p = p->next;
			cout << p->key << " ";
			
		}
		cout << std::endl;
	}
	void reverse()
	{
		node<T> *p2 = head->next;
		node<T> *p3;
		head->next = NULL;
		while (p2)
		{
			p3 = p2->next;
			p2->next = head->next;
			head->next = p2;
			p2 = p3;
		}
		

	}

};
#endif