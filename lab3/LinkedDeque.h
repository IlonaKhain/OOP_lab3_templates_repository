#pragma once
#include "Deque.h"


template<typename T>
class DequeIterator;
template<typename T>
class DequeIteratorConst;

template<typename T>
class LinkedDeque : virtual public Deque<T> {
	template<typename T>
	struct node
	{
		T data;
		node *next;
		node *prev;
	};
    node<T> *top;
	node<T> *tail;
	int count;
public:
	friend class DequeIterator<T>;
	friend class DequeIteratorConst<T>;
	LinkedDeque ()// constructor
	{
		top = NULL;
		tail = NULL;
		count = 0;
	}
 bool pushFront(T const& value);
 bool pushBack(T const& value);
 T popFront();
 T popBack();
 T peekFront() const;
 T peekBack() const;
 T& peekFront();
 T& peekBack();
	//string toString() const; 
	bool isEmpty() const;
	int size() const;
	LinkedDeque<T>& operator=(const LinkedDeque& ld);
	Iterator<T&>* createIterator()
	{
		return new DequeIterator<T>(*this);
	}
	Iterator<const T&>* createIteratorConst() const
	{
		return new DequeIteratorConst<T>(*this);
	}
	~LinkedDeque();
};
template<typename T>
class DequeIterator :public virtual Iterator<T&> {
	typename LinkedDeque<T>::template node<T> *current;
public:
	DequeIterator(LinkedDeque<T> &deque) :current(deque.top) {}
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
class DequeIteratorConst : public virtual Iterator<T const&> {
	typename LinkedDeque<T>::template node<T>const *current;
	
	//const *node<T>*current;
public:
	DequeIteratorConst( LinkedDeque<T>const& deque) :current(deque.top) {}
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
#include "LinkedDeque.tpp"