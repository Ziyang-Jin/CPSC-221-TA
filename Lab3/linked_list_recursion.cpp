// linked_list.cpp -- functions for linked_list lab (cs221) 
#include <iostream>
#include <vector>
using namespace std;

struct Node {
  int key;
  Node* next;
}; 

/**
 * Inserts a new Node (with key=newKey) at the head of the linked_list.
 * PRE: head is the first node in a linked_list (if NULL, linked_list is empty) 
 * PRE: newKey is the value for the key in the new Node 
 * POST: the new Node is now the head of the linked_list
 */ 
void insert(Node*& head, int newKey) {
  Node * curr = new Node;
  curr->key  = newKey;
  curr->next = head;

  head = curr;
}

/**
 * Print the keys of a linked_list in order, from head to tail 
 * PRE: head is the first node in a linked_list (if NULL, linked_list is empty) 
 */ 
void print(Node* head) {
  cout << "[";
  for (Node* curr = head; curr != NULL; curr = curr->next){ 
    cout << curr->key;
    if (curr->next != NULL) cout << ", ";
  }
  cout << "]" << endl;
}

/** 
 * Returns the size (number of Nodes) of the linked_list  
 * PRE: head is the first node in a linked_list (if NULL, linked_list is empty) 
 */ 
int size(Node* head){ 
  if (! head) return 0; 
  return 1 + size(head->next); 
}

/**
 * Copies the keys in a linked list to a vector.
 * PRE: head is the first node in a linked_list (if NULL, linked_list is empty) 
 * POST: a new vector<int> containing the keys in the correct order has been returned.  
 */ 
vector<int>* to_vector(Node* head){ 
  vector<int>* result = new vector<int>(); 
  for (Node* curr = head; curr != NULL; curr = curr->next ){ 
    result->push_back(curr->key); 
  }
  return result; 
}

/** 
 * Delete the last Node in the linked_list
 * PRE: head is the first Node in a linked_list (if NULL, linked_list is empty) 
 * POST: the last Node of the linked_list has been removed
 * POST: if the linked_list is now empty, head has been changed 
 */
void delete_last_element(Node*& head){
  // ******** WRITE YOUR CODE HERE ********
    if (!head) return; // head == NULL
    if (!head->next) { // one-element list
        delete(head);
        head = NULL;
        return;
    }
    Node* curr = head;
    while(curr->next->next) 
        curr = curr->next;
    delete(curr->next);
    curr->next = NULL;
}

/**
 * Removes an existing Node (with key=oldKey) from the linked_list. 
 * PRE: head is the first node in a linked_list (if NULL, linked_list is empty) 
 * PRE: oldKey is the value of the key in the Node to be removed 
 * PRE: if no Node with key=oldKey exists, the linked_list has not changed 
 * POST: if a Node with key=oldKey was found, then it was deleted
 * POST: other Nodes with key=oldKey might still be in the linked_list
 */ 
void remove(Node*& head, int oldKey) {
  // ******** WRITE YOUR CODE HERE ********
    if(!head) return; // head == NULL
    if(!head->next) { // one-element list
        if(head->key == oldKey) {
            delete(head);
            head = NULL;
        }
            return;
    }
    Node* curr = head;
    if(curr->key == oldKey) { // more than two elements, and key in the head element
        head = curr->next;
        delete(curr);
        return;
    } 
    while(curr->next && curr->next->key != oldKey)
        curr = curr->next;
    if(!curr->next) return; // last element
    Node* temp = curr->next; // oldkey is in curr->next
    curr->next = temp->next;
    delete(temp); 
}

/**
 * Insert a new Node (with key=newKey) after an existing Node (with key=oldKey)
 * If there is no existing Node with key=oldKey, then no action.
 * PRE: head is the first Node in a linked_list (if NULL, linked_list is empty) 
 * PRE: oldKey is the value to look for (in the key of an existing Node)  
 * PRE: newKey is the value of the key in the new Node (that might be inserted) 
 * POST: If no Node with key=oldKey was found, then the linked_list has not changed 
 * POST: Else a new Node (with key=newKey) is right after the Node with key = oldKey. 
 */
void insert_after(Node* head, int oldKey, int newKey){
  // ******** WRITE YOUR CODE HERE ********
    if(!head) return; // empty 
    Node* curr = head;
    while (curr->key != oldKey && curr->next)
        curr = curr->next;
    if(curr->key == oldKey) {
        Node* n = new Node;
        n->key = newKey;
        n->next = curr->next;
        curr->next = n;
    }
}

/** 
 * Create a new linked_list by merging two existing linked_lists. 
 * PRE: list1 is the first Node in a linked_list (if NULL, then it is empty)
 * PRE: list2 is the first Node in another linked_list (if NULL, then it is empty)
 * POST: A new linked_list is returned that contains new Nodes with the keys from 
 * the Nodes in list1 and list2, starting with the key of the first Node of list1, 
 * then the key of the first Node of list2, etc. 
 * When one list is exhausted, the remaining keys come from the other list.
 * For example: [1, 2] and [3, 4, 5] would return [1, 3, 2, 4, 5]
 */
Node* interleave(Node* list1, Node* list2){
  // ******** WRITE YOUR CODE HERE ********
    if(!list1 && !list2) return NULL;    

    if(list1 && list2) {
        Node* n1 = new Node;
        Node* n2 = new Node;
        n1->key = list1->key;
        n2->key = list2->key;
        n1->next = n2;
        n2->next = interleave(list1->next, list2->next);
        return n1;
    }
    
    if(list2) {
        Node* n2 = new Node;
        n2->key = list2->key;
        n2->next = interleave(NULL, list2->next);
        return n2;
    }
    
    if(list1) {
        Node* n1 = new Node;
        n1->key = list1->key;
        n1->next = interleave(list1->next, NULL);
        return n1;
    }
}

