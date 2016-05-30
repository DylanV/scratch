//
// Created by Dylan on 26/05/2016.
//

#ifndef SCRATCH_LINKED_LIST_H
#define SCRATCH_LINKED_LIST_H

#include <memory>


template <class T> class LinkedList {

    struct ListItem{
        T value;
        ListItem* next;
        ListItem() : next(nullptr) {};
        ListItem(T value) : value(value), next(nullptr) {};
    };

public:

    LinkedList();
    ~LinkedList();

    int get_size();
    bool insert(const T value);
    int get_index(const T value);
    T get(const int index);
    T peek_at(const int index);
    bool remove(const int index);
    T operator[](const int index);
    bool swap(int index1, int index2);

private:
    int size;
    ListItem* head;
    ListItem* tail;
};


template <class T>
LinkedList<T>::LinkedList():size(0), head(nullptr) { }

template <class T>
LinkedList<T>::~LinkedList() {
    ListItem * curr_list_item = head;
    while(curr_list_item != nullptr){
        ListItem * next_list_item = curr_list_item->next;
        delete(curr_list_item);
        curr_list_item = next_list_item;
    }
    head = nullptr;
}

template <class T>
int LinkedList<T>::get_size() {
    return size;
}

template <class T>
int LinkedList<T>::get_index(const T value) {
    if(size ==0){
        return -1;
    }
    ListItem * curr_list_item = head;
    int index = 0;
    while(curr_list_item != NULL){
        if(curr_list_item-> value == value){
            return index;
        }
        curr_list_item = curr_list_item->next;
        index++;
    }
    return -1;
}

template <class T>
bool LinkedList<T>::insert(const T value) {

    if(size == 0){
        head = new ListItem(value);
        size += 1;
        tail = head;
    }
    else{
        tail->next = new ListItem;
        tail = tail->next;
        tail->value = value;
        tail->next = NULL;
        size += 1;
    }
    return true;
}

template <class T>
T LinkedList<T>::get(const int index) {

    if(index >= size || index < 0){
        throw std::out_of_range("Index out of range");
    }

    ListItem * curr_list_item = head;
    if(index == size -1){ // kept track of tail so no need to iterate through whole list
        curr_list_item = tail;
    } else{
        for(int i=0; i<index; i++){
            curr_list_item = curr_list_item->next;
        }
    }

    T ret_value = curr_list_item->value;
    remove(index);
    return ret_value;
}

template <class T>
T LinkedList<T>::peek_at(const int index) {

    if(index >= size || index < 0){
        throw std::out_of_range("Index out of range");
    }

    ListItem * curr_list_item = head;
    for(int i=0; i<index; i++){
        curr_list_item = curr_list_item->next;
    }
    return curr_list_item->value;
}

template <class T>
T LinkedList<T>::operator[](const int index) {
    return this->peek_at(index);
}

template <class T>
bool LinkedList<T>::swap(int index1, int index2) {
    if(index1 < 0 || index1 > size-1 || index1 == index2 || index2 < 0 || index2 > size-1){
        return false;
    }
    ListItem* first = head;
    ListItem* second = head;
    int ind1 = index1;
    int ind2 = index2;
    if(ind2 < ind1){
        int temp = ind2;
        ind2 = ind1;
        ind1 = temp;
    }

    assert(ind1 < ind2);

    for(int i=0; i<ind1; i++){
        first = first->next;
        second = second->next;
    }
    for(int i=0; i<ind2-ind1; i++){
        second = second->next;
    }

    T temp = second->value;
    second->value = first->value;
    first->value = temp;
}

template <class T>
bool LinkedList<T>::remove(const int index) {
    if(index >= size || index < 0){
        return false;
    }

    if(index == 0){ // remove head
        ListItem * next_item = head->next;
        delete(head);
        head = next_item;
        size--;
        return true;
    }
    else if(index == size - 1){ //remove tail
        ListItem * curr_list_item = head;
        ListItem * prev_list_item = head;
        for(int i=0; i<index; i++){
            prev_list_item = curr_list_item;
            curr_list_item = curr_list_item->next;
        }
        prev_list_item->next = curr_list_item->next;
        delete(curr_list_item);
        size--;
        tail = prev_list_item;
        return true;
    }
    else{
        ListItem * curr_list_item = head;
        ListItem * prev_list_item = head;
        for(int i=0; i<index; i++){
            prev_list_item = curr_list_item;
            curr_list_item = curr_list_item->next;
        }
        prev_list_item->next = curr_list_item->next;
        delete(curr_list_item);
        size--;
        return true;
    }
}

#endif //SCRATCH_LINKED_LIST_H
