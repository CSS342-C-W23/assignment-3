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

//ll
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
    while (find(val))
    {
        ListNode<T> *tmp = head;

        // tmp stops at node before target or end of list
        while (tmp->next != nullptr && tmp->next->val != val)
            tmp = tmp->next;

        ListNode<T> *tmp2 = tmp->next;

        tmp->next = tmp->next->next;
        delete tmp2;
        num_of_element--;
    }
    /*while (tmp != nullptr && tmp->next != nullptr) {
        if (tmp->next->val == val) {
            ListNode<T>* tmp2 = tmp->next;
            tmp->next = tmp2->next;
            delete tmp2;
            num_of_element--;
        }
        else {
            tmp = tmp->next;
        }
    }*/

}

/*
 * merge in ascending order
 */
template<class T>
void LinkedList<T>::merge(const List<T> &ot) {
    /*
     * TODO: homework
     */

    auto &other_list = (LinkedList<T> &) ot;


    ListNode<T>* cur1 = head;
    ListNode<T>* cur2 = other_list.head;
    while (cur1->next != nullptr && cur2->next != nullptr) {
        if (cur1->next->val < cur2->next->val) {
            cur1 = cur1->next;
        } else {
            ListNode<T>* tmp = cur1->next;
            cur1->next = new ListNode<T>(cur2->next->val);
            cur1->next->next = tmp;
            cur1 = cur1->next;

            cur2 = cur2->next;

        num_of_element++;
        }
    }
    while(cur2->next != nullptr) {
        cur2 = cur2->next;
        push_back(cur2->val);
    }

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

template<class T>
bool LinkedList<T>::find(T& val) {
    ListNode<T> *tmp = head;
    while (tmp->next != nullptr) {
        tmp = tmp->next;
        if (tmp->val == val) {
            return true;
        }
    }
    return false;
}