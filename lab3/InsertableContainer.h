#pragma once
#include "IndexedContainer.h"
#include "Deque.h"

template <typename T>
class InsertableContainer : virtual public IndexedContainer <T>, virtual public Deque<T> {
public:
	virtual bool insertAt(int index, T const& value)=0;
	virtual T removeAt(int index)=0;
	virtual ~InsertableContainer() {};
};