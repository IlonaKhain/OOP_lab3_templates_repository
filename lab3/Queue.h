#pragma once
#include "PushPopContainer.h"


template<typename T>
class QueueIterator;
template<typename T>
class QueueIteratorConst;
template<typename T>
class Queue : virtual public PushPopContainer<T> {
	template<typename T>
	 struct node
	{
		T data;
		node *next;
	};
	node<T> *top;
	node<T> *tail;	
public:
	friend class QueueIterator<T>;
	friend class QueueIteratorConst<T>;

	typedef QueueIterator<T> iterator;
	typedef QueueIteratorConst<T> const_iterator;

	virtual bool push(T const& value);
    T pop();
	T peek() const;
	T& peek();
	//string toString() const; // to show the stack
	bool isEmpty() const;
	int size() const;
	Queue<T>& operator=(const Queue& q);
	Iterator<T&>* createIterator()
	{
		return new QueueIterator<T>(*this);
	}
	Iterator<const T&>* createIteratorConst() const
	{
		return new QueueIteratorConst<T>(*this);
	}
	virtual ~Queue();
};
template<typename T>
class QueueIterator: public virtual Iterator<T&> {
	typename Queue<T>::template node<T> *current;
public:
	/*friend class QueueIterator<T>;
	friend class QueueIteratorConst<T>;*/
	QueueIterator(Queue<T> &queue) :current(queue.top) {};
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
class QueueIteratorConst : public virtual Iterator<T const&> {
	typename Queue<T>::template node<T>const *current;
	//const *node<T>*current;
public:
	QueueIteratorConst(Queue<T>const& queue):current(queue.top) {}
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
#include "queue.tpp"