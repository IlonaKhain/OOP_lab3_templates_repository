#pragma once

template <typename T>
class Iterator {
public:
	virtual T next() = 0;
	virtual bool hasNext() const = 0;
	//virtual Iterator<T>* clone() const = 0;
	virtual ~Iterator() {}
};