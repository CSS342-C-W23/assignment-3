#include "linked_list.h"

template<class T>
void LinkedList<T>::push_front(const T &value) {
    /*
     * TODO: homework
     */
    ListNode<T> *to_add = new ListNode(value);
    to_add->next = head->next;
    head->next = to_add;
    num_of_element++;
}

template<class T>
void LinkedList<T>::push_back(const T &value) {
    /*
     * TODO: homework
     */
    ListNode<T> *current = head;
    while (current->next != nullptr){
        current = current->next;
    }
    ListNode<T> *new_node = new ListNode(value);
    current->next = new_node;
    num_of_element++;
}

template<class T>
void LinkedList<T>::pop_back() {
    /*
     * TODO: homework
     */
    if (head->next == nullptr) return;
    ListNode<T> *current = head;
    while (current->next->next != nullptr){
        current = current->next;
    }
    ListNode<T> *to_delete = current->next;
    current->next = nullptr;
    delete to_delete;
    num_of_element--;
}

template<class T>
void LinkedList<T>::pop_front() {
    /*
     * TODO: homework
     */
    if (head->next == nullptr) return;
    ListNode<T> *to_delete = head->next;
    head->next = head->next->next;
    delete to_delete;
    num_of_element--;
}

template<class T>
void LinkedList<T>::remove(T &val) {
    /*
     * TODO: homework
     */
    if (head->next == nullptr) return;
    ListNode<T> *current = head;
    while (current->next != nullptr){
        if (current->next->val == val){
            ListNode<T> *to_delete = current->next;
            current->next = current->next->next;
            delete to_delete;
            num_of_element--;
        }
        else current = current->next;
    }
}

/*
 * merge in ascending order
 */
template<class T>
void LinkedList<T>::merge(const List<T> &ot) {
    /*
     * TODO: homework
     */
    const List<T> *ptr = &ot;
    const LinkedList<T> * ar = dynamic_cast<const LinkedList<T>*>(ptr);
    int size_of_merged = num_of_element + ar->num_of_element;
    ListNode<T> *self = head->next;
    ListNode<T> *current = ar->head->next;
    int index = 0;
    if (ar->head->next == nullptr) return;
    else{
        T *merged = new T[size_of_merged];
        while (current->next != nullptr && self->next != nullptr){
            if (current->val > self->val) merged[index] = self->val;
            else merged[index] = current->val;
            index++;
            current = current->next;
            self = self->next;
        }
        while (self != nullptr){
            merged[index] = self->val;
            index++;
            self = self->next;
        }
        while (current != nullptr){
            merged[index] = current->val;
            index ++;
            current = current->next;
        }
        index = 0;
        self = head->next;
        while (self != nullptr){
            self->val = merged[index];
            index++;
            self = self->next;
        }
        for (index; index <= size_of_merged; index ++){
            T data = merged[index];
            ListNode<T> *to_add = new ListNode<T>(data);
            self = to_add;
            self = self->next;
        }
        num_of_element = size_of_merged;
        delete[] merged;
    }
}

template<class T>
void LinkedList<T>::reverse_iterative() {
    /*
     * TODO: homework
     */
    if (head->next == nullptr) return;
    T *reversed = new T[num_of_element];
    ListNode<T> *current = head->next;
    ListNode<T> *curr = head->next;
    int i = num_of_element-1;
    while (current != nullptr){
        T data = current->val;
        reversed[i] = data;
        current = current->next;
        i--;

    }
    for (int j = 0; j < num_of_element; j ++){
        curr->val = reversed[j];
        curr = curr->next;

    }
    delete[] reversed;
}