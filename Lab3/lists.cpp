#include <iostream>
#include <string> 
#include <vector> 
#include <sstream> 
#include "Unit.h" 
#include "linked_list.cpp" 

using namespace std;

// DO NOT CHANGE THIS FILE 

int main() {
  Unit unit; 

  Node * list1 = NULL;
  Node * list2 = NULL;
  Node * list3 = NULL;
  Node * list4 = NULL;

  insert( list1, 1);
  insert( list1, 2);
  insert( list1, 3);

  cout << "<A> List 1: ";
  print( list1 );
  
  int size1 = size(list1); 
  unit.assertEquals("<A> list1 size", 3, size1 ); 
  vector<int>* vector1 = to_vector(list1); 
  if (size1 > 0) unit.assertEquals("<A> list1->key", list1->key, vector1->at(0) ); 
  if (size1 > 1) unit.assertEquals("<A> list1->next->key", list1->next->key, vector1->at(1) ); 
  if (size1 > 2) unit.assertEquals("<A> list1->next->next->key", list1->next->next->key, vector1->at(2) ); 
  if (size1 > 2) unit.assertNull("<A> list1->next->next->next", list1->next->next->next ); 

  insert( list2, 10);
  insert( list2, 9);
  insert( list2, 8);
  insert( list2, 7);
  insert( list2, 6);

  cout << "<B> List 2: ";
  print( list2 );
  int size2 = size(list2); 
  unit.assertEquals("<B> list2 size", 5, size2 ); 
  vector<int>* vector2 = to_vector(list2); 
  int list2_B[] = {6, 7, 8, 9, 10}; 
  for (int ii=0; ii<size2; ++ii){ 
    stringstream msg; 
    msg << "<B> list2 Node[" << ii << "]"; 
    unit.assertEquals(msg.str(), list2_B[ii], vector2->at(ii) ); 
  }

  delete_last_element( list1 );
  cout << "<C> List 1: ";
  print( list1 );
  size1 = size(list1); 
  unit.assertEquals("<C> list1 size", 2, size1 ); 
  if (size1 > 0) unit.assertEquals("<C> list1->key", list1->key, vector1->at(0) ); 
  if (size1 > 1) unit.assertEquals("<C> list1->next->key", list1->next->key, vector1->at(1) ); 
  if (size1 > 1) unit.assertNull("<C> list1->next->next", list1->next->next ); 
  
  delete_last_element( list1 );
  cout << "<D> List 1: ";
  print( list1 );
  size1 = size(list1); 
  unit.assertEquals("<D> list1 size", 1, size1 ); 
  if (size1 > 0) unit.assertEquals("<D> list1->key", list1->key, vector1->at(0) ); 
  if (size1 > 0) unit.assertNull("<D> list1->next", list1->next ); 

  delete_last_element( list1 );
  cout << "<E> List 1: ";  // list1 is now empty 
  print( list1 );
  size1 = size(list1); 
  unit.assertEquals("<E> list1 size", 0, size1 ); 
  unit.assertNull("<E> list1", list1 ); 
  delete_last_element( list1 ); // try to delete from empty list 
  size1 = size(list1); 
  unit.assertEquals("<E> list1 size", 0, size1 ); 
  unit.assertNull("<E> list1", list1 ); 
  
  insert( list1, 15 ); 
  insert( list1, 10 ); 
  insert( list1,  5 ); 
  size1 = size(list1); 
  unit.assertEquals("<F> list1 size", 3, size1 ); 
  if (size1 > 0) unit.assertEquals("<F> list1->key", 5, list1->key ); 
  if (size1 > 0) unit.assertNonNull("<F> list1->next", list1->next ); 
  if (size1 > 1) unit.assertEquals("<F> list1->next->key", 10, list1->next->key ); 
  if (size1 > 1) unit.assertNonNull("<F> list1->next->next", list1->next->next ); 
  if (size1 > 2) unit.assertEquals("<F> list1->next->next->key", 15, list1->next->next->key ); 
  if (size1 > 2) unit.assertNull("<F> list1->next->next->next", list1->next->next->next ); 
  remove( list1, 10 ); 
  size1 = size(list1); 
  unit.assertEquals("<F> list1 size after remove 10", 2, size1 ); 
  if (size1 > 0) unit.assertEquals("<F> list1->key", 5, list1->key ); 
  if (size1 > 0) unit.assertNonNull("<F> list1->next", list1->next ); 
  if (size1 > 1) unit.assertEquals("<F> list1->next->key", 15, list1->next->key ); 
  if (size1 > 1) unit.assertNull("<F> list1->next->next", list1->next->next ); 
  remove( list1, 15 ); 
  size1 = size(list1); 
  unit.assertEquals("<F> list1 size after remove 15", 1, size1 ); 
  if (size1 > 0) unit.assertEquals("<F> list1->key", 5, list1->key ); 
  if (size1 > 0) unit.assertNull("<F> list1->next", list1->next ); 
  remove( list1, 5 ); 
  size1 = size(list1); 
  unit.assertEquals("<F> list1 size after remove 5", 0, size1 ); 
  unit.assertNull("<F> list1", list1 ); 
  cout << "<F> List 1: ";  // list1 is now empty again  
  print( list1 );

  insert(list1, 11);			// list1 = [11]
  insert_after(list1, 11, 12);	// list1 = [11.12]
  cout << "<G> List 1: ";
  print( list1 );
  size1 = size(list1); 
  unit.assertEquals("<G> list1 size", 2, size1 ); 
  if (size1 > 0) unit.assertEquals("<G> list1->key", 11, list1->key ); 
  if (size1 > 0) unit.assertNonNull("<G> list1->next", list1->next ); 
  if (size1 > 1) unit.assertEquals("<G> list1->next->key", 12, list1->next->key ); 
  if (size1 > 1) unit.assertNull("<G> list1->next->next", list1->next->next ); 

  insert_after(list1, 13, 14);
  cout << "<H> List 1: ";
  print( list1 );
  size1 = size(list1); 
  unit.assertEquals("<H> list1 size", 2, size1 ); 
  if (size1 > 0) unit.assertEquals("<H> list1->key", 11, list1->key ); 
  if (size1 > 0) unit.assertNonNull("<H> list1->next", list1->next ); 
  if (size1 > 1) unit.assertEquals("<H> list1->next->key", 12, list1->next->key ); 
  if (size1 > 1) unit.assertNull("<H> list1->next->next", list1->next->next ); 

  insert_after(list1, 11, 12);	// list1 = [11,12,12]
  cout << "<I> List 1: ";
  print( list1 );
  size1 = size(list1); 
  unit.assertEquals("<I> list1 size", 3, size1 ); 
  if (size1 > 0) unit.assertEquals("<I> list1->key", 11, list1->key ); 
  if (size1 > 0) unit.assertNonNull("<I> list1->next", list1->next ); 
  if (size1 > 1) unit.assertEquals("<I> list1->next->key", 12, list1->next->key ); 
  if (size1 > 1) unit.assertNonNull("<I> list1->next->next", list1->next->next ); 
  if (size1 > 2) unit.assertEquals("<I> list1->next->next->key", 12, list1->next->next->key ); 
  if (size1 > 2) unit.assertNull("<I> list1->next->next->next", list1->next->next->next ); 

  delete_last_element( list1 );	// list1 = [11,12]
  cout << "<J> List 1: ";
  print( list1 );
  size1 = size(list1); 
  unit.assertEquals("<J> list1 size", 2, size1 ); 
  if (size1 > 0) unit.assertEquals("<J> list1->key", 11, list1->key ); 
  if (size1 > 0) unit.assertNonNull("<J> list1->next", list1->next ); 
  if (size1 > 1) unit.assertEquals("<J> list1->next->key", 12, list1->next->key ); 
  if (size1 > 1) unit.assertNull("<J> list1->next->next", list1->next->next ); 

  list4 = interleave(list1, list2);
  cout << "<K> List 4: ";
  print( list4 );
  size1 = size(list1); 
  size2 = size(list2); 
  int size4 = size(list4); 
  unit.assertEquals("<K> list4 size", size1 + size2, size4 ); 
  vector<int>* vector4 = to_vector( list4 ); 
  int list4_K[] = {11, 6, 12, 7, 8, 9, 10}; 
  for (int ii=0; ii<size4; ++ii){ 
    stringstream msg; 
    msg << "<K> list4 Node[" << ii << "]"; 
    unit.assertEquals(msg.str(), list4_K[ii], vector4->at(ii) ); 
  }
  delete_last_element(list4);
  unit.assertEquals("<K> list1 size", size1, size(list1) );
  unit.assertEquals("<K> list2 size", size2, size(list2) );


  list4 = interleave(list2, list2);
  cout << "<L> List 4: ";
  print( list4 );
  size2 = size(list2); 
  size4 = size(list4); 
  unit.assertEquals("<L> list4 size", size2 + size2, size4 ); 
  delete vector4;
  vector4 = to_vector( list4 ); 
  int list4_L[] = {6, 6, 7, 7, 8, 8, 9, 9, 10, 10};
  for (int ii=0; ii<size4; ++ii){ 
    stringstream msg; 
    msg << "<L> list4 Node[" << ii << "]"; 
    unit.assertEquals(msg.str(), list4_L[ii], vector4->at(ii) ); 
  }

  list4 = interleave(list1, list3); // list3==NULL
  cout << "<M> List 4: ";
  print( list4 );
  size1 = size(list1); 
  size4 = size(list4); 
  unit.assertEquals("<M> list4 size", size1, size4 ); 
  delete vector1;
  vector1 = to_vector( list1 ); 
  delete vector4;
  vector4 = to_vector( list4 ); 
  for (int ii=0; ii<size4; ++ii){ 
    stringstream msg; 
    msg << "<M> list4 Node[" << ii << "]"; 
    unit.assertEquals(msg.str(), vector1->at(ii), vector4->at(ii) ); 
  }
  if (size4 > 1) unit.assertNull("<M> list4->next->next", list4->next->next ); 

  list4 = interleave(list3, list2);
  cout << "<N> List 4: ";
  print( list4 );
  size2 = size(list2); 
  size4 = size(list4); 
  unit.assertEquals("<N> list4 size", size2, size4 ); 
  delete vector2;
  vector2 = to_vector( list2 ); 
  delete vector4;
  vector4 = to_vector( list4 ); 
  for (int ii=0; ii<size4; ++ii){ 
    stringstream msg; 
    msg << "<N> list4 Node[" << ii << "]"; 
    unit.assertEquals(msg.str(), vector2->at(ii), vector4->at(ii) ); 
  }

  list4 = interleave(list3, list3);
  cout << "<O> List 4: ";
  print( list4 );
  size4 = size(list4); 
  unit.assertEquals("<O> list4 size", 0, size4 ); 
  unit.assertNull("<O> list4 ", list4 ); 
  
  unit.printResults(); 
  delete vector1;
  delete vector2;
  delete vector4;

#ifdef _WIN32
  system("PAUSE"); // needed for windows to prevent the program from terminating and the command window to close
#endif

  return 0;
}
