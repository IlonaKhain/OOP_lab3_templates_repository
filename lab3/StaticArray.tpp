

#include "stdafx.h"
#include "staticarray.h"

#include<iostream>
using namespace std;

template<typename T>
T StaticArray<T>::get(int index) const {
	if (index >= size() || index < 0)
	{
		cout << "element with such index doesn't exist";
		return NULL;
	}
	else
	{
		return array[index];
	}	
}

template<typename T>
T& StaticArray<T>::get(int index)  {
	return array[index];
}
template<class T>
void StaticArray<T>::set(int index, T const& value) {
	
	if (index >= size() || index < 0)
	{
		cout << "element with such index doesn't exist";
		//return NULL;
	}
	array[index] = value;
	//return true;	
}
template<class T>
int StaticArray<T>::size() const
{
	return Number;
}

template<class T>
bool StaticArray<T>::isEmpty() const {
	if (size() == 0) {
		return true;
	}
	else return false;
}
