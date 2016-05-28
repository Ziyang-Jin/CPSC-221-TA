#ifdef _LINKEDLIST_H_
#include <stdexcept>

template <typename T>
void LinkedList<T>::CopyList(const LinkedList& ll) {
    DeleteList();
    for(int i = 0; i < ll.size; i++) InsertBack(ll.ElementAt(i));
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
    if(size++ != 0) {
        temp->next = front;
        front->prev = temp;
        front = temp;
    } else front = back = temp;
}

template <typename T>
void LinkedList<T>::InsertBack(T item) {
    Node<T> *temp = new Node<T>(item);
    if(size++ != 0) {
        temp->prev = back;
        back->next = temp;
        back = temp;
    } else front = back = temp;
}

template <typename T>
void LinkedList<T>::InsertAt(T item, int p) {
    if(p > 0 && p < size) {
        Node<T> *temp = new Node<T>(item);
        Node<T> *mark = front;
        while(p-- > 0) mark = mark->next;
        temp->prev = mark->prev;
        temp->next = mark;
        mark->prev->next = temp;
        mark->prev = temp;
        size++;
    } else if(p == 0) InsertFront(item);
    else if (p == size) InsertBack(item);
    else throw std::invalid_argument("invalid index");
}

template <typename T>
T LinkedList<T>::RemoveAt(int p) {
    if(p < 0 || p >= size) throw std::invalid_argument("invalid index");
    size--;
    Node<T>* temp = front;
    if(p == 0) {
        front = front->next;
        if(size == 0) back = NULL;
    } else if(p == size) {
        temp = back;
        back = back->prev;
    } else {
        while(p--) temp = temp->next;
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
    }
    T d = temp->data;
    delete temp;
    return d;
}

template <typename T>
void LinkedList<T>::Append(const LinkedList& ll) { for(int i = 0; i < ll.size; i++) InsertBack(ll.ElementAt(i)); }

template <typename T>
void LinkedList<T>::RemoveDuplicates() {
    if(size > 2) {
        Node<T> *temp = front, *check;
        while(temp != back) {
            check = temp->next;
            while(check && check->data != temp->data) check = check->next;
            if(check) { // has duplicates 
                Node<T> *dele = temp;
                if(temp == front) front = front->next;
                else temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
                temp = temp->next;
                delete dele;
                size--;
            } else temp = temp->next;
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
    if(p >= 0 && p < size) {
        Node<T> *curr = front;
        while(p--) curr = curr->next;
        return curr->data;
    } else throw std::invalid_argument("invalid index");
}

template <typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& ll) {
    if(this != &ll) CopyList(ll);
    return *this;
}
#endif
