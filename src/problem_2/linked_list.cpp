#include "linked_list.h"

template<class T>
void LinkedList<T>::push_front(const T &value) {
    ListNode<T> *newNode = new ListNode(value);
    newNode->next = head->next;
    head->next = newNode;
    num_of_element++;
}

template<class T>
void LinkedList<T>::push_back(const T &value) {
    ListNode<T> *curr = head;
    ListNode<T> *newNode = new ListNode(value);
    while(curr && curr->next)
    {
        curr = curr->next;
    }
    curr->next = newNode;
    num_of_element++;
}

template<class T>
void LinkedList<T>::pop_back(){
    if(head->next == NULL || size() <= 0)
    {
        return;
    }
    ListNode<T> *curr = head;
    while(curr && curr->next->next)
    {
        curr = curr->next;
    }
    ListNode<T> *deleteNode = curr->next;
    curr->next = NULL;
    num_of_element--;
    delete deleteNode;
}

template<class T>
void LinkedList<T>::pop_front() {
    if(head->next == NULL || size() == 0)
    {
        return;
    }
    ListNode<T> *front = head;
    head = head->next;
    num_of_element--;
    delete front;
}

template<class T>
void LinkedList<T>::remove(T &val) {
    if(head->next == NULL)
    {
        return;
    }
    ListNode<T> *curr = head;
    ListNode<T> *prev = nullptr;
    while(curr->next)
    {
        if(curr->next->val == val)
            {
                prev = curr->next;
                curr->next = curr->next->next;
                num_of_element--;
                delete prev;
            }
        else
        {
         curr = curr->next;
        }
    }
}

/*
 * merge in ascending order
 */
template<class T>
void LinkedList<T>::merge(const List<T> &ot) {
    int index = 0;
    int sizeOfMerged = num_of_element + ot.size();
    T *merged = new T[sizeOfMerged];
    ListNode<T> *curr = head;
    ListNode<T> *other = ot->head;
while(curr ->next != nullptr && other->next != nullptr)
{
   if(curr->val > other->val)
   {
       merged[index] = other->val;
   }
   else {
       merged[index] = curr->val;
   }
   index++;
   curr = curr->next;
   other = other->next;
}
while(other)
{
    merged[index] = other->val;
    index++;
    other = other->next;
}
while(curr != nullptr)
{
    merged[index] = curr->val;
    index++;
    curr = curr->next;
}
index = 0;
other = head->next;
while(other)
{
    other->val = merged[index];
    index++;
    other = other->val;
}
for(index; index <= sizeOfMerged; index++)
{
T value = merged[index];
ListNode<T> add = new ListNode<T>(value);
other = add;
other = other->next;
}
num_of_element = sizeOfMerged;
delete[] merged;
    }

    template<class T>
    void LinkedList<T>::reverse_iterative() {
        if (head->next == nullptr) {
            return;
        }
        T *temp = new T[num_of_element];
        ListNode<T> *curr = head->next;
        ListNode<T> *curr1 = head->next;
        int index = num_of_element - 1;
        while (curr) {
            temp[index--] = curr->val;
            curr = curr->next;
        }
        for (int i = 0; i < num_of_element; i++) {
            curr1->val = temp[i];
            curr1 = curr1->next;
        }

    }
