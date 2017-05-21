#include "stdafx.h"
#include "LinkedDeque.h"

template<typename T>
bool LinkedDeque<T>:: pushFront(T const& element)
{
	// Create a new node
	node<T>* tmp = new node<T>();
	tmp->data = element;
	tmp->next = NULL;
	tmp->prev = NULL;

	if (isEmpty()) {
		// Add the first element
		top = tail = tmp;
	}
	else {
		// Prepend to the list and fix links
		tmp->next = top;
		top->prev = tmp;
		top = tmp;
	}

	count++;
	return true;
}
template<typename T>
T LinkedDeque<T>::popFront()
{
	if (isEmpty()) {
		//throw new DequeEmptyException();
		cout << "Deque is empty";
		return NULL;
	}

	//  Data in the top node
	T ret = top->data;

	// Delete the top node and fix the links
	node<T>* tmp = top;
	if (top->next != NULL)
	{
		top = top->next;
		top->prev = NULL;
	}
	else
	{
		top = NULL;
	}
	count--;
	delete tmp;

	return ret;
}
template<typename T>
bool LinkedDeque<T>:: pushBack(T const& element)
{
	// Create a new node
	node<T>* tmp = new node<T>();
	tmp->data = element;
	tmp->next = NULL;
	tmp->prev = NULL;

	if (isEmpty()) {
		// Add the first element
		top = tail = tmp;
	}
	else {
		// Append to the list and fix links
		tail->next = tmp;
		tmp->prev = tail;
		tail = tmp;
	}

	count++;
	return true;
}
template<typename T>
T LinkedDeque<T>:: popBack()
{
	if (isEmpty()) {
		cout<<"deque is empty"<<endl;
		return NULL;
	}
	
		//  Data in the tail node
		T ret = tail->data;

		// Delete the top node and fix the links
		node<T>* tmp = tail;
		if (tail->prev != NULL)
		{
			tail = tail->prev;
			tail->next = NULL;
		}
		else
		{
			tail = NULL;
		}
		delete tmp;
		return ret;		
}
template<typename T>
T LinkedDeque<T>:: peekFront() const
{
	if (isEmpty())
		return NULL;

	return top->data;
}
template<typename T>
T LinkedDeque<T>:: peekBack() const
{
	if (isEmpty())
		return NULL;

	return tail->data;
}
template<typename T>
T& LinkedDeque<T>:: peekFront() 
{
	return top->data;
}
template<typename T>
T& LinkedDeque<T>:: peekBack() 
{
	return tail->data;
}
template<typename T>
int LinkedDeque<T> :: size() const
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
template<typename T>
bool LinkedDeque<T>:: isEmpty() const
{ 
	if (size() == 0) {
		return true;
	}
	else return false;
}
/*template<typename T>
string LinkedDeque<T> :: toString() const
{
	string str = "  The linked deque is ";
	struct node *ptr1 = top;

	while (ptr1 != NULL)
	{
		str += to_string(ptr1->data) + " -> ";
		ptr1 = ptr1->next;
	}
	return str;
}*/
template<typename T>
LinkedDeque<T>:: ~LinkedDeque() {
	node<T> *temp = top;
 node<T> *temp2;
	while (temp != NULL)
	{
		temp2 = temp->next;
		delete temp;
		temp = temp2;
	}
	cout << "~LinkedDeque()" << endl;
}
