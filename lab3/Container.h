#pragma once
#include <sstream>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <memory>

#include "Iterator.h"
using namespace std;

template<typename T>
class Container {
public:
	virtual int size() const = 0;
	virtual bool isEmpty() const {
		if (size() == 0)
		{
			return true;
		}
		else return false;
	
	};
	friend class Iterator<T>;
	friend ostream& operator<<(ostream &os, Container<T> const & c) {
		os << c.toString();
		return os;
	}
	friend bool operator == (Container const& c1, Container const& c2)
	{
		auto it1 = unique_ptr<Iterator <T const&>>(c1.createIteratorConst());
		auto it2 = unique_ptr<Iterator <T const&>>(c2.createIteratorConst());
		if (c1.size() == c2.size()) {
			while (it1->hasNext() && it2->hasNext())
			{
				if (it1->next() == it2->next())
				{
					continue;
				}
				else { return false; }
			}

			return true;
		}
		else return false;
	}
	
	
	void selection_sort(Container<T> &c)
	{
		auto it1 =this->createIterator();	
		
		for (int i = 0; i < c.size() - 1; i++)
		{
			T& begin = it1->next();
			T& min = begin;
			auto it2 = this->createIterator();
			int k = 0;
			while (k != i) {
				it2->next();
				k++;
			}
			while (it2->hasNext()) {
				T& temp = it2->next();				
				if (min > temp)
				{
					swap(begin, temp);
				}
			}
			delete it2;
		}	
		delete it1;
	}
	virtual string toString() const {
		string s;
		ostringstream ostr;
		Iterator<const T&> *iterator = createIteratorConst();
		while (iterator->hasNext())
		{
			ostr << iterator->next() << ", ";
			s = ostr.str();
		}
		delete iterator;
		return s;
	}
	virtual Iterator<const T&>* createIteratorConst() const = 0;
	virtual Iterator<T&>* createIterator() = 0;
	virtual ~Container() {};
};