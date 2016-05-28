#ifdef _LINKEDLIST_H_
#include <stdexcept>
using namespace std;

// helper function for deep copy
// Used by copy constructor and operator=
template <typename T>
void LinkedList<T>::CopyList(const LinkedList& ll) {
    DeleteList();
    int copy_size = ll.Size();
    if(copy_size) {
        front = new Node<T>(ll.ElementAt(0));
        Node<T> *pred = front, *temp;
        for(int i = 1; i < copy_size; i++) {
            temp = new Node<T>(ll.ElementAt(i));
            temp->prev = pred;
            pred->next = temp;
            pred = temp;
        }
        back = pred;
        size += copy_size;
    }
}

// helper function for deep delete
// Used by destructor and copy/assignment
template <typename T>
void LinkedList<T>::DeleteList() {
    Node<T> *curr = front, *temp;
    while(curr) {
        temp = curr;
        curr = curr->next;
        delete temp;
    }
    size = 0;
    front = back = NULL;
}

// default constructor
template <typename T>
LinkedList<T>::LinkedList() : size(0), front(NULL), back(NULL) {}

// copy constructor, performs deep copy of list elements
template <typename T>
LinkedList<T>::LinkedList(const LinkedList& ll) : size(0), front(NULL), back(NULL) {
    CopyList(ll);
}

// destructor
template <typename T>
LinkedList<T>::~LinkedList() {
    DeleteList();
}

// MUTATORS

// Inserts an item at the front of the list
// POST: List contains item at position 0
// PARAM: item = item to be inserted
template <typename T>
void LinkedList<T>::InsertFront(T item) {
    Node<T> *temp = new Node<T>(item);
    if(size++ == 0) {
        front = back = temp;
    } else {
        temp->next = front;
        front->prev = temp;
        front = temp;
    }
}

// Inserts an item at the back of the list
// POST: List contains item at back
// PARAM: item = item to be inserted
template <typename T>
void LinkedList<T>::InsertBack(T item) {
    Node<T> *temp = new Node<T>(item);
    if(size++ == 0) {
        front = back = temp;
    } else {
        temp->prev = back;
        back->next = temp;
        back = temp;
    }
}

// Inserts an item in position p (0-indexed)
// Throws exception for invalid index
// PRE: 0 <= p <= size
// POST: List contains item at position p
// PARAM: item = item to be inserted, p = position where item will be inserted
template <typename T>
void LinkedList<T>::InsertAt(T item, int p) {
    if(p < 0 || p > size) // invalid index
        throw invalid_argument("invalid index");  
    if(size++ == 0) { // insert to an empty list
        front = new Node<T>(item);
        back = front;
        return;
    }
    Node<T> *temp = new Node<T>(item);
    if(p == 0) { // insertFront
        temp->next = front;
        front->prev = temp;
        front = temp;
        return;
    }
    if(p+1 == size) { // insertBack
        temp->prev = back;
        back->next = temp;
        back = temp;
        return;
    }
    // insertMiddle
    Node<T> *mark = front;
    while(p-- > 0)
        mark = mark->next;
    temp->prev = mark->prev;
    temp->next = mark;
    mark->prev->next = temp;
    mark->prev = temp;
}

// Removes and returns an item from position p (0-indexed)
// Throws exception if list is empty or index invalid
template <typename T>
T LinkedList<T>::RemoveAt(int p) {
    if(p < 0 || p >= size) // invalid index 
            throw invalid_argument("invalid index");
    // Remove Front:
    if(p == 0) {
        Node<T> *temp = front;
        T d = temp->data;
        front = front->next;
        size--;
        if(size == 0) back = NULL;
        delete temp;
        return d;
    }
    // Remove Back:
    if(p == (size-1)) {
        Node<T> *temp = back;
        T d = temp->data;
        back = back->prev;
        size--;
        delete temp;
        return d;
    }
    // Remove Middle:
    Node<T>* mark = front;
    while(p--)
        mark = mark->next;
    T d = mark->data;
    mark->prev->next = mark->next;
    mark->next->prev = mark->prev;
    size--;
    delete mark;
    return d;
}

// Appends the contents of the parameter list to the back of this list as a deep copy
// PRE:
// POST: List contains every element of ll appended to back, size is updated appropriately
template <typename T>
void LinkedList<T>::Append(const LinkedList& ll) {
    Node<T> *temp;
    int append_size = ll.Size();
    for(int i = 0; i < append_size; i++) {
        temp = new Node<T>(ll.ElementAt(i));
        back->next = temp;
        temp->prev = back;
        back = back->next;
    }
    size += append_size;
}

// Removes duplicates from the list, preserving existing order of remaining items.
// The LAST occurrence of any duplicate (relative to the front of the list)
// is the one which remains.
// Efficiency will not be a priority as long as the behaviour above is satisfied.
// PRE:
// POST: List contains no duplicates, front and back point to the appropriate nodes
// PARAM:
template <typename T>
void LinkedList<T>::RemoveDuplicates() {
    Node<T> *temp = front, *check, *dele;
    T t;
    bool dup;
    while(temp) {
        t = temp->data;
        check = temp->next;
        dup = false;
        while(check) {
            if(t == check->data) {
                dup = true;
                break;
            }
            check = check->next;
        }
        if(dup) { // has duplicates 
            dele = temp;
            if(temp == front)
                front = front->next;
            else
                temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            temp = temp->next;
            delete dele;
            size--;
        } else { // no duplicates, go to next
            temp = temp->next;
        }
    }
}

// ACCESSORS

// Return size of list
template <typename T>
int LinkedList<T>::Size() const {
    return size;
}

// Returns whether the list is empty
template <typename T>
bool LinkedList<T>::IsEmpty() const {
    return !size;
}

// Returns existence of item
template <typename T>
bool LinkedList<T>::Contains(T item) const {
    Node<T> *curr = front;
    while(curr) {
        if(curr->data == item)
            return true;
        curr = curr->next;
    }
    return false;
}

// Returns item at index (0-indexed)
// Throws exception for invalid index
template <typename T>
T LinkedList<T>::ElementAt(int p) const {
    if(p < 0 || p > (size-1))
        throw invalid_argument("invalid index");
    Node<T> *curr = front;
    while(p--)
        curr = curr->next;
    return curr->data;
}

// OVERLOADED OPERATORS

// overloaded assignment operator
// must work in the following cases:
// list2 = list1 -> general case
// list2 = list2 -> should do nothing
template <typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& ll) {
    if(this != &ll)
        CopyList(ll);
    return *this;
}
#endif
