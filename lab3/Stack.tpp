#include "stdafx.h"
#include "Container.h"
#include "Stack.h"

#include<iostream>
using namespace std;

template<typename T>
bool Stack<T>::push( T const& value)
{
	 node<T> *ptr= new node<T>;	
	ptr->data = value;
	ptr->next = NULL;
	if (top != NULL)
		ptr->next = top;
	top = ptr;
	return true;
	//cout << "nNew item is inserted to the stack!!!";
}

// POP Operation
template<class T>
T Stack<T>::pop()
{
	struct node<T> *temp;
	if (top == NULL)
	{
		cout << "nThe stack is empty!!!";
		//exit(1);
		return NULL;
	}
	temp = top;
	top = top->next;
	//cout << "nPOP Operation........nPoped value is " << temp->data<<endl;	
	return temp->data;
	delete temp;
}
template<typename T>
T Stack<T>::peek() const
{
	if (top == NULL)
	{
		cout << "nThe stack is empty!!!";
		exit(1);
	}
	return top->data;

}
template<typename T>
T& Stack<T>::peek()
{
	if (top == NULL)
	{
		cout << "nThe stack is empty!!!";
		exit(1);
	}
	return top->data;
}
// Show stack
/*template<class T>
string Stack<T>::toString() const
{
	string str = "  The stack is ";
	struct node *ptr1 = top;
	
	while (ptr1 != NULL)
	{
		str += to_string(ptr1->data) + " -> ";
		ptr1 = ptr1->next;
	}
	return str;
}*/
template<class T>
int Stack<T>::size() const
{
	int count = 0;
	 node<T> *temp = top;	
	count++;
	while (temp != NULL)
	{
		count++;
		temp = temp->next;
	}
	return count-1;
}
template<class T>
bool Stack<T>::isEmpty() const {
	if (size() == 0) {
		return true;
	}
	else return false;
		
}
template<typename T>
Stack<T>::~Stack()
{
	node<T> *temp = top;
	 node<T> *temp2;
	while (temp != NULL)
	{
		temp2 = temp->next;
		delete temp;
		temp = temp2;
	}
	cout << "~Stack()" << endl;
}

