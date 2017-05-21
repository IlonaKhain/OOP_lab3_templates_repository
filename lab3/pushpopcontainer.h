#pragma once
#include "Container.h"


template <typename T>
class PushPopContainer : virtual public Container<T> {
public:
	virtual bool push(T const& value)=0;
	virtual T pop()=0;
	virtual T peek() const=0;
	virtual T& peek()=0;
	virtual ~PushPopContainer() {};
};