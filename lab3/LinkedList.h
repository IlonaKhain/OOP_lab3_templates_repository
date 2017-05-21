#pragma once
#include "PushPopContainer.h"
#include "InsertableContainer.h"
#include "Stack.h"


template<typename T>
class ListIterator;
template<typename T>
class ListIteratorConst;
template<typename T>
class LinkedList : virtual public PushPopContainer <T>, virtual public InsertableContainer<T> {
	template<typename T>
	struct node 
	{
		T data;
		node *next;
	};
    node<T> *top;
    node<T> *tail;
public:
	LinkedList<T>() {
		top = NULL;
		tail = NULL;
	};
	friend class ListIterator<T>;
	friend class ListIteratorConst<T>;

	 bool push(T const& value);
	 bool pushFront(T const& value) { return false; };
	 bool pushBack(T const& value) { return nullptr; };
	T pop();
	T popBack() { return pop(); };
	T popFront() { return NULL; };
	T peek() const;
	T& peek();
	T peekBack() const { return peek(); };
	T peekFront() const { return NULL; };
	T& peekFront() { return peek(); };
	T& peekBack() { return peek(); };
	T get(int index) const ;
	T& get(int index);
	void set(int index, T const& value) {  };
	T removeAt(int index);
	//string toString() const; // to show the stack
	bool isEmpty() const;
	int size() const;
	bool insertAt(int index, T const& value);
	LinkedList<T>& operator=(const LinkedList& ll);
	Iterator<T&>* createIterator()
	{
		return new ListIterator<T>(*this);
	}
	Iterator<const T&>* createIteratorConst() const
	{
		return new ListIteratorConst<T>(*this);
	}
	virtual ~LinkedList();
};
template<typename T>
class ListIterator : public virtual Iterator<T&> {
	typename LinkedList<T>::template node<T> *current;
public:
	ListIterator(LinkedList<T> &list) :current(list.top) {};
	T& next()
	{
		T& data = current->data;
		current = current->next;
		return data;
	}
	bool hasNext() const {
		return current != nullptr;
	}
};
template<typename T>
class ListIteratorConst : public virtual Iterator<T const&> {
	typename LinkedList<T>::template node<T>const *current;
	//const *node<T>*current;
public:
	ListIteratorConst(LinkedList<T>const& list):current(list.top) {}
	T const& next()
	{
		T const& data = current->data;
		current = current->next;
		return data;
	}
	bool hasNext() const {
		return current != nullptr;
	}
};
#include "linkedlist.tpp"
