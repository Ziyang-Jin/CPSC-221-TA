// file:        arrayclass.cpp
// author:      Geoffrey Tien
// date:        2016-05-19
// description: Implementation file for an array wrapper class, CPSC 221 lab 4
//              To be completed by you!
//              *** This file will contain a deliberate error! ***

#ifdef _ARRAYCLASS_H_

// #include "arrayclass.h"
#include <stdexcept>

// paste code from lab 4 document below

// Default constructor
// POST: Creates an ArrayClass object with an array of size 10
// PARAM:
template <typename ItemType>
ArrayClass<ItemType>::ArrayClass()
{
	arr_size = 10;
	arr = new ItemType[arr_size];
	current_size = 0;
}

// Parameterized constructor
// PRE: array_size > 0
// POST: Creates an ArrayClass object with an array of size array_size
// PARAM: array_size = size of the array to be created
template <typename ItemType>
ArrayClass<ItemType>::ArrayClass(int array_size)
{
	arr_size = array_size;
	arr = new int[arr_size];
	current_size = 0;
}

// Destructor
// POST: De-allocates dynamic memory associated with object
template <typename ItemType>
ArrayClass<ItemType>::~ArrayClass()
{
	delete[] arr;
}

// Sets the value of the next free element
// PRE: current_size < arr_size
// POST: sets index current_size to value
// PARAM: value = value to be set
template <typename ItemType>
void ArrayClass<ItemType>::Insert(ItemType value)
{
	if (current_size < arr_size)
	{
		arr[current_size++] = value;
	}
	// NOTE – no else – should throw error
	else {
		throw std::exception ("array is full");
	}
}

// Sets an existing element’s value
// PRE: 0 <= i < current_size
// POST: sets index i to value
// PARAM: i = index of element to be changed
// value = value to be set
template <typename ItemType>
void ArrayClass<ItemType>::Set(int i, ItemType value)
{
	if (i >= 0 && i < current_size)
	{
		arr[i] = value;
	}
	// NOTE – no else – should throw error
	else {
		throw std::exception ("index is not in the range");
	}
}

// Returns an element’s value
// PRE: 0 <= i < current_size
// POST: returns the value at index i
// PARAM: i = index of value to be returned
template <typename ItemType>
ItemType ArrayClass<ItemType>::Get(int i) const
{
	if (i >= 0 && i < current_size)
	{
		return arr[i];
	}
	// Returns 0 if i invalid – THIS IS NOT SATISFACTORY!
	else
	{
		throw std::exception ("index is not in the range");
	}
}
// POST: Returns the size of the underlying array
template <typename ItemType>
int ArrayClass<ItemType>::MaxSize() const
{
	return arr_size;
}
// POST: Returns the number of elements stored in the array
template <typename ItemType>
int ArrayClass<ItemType>::Size() const
{
	return current_size;
}

#endif