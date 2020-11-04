#include<iostream>
#include "myHeap.h"
#include "myList.h"
#include "sort.h"
#include "toolkit.h"
#include "include/add.h"
using  std::cout;
using std::cin;
using std::endl;
int main()
{
	linkedList<double> li;
	li.insert(15.0);
	li.insert(354.4);
	li.insert(94.12);
	li.show();
	li.reverse();
	li.show();
}