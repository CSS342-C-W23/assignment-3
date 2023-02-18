#include "linked_list.h"

template<class T>
void LinkedList<T>::push_front(const T &value) {
    /*
     * TODO: homework
     */
    ListNode<T>* tmp = new ListNode<T>(value);
    tmp->next = head->next;
    head->next = tmp;
    num_of_element++;
}

template<class T>
void LinkedList<T>::push_back(const T &value) {
    /*
     * TODO: homework
     */
    ListNode<T>* new_node = new ListNode<T>(value);
    new_node->val = value;
    new_node->next = nullptr;
    if(head == nullptr) {
        head = new_node;
    } else {
        ListNode<T>* temp = head;
        while(temp->next != nullptr)
            temp = temp->next;
        temp->next = new_node;
    }
    num_of_element++;
}


template<class T>
void LinkedList<T>::pop_back() {
    /*
     * TODO: homework
     */
    if(num_of_element == 0) {
        return;
    }

    ListNode<T> *tmp = head;

    while(tmp->next->next != nullptr) {
        tmp = tmp->next;
    }
    delete tmp->next;
    tmp->next = nullptr;
    num_of_element--;

}

template<class T>
void LinkedList<T>::pop_front() {
    /*
     * TODO: homework
     */
    if(num_of_element == 0) {
        return;
    }

    ListNode<T> *tmp = head;
    head = head->next;
    delete tmp;
    num_of_element--;

}

template<class T>
void LinkedList<T>::remove(T &val) {
    /*
     * TODO: homework
     */
    ListNode<T> *tmp = head;
    while (tmp->next != nullptr) {
        if (tmp->next->val == val) {
            ListNode<T>* tmp2 = tmp->next;
            tmp->next = tmp2->next;
            delete tmp2;
            num_of_element--;
            return;
        }
        tmp = tmp->next;
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



}

template<class T>
void LinkedList<T>::reverse_iterative() {
    /*
     * TODO: homework
     */

    if(num_of_element <= 1) {
        return;
    }

    ListNode<T> *prev = nullptr;
    ListNode<T> *curr = head->next;
    ListNode<T> *next = nullptr;

    while(curr != nullptr) {
        next = curr ->next;
        curr ->next = prev;
        prev = curr;
        curr = next;
    }
    head->next = prev;
}
