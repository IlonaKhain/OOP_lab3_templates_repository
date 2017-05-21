#pragma once

#include "IndexedContainer.h"

template<typename T>
class ArrayIterator;
template<typename T>
class ArrayIteratorConst;

template <typename T>
class StaticArray : virtual public IndexedContainer<T> {	
	T* array = new T[10000];
	int Number;
public:
	friend class ArrayIterator<T>;
	friend class ArrayIteratorConst<T>;
	StaticArray(int number)
	{
		if (number < 10000)
		{
			array = new T[number]{};
		}
		else { cout<<"Number of elements is too big"; }
		
		Number = number;
		
	}
	T get(int index) const;
	T& get(int index);
	void set(int index, T const& value);
	//string toString() const; // to show the stack
	bool isEmpty() const;
	int size() const;
	StaticArray<T>& operator=(const StaticArray& sa);
	Iterator<T const&> *createIteratorConst() const { 
		return new ArrayIteratorConst<T>(*this);
	};
	Iterator<T &> *createIterator() { 
		return new ArrayIterator<T>(*this);
	};


	virtual ~StaticArray() {
		//delete[] array;
	};
};
template<typename T>
class ArrayIterator :public virtual Iterator<T&> {
private:
	StaticArray<T> &array;
	int index;
public:
	ArrayIterator(StaticArray<T> &_array) :array(_array), index(0) {}
	bool hasNext() const
	{
		return index != array.size();
	}
	T& next()
	{
		return array.get(index++);
	}
};
template<typename T>
class ArrayIteratorConst :public virtual Iterator<T const&> {
private:
	StaticArray<T>const &array;
	int index;
public:
	ArrayIteratorConst(StaticArray<T> const&_array) :array(_array), index(0) {}
	bool hasNext() const
	{
		return index != array.size();
	}
	T const& next()
	{
		return array.get(index++);
	}
};
#include "StaticArray.tpp"

