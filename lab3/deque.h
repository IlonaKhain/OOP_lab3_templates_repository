#pragma once
#include "Container.h"

template<typename T>
class Deque : virtual public Container<T> {
public:
	virtual bool pushFront(T const& value)=0;
	virtual bool pushBack(T const& value)=0;
	virtual T popFront()=0;
	virtual T popBack()=0;
	virtual T peekFront() const=0;
	virtual T peekBack() const=0;
	virtual T& peekFront()=0;
	virtual T& peekBack()=0;
	virtual ~Deque() {};
};