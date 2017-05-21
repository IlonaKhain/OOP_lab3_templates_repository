#include "stdafx.h"
#include "Queue.h"

#include<iostream>
using namespace std;

template<typename T>
T Queue<T>::pop()
{
	struct node<T> *temp;

	if (top == NULL)
	{
		cout << "The queue is empty!!!";
		//exit(1);
		return NULL;
	}
	
	temp = top;
	top = top->next;
	//cout << "POP Operation........Poped value is " << temp->data;
	return temp->data;
	delete temp;
	
}
template<class T>
T Queue<T>::peek() const
{
	if (top == NULL)
	{
		cout << "The queue is empty!!!";
		//exit(1);
		return NULL;
	}
	return top->data;
}
template <typename T>
T& Queue<T>::peek() 
{
	return top->data;
}
template<class T>	
bool Queue<T>::push(T const& value)
{
	struct node<T> *temp = new node<T>;
	//cout << "nPUSH Operationn";
	//cout << "Enter a number to insert: ";
	//cin >> value;
	temp->data = value;
	temp->next = NULL;	
		if (top == NULL) {
			top = temp;		
		}
		else {
			tail->next = temp;		
		}
		tail = temp;
		return true;
	}
/*template<class T>
string Queue<T>::toString() const
{
	string str = "  The queue is ";
	node<T> *ptr1 = top;

	while (ptr1 != NULL)
	{
		str += to_string(ptr1->data) + " -> ";
		ptr1 = ptr1->next;
	}
	return str;
}*/
template<class T>
int Queue<T>::size() const
{
	int count = 0;
	 node<T> *temp = top;
	count++;
	while (temp != NULL)
	{
		count++;
		temp = temp->next;
	}
	return count - 1;
}
template<class T>
bool Queue<T>::isEmpty() const {
	if (size() == 0) {
		return true;
	}
	else return false;

}
template<class T>
Queue<T>:: ~Queue() {
	node<T> *temp = top;
	node<T> *temp2;
	while (temp != NULL)
	{
		temp2 = temp->next;
		delete temp;
		temp = temp2;
	}
	
	cout << "~queue()" << endl;
}


