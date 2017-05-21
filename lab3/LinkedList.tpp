#include "stdafx.h"
#include "LinkedList.h"
#include<iostream>
using namespace std;


template<class T>
bool LinkedList<T>::push(T const& value) {
	 node<T> *temp = new node<T>;	
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
template<class T>
T LinkedList<T>::pop() {
	node<T> *temp;	
		if (top == NULL)
		{
			cout << "nThe list is empty!!!";
			return NULL;
		}
		if (top == tail)
		{
			return tail->data;		
			delete top;
			top = NULL;
			tail = NULL;	
		}
		node<T> *current = top;
		while (current->next != tail)
		{
			current = current->next;
		}
		int answer = tail->data;
		tail = current;
		tail->next = NULL;
		
		return answer;	
		delete current;
		
 }
template<class T>
T LinkedList<T>::peek() const {
	node<T> *temp;
	if (top == NULL)
	{
		cout << "nThe list is empty!!!";
		return NULL;
	}
	if (top == tail)
	{
		return tail->data;		
	}
	node<T> *current = top;
	while (current->next != tail)
	{
		current = current->next;
	}
	return tail->data;	
}
template<class T>
T& LinkedList<T>::peek()  {
	node<T> *temp;
	if (top == tail)
	{
		return tail->data;
	}
	node<T> *current = top;
	while (current->next != tail)
	{
		current = current->next;
	}
	return tail->data;
}
/*template<class T>
string LinkedList<T>::toString() const {
	string str = "  The list is ";
	struct node *ptr1 = top;
	while (ptr1 != NULL)
	{
		str += to_string(ptr1->data) + " -> ";
		ptr1 = ptr1->next;
	}
	return str;
}*/
template<class T>
bool LinkedList<T>::isEmpty() const {
	if (size() == 0)
	{
		return true;
	}
	else return false;
	}
template<class T>
int LinkedList<T>::size() const {
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
LinkedList<T>::  ~LinkedList() {
	node<T> *temp = top;
	node<T> *temp2;
	while (temp != NULL)
	{
	temp2=temp->next;
		delete temp;
		temp = temp2;
	}
	cout << "~linkedList()" << endl;
}
template<class T>
bool LinkedList<T> :: insertAt(int index, T const& value)
{
	int i;
	node<T> *temp = top;
	for (i = 1; i<index-1; i++)
	{
		temp = temp->next;
	}
	 node<T> *newnode = new node<T>();
	newnode->data = value;

	newnode->next = temp->next;
	
	temp->next = newnode;


	return true;
}
template<class T>
T LinkedList<T>::removeAt(int index) {
	node<T> *current = top;
	node<T> *prev=new node<T>;
	int count = 1;
	while (count != index)
	{
		prev = current;
		current = current->next;
		count++;
	}
	return current->data;
	if (current == top)
	{		
		top = top->next;
		
	}
	else if(current == tail)
	{		
		tail = prev;
		tail->next = 0;
	}
	else
	{
		prev->next = current->next;
	}
	//	cout << "nPOP Operation........nPoped value is " << 
	return current->data;
	delete current;
	//tail = current;
	//tail->next = NULL;
}
template<class T>
T LinkedList<T>::get(int index) const
{
	if (index<0 || index>size())
	{
		cout << "Index is out of range";
		return NULL;
	}
	node<T> *current = top;
	int count = 1;
	while (count != index)
	{		
		current = current->next;
		count++;
	}
	return current->data;
}
template <typename T>
T& LinkedList<T>::get(int index) 
{
	if (index<0 || index>size())
	{
		cout << "Index is out of range";
		//return error;
	}
	node<T> *current = top;
	if (index==0)
	{
		return current->data;
	}
	int count = 1;
	while (count != index)
	{
		current = current->next;
		count++;
	}
	return current->data;
}