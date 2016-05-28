#ifdef _LINKEDLIST_H_
#include <stdexcept>
using namespace std;

template <typename T>
void LinkedList<T>::CopyList(const LinkedList& ll) {
    DeleteList();
    int copy_size = ll.size;
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

template <typename T>
LinkedList<T>::LinkedList() : size(0), front(NULL), back(NULL) {}

template <typename T>
LinkedList<T>::LinkedList(const LinkedList& ll) : size(0), front(NULL), back(NULL) { CopyList(ll); }

template <typename T>
LinkedList<T>::~LinkedList() { DeleteList(); }

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
    Node<T> *mark = front; // insertMiddle
    while(p-- > 0)
        mark = mark->next;
    temp->prev = mark->prev;
    temp->next = mark;
    mark->prev->next = temp;
    mark->prev = temp;
}

template <typename T>
T LinkedList<T>::RemoveAt(int p) {
    if(p < 0 || p >= size) // invalid index 
            throw invalid_argument("invalid index");
    size--;
    Node<T>* temp = front;
    if(p == 0) {
        front = front->next;
        if(size == 0) back = NULL;
    } else if(p == size) {
        temp = back;
        back = back->prev;
    } else {
        while(p--)
            temp = temp->next;
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
    }
    T d = temp->data;
    delete temp;
    return d;
}

template <typename T>
void LinkedList<T>::Append(const LinkedList& ll) {
    Node<T> *temp;
    int append_size = ll.size;
    for(int i = 0; i < append_size; i++) {
        temp = new Node<T>(ll.ElementAt(i));
        back->next = temp;
        temp->prev = back;
        back = back->next;
    }
    size += append_size;
}

template <typename T>
void LinkedList<T>::RemoveDuplicates() {
    Node<T> *temp = front, *check, *dele;
    bool dup;
    while(temp) {
        check = temp->next;
        dup = false;
        while(check) {
            if(temp->data == check->data) {
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

template <typename T>
int LinkedList<T>::Size() const { return size; }

template <typename T>
bool LinkedList<T>::IsEmpty() const { return !size; }

template <typename T>
bool LinkedList<T>::Contains(T item) const {
    Node<T> *curr = front;
    while(curr) {
        if(curr->data == item) return true;
        curr = curr->next;
    }
    return false;
}

template <typename T>
T LinkedList<T>::ElementAt(int p) const {
    if(p < 0 || p > (size-1)) throw invalid_argument("invalid index");
    Node<T> *curr = front;
    while(p--) curr = curr->next;
    return curr->data;
}

template <typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& ll) {
    if(this != &ll) CopyList(ll);
    return *this;
}
#endif
