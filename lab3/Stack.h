#pragma once
#include "PushPopContainer.h"
#include "Iterator.h"

template<typename T>
class StackIterator;
template<typename T>
class StackIteratorConst;

template<typename T>
class Stack : virtual public PushPopContainer<T> {
	template<typename U>
	struct node
	{
		U data;
		node* next;
	};
	node<T> *top;
		
	public:
		friend class StackIterator<T>;
		friend class StackIteratorConst<T>;
		Stack<T>() // constructure
		{
			top = NULL;
		}
		 bool push( T const& value); // to insert an element
		 T pop();  // to delete an element
		 T peek() const; //recognize element
		// string toString() const; // to show the stack
		 T& peek();
		 bool isEmpty() const;
		 int size() const;
		 Stack<T>& operator=(const Stack& st);
		 Iterator<T&>* createIterator()
		 {
			 return new StackIterator<T>(*this);
		 }
		 Iterator<const T&>* createIteratorConst() const
		 {
			 return new StackIteratorConst<T>(*this);
		 }
		 ~Stack();
	};

template<typename T>     
class StackIterator:public virtual Iterator<T&> {
private:
	typename Stack<T>::template node<T> *current;
public: 
	StackIterator(Stack<T> &stack) :current(stack.top) {}
	T& next()
	{
		T& data = current->data;
		current = current->next;
		return data;
	}
	bool hasNext() const {
		return current!= nullptr;
	}
};

template<typename T>
class StackIteratorConst : public virtual Iterator<T const&> {
	typename Stack<T>::template node<T>const *current;
	//const *node<T>*current;
public:
	StackIteratorConst(Stack<T>const & stack):current(stack.top) {}
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
#include "stack.tpp"
