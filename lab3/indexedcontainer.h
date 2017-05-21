#pragma once

#include "Container.h"

template <typename T>
class IndexedContainer : virtual public Container<T> {
public:
	virtual T get(int index) const=0;
	virtual T& get(int index)=0;
	virtual void set(int index, T const& value)=0;
	T& operator[](int index)
	{
		return this->get(index);
	}
	virtual ~IndexedContainer() {};
};