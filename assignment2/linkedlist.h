// File:        linkedlist.h
// Author:      Geoffrey Tien
// Date:        2016-05-24
// Description: Declaration of a doubly-linked list template class for CPSC 221 assignment #2
//              This file should not be modified

#ifndef _LINKEDLIST_H_
#define _LINKEDLIST_H_

#include <cstdlib>
#include <stdexcept>
#include <string>

// Node template class used in LinkedList
template <typename T>
class Node
{
public:
  T data;
  Node<T>* prev;
  Node<T>* next;

  // default constructor
  Node(T value)
  {
    data = value;
    prev = NULL;
    next = NULL;
  }
};

// LinkedList class definition
template <typename T>
class LinkedList
{
private:
  // LinkedList private members
  int size; // number of items stored in list
  Node<T>* front; // references to the front
  Node<T>* back;  //  and back of the list

                  // helper function for deep copy
                  // Used by copy constructor and operator=
  void CopyList(const LinkedList& ll);

  // helper function for deep delete
  // Used by destructor and copy/assignment
  void DeleteList();

  #include "linkedlistprivate.h" // declare your private helper functions this file

public:
  // default constructor
  LinkedList();

  // copy constructor, performs deep copy of list elements
  LinkedList(const LinkedList& ll);

  // destructor
  ~LinkedList();

  // MUTATORS

  // Inserts an item at the front of the list
  // POST:  List contains item at position 0
  // PARAM: item = item to be inserted
  void InsertFront(T item);

  // Inserts an item at the back of the list
  // POST:  List contains item at back
  // PARAM: item = item to be inserted
  void InsertBack(T item);

  // Inserts an item in position p (0-indexed)
  // Throws exception for invalid index
  // PRE:   0 <= p <= size
  // POST:  List contains item at position p
  // PARAM: item = item to be inserted, p = position where item will be inserted
  void InsertAt(T item, int p);

  // Removes and returns an item from position p (0-indexed)
  // Throws exception if list is empty or index invalid
  // PRE:   0 <= p < size
  // POST:  Item is removed from list
  // PARAM: p = position from where item will be removed
  T RemoveAt(int p);

  // Appends the contents of the parameter list to the back of this list as a deep copy
  // PRE:
  // POST: List contains every element of ll appended to back, size is updated appropriately
  void Append(const LinkedList& ll);

  // Removes duplicates from the list, preserving existing order of remaining items.
  // The LAST occurrence of any duplicate (relative to the front of the list)
  //   is the one which remains.
  // Efficiency will not be a priority as long as the behaviour above is satisfied.
  // PRE:   
  // POST:  List contains no duplicates, front and back point to the appropriate nodes
  // PARAM: 
  void RemoveDuplicates();

  // ACCESSORS

  // Returns size of list
  int Size() const;

  // Returns whether the list is empty
  bool IsEmpty() const;

  // Returns existence of item
  bool Contains(T item) const;

  // Returns item at index (0-indexed)
  // Throws exception for invalid index
  T ElementAt(int p) const;

  // OVERLOADED OPERATORS

  // overloaded assignment operator
  // must work in the following cases:
  // list2 = list1 -> general case
  // list2 = list2 -> should do nothing
  LinkedList& operator=(const LinkedList& ll);
};

#include "linkedlist.cpp"

#endif