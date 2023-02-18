#include "linked_list.h"

template<class T>
void LinkedList<T>::push_front(const T &value) {
    //We reassign the value we are given to be the head of list
    //and add a new head node

    //Make newNode and set val to parameter value 
    //and a next pointer to the head node
    ListNode<T> *ptrPushFront = new ListNode<T>;
    ptrPushFront->val = value;
    ptrPushFront->next = head;

    //Change head to the node we just added
    //which also has a pointer to the previous head
    //also update num of elements
    head = ptrPushFront;
    num_of_element++;
}

template<class T>
void LinkedList<T>::push_back(const T &value) {
    //Add a element to the linked list, added to the end

    //Used to help travel to the last item in the linked list
    ListNode<T> *ptrCurrent = head->next;

    //Travel until we reach the end of the list
    //Where we can add a item
    while(ptrCurrent != nullptr){
        ptrCurrent = ptrCurrent->next;
    }

    //Make a newNode and set it's val to given value
    //and let it point to nullptr since it's
    //at the end of linked list
    ListNode<T> *ptrPushBack = new ListNode<T>;
    ptrPushBack->val = value;
    ptrPushBack->next = nullptr;

    
    //We can now add the item to the back of the list
    //Update the num of elements in linked list too
    ptrCurrent = ptrPushBack;
    num_of_element++;
}

template<class T>
void LinkedList<T>::pop_back() {
    //Remove the last element in the linked list
    //Used to help travel to the last item in the linked list
    ListNode<T> *ptrPopBack = head->next;

    //Travel until we reach the end of the list
    //At the very last item of the list
    while(ptrPopBack->next != nullptr){
        ptrPopBack = ptrPopBack->next;
    }

    //We have reached the last item, set to null to pop
    //Update the num of elements in linked list too
    ptrPopBack = nullptr;
    num_of_element--;
}

template<class T>
void LinkedList<T>::pop_front() {
    //Removing the head from the linked list
    //Keep track of the head in temp, and move head to next item
    ListNode<T> *ptrPopTemp = head;
    head = head->next;

    //Pop the front item and update num of elements
    //The previous head is set to nullptr
    ptrPopTemp = nullptr;
    num_of_element--;
}

template<class T>
void LinkedList<T>::remove(T &val) {
    //We look for val in the linked list and remove it
    //Previous is always 1 item behind current ptr
    ListNode<T> *ptrRemovePrevious = head;
    ListNode<T> *ptrRemoveCurrent = head->next;

    //Checks the head since loop doesn't check
    if(ptrRemovePrevious->val == val){
        pop_front();
    }

    //Keeps looping in the list until we find all val we want to remove
    //We can add condition "|| ptrRemove->val != val" to while loop
    //If we only want to delete one instance of val if there are multiple
    //val in the linked list
    while(ptrRemoveCurrent != nullptr){
        //We found the value we want to remove
        //Shift items in linked list
        if(ptrRemoveCurrent->val == val){

            //Make it so previous item is linked to the item after our current
            ptrRemovePrevious->next = ptrRemoveCurrent->next;

            //Set our current to null for successful remove, update num of elements
            ptrRemoveCurrent = nullptr;
            num_of_element--;
        }
        else{
            //Travel through the list
            ptrRemovePrevious = ptrRemovePrevious->next;
            ptrRemoveCurrent = ptrRemoveCurrent->next;
        }
    }


    
}

/*
 * merge in ascending order
 */
template<class T>
void LinkedList<T>::merge(const List<T> &ot) {

    //Set otherList as a linked list
    auto &other_list = (LinkedList<T> &) ot;

    //Checks if otherList is empty
    if (other_list.num_of_element == 0) {
        return;
    }

    //Setup our merged link list
    T *mergedListTemp = new T[mergedListSize];
    size_t mergedListSize = num_of_element + ot.num_of_element;

    //Setup pointers to track and compare both linked list items

    ListNode<T> *ptrMergedListCurrent = head;
    ListNode<T> *ptrMergedOtherListCurrent = other_list.head;

    //Loops for the entire merged Linked list size
    for(size_t i=0; i<mergedListSize; i++){

        //Checks if we run out elements in currentList
        if(ptrMergedListCurrent == nullptr){

        }
        //Checks if we run out elements in otherList
        else if(ptrMergedOtherListCurrent == nullptr){

        }
        //Checks the 
        else{

        }

        while(){


        }

        while(){
            
        }
    }

}

template<class T>
void LinkedList<T>::reverse_iterative() {
    //Reverses the linked list

    //Pointers to keep track of current, previous and next nodes
    ListNode<T> *ptrReverseCurrent = head;

    //So that we can swap pointers to reverse, nullptr
    //because one of pointers will be the last node in reversed list
    //Acts sort of like another linked list we are building
    //ptrReverseNext keeps track of original linked list
    //Previous and current jump around between building and original
    //List to build our reversed list
    ListNode<T> *ptrReversePrevious = nullptr;
    ListNode<T> *ptrReverseNext = nullptr;

    //Loops until end of list
    while(ptrReverseCurrent != nullptr){

        //Next node will point backwards to our current
        ptrReverseNext = ptrReverseCurrent->next;

        //Next node will be our previous because backwards
        //First loop the item will point towards null
        //signifying the last item in the list
        ptrReverseCurrent->next = ptrReversePrevious;

        //Pointer is used to keep track of original linked list
        //and to prepare for next loop
        ptrReversePrevious = ptrReverseCurrent;
        ptrReverseCurrent = ptrReverseNext;
    }

    //Reassign our head to point to where it's suppose to be
    //after reversing the list
    head = ptrReversePrevious;
}