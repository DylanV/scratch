//
// Created by Dylan on 26/05/2016.
//

#ifndef SCRATCH_LINKED_LIST_H
#define SCRATCH_LINKED_LIST_H

#include <memory>

//typedef struct ListItem ListItem;



template <class T> class LinkedList {

    struct ListItem{
        T value;
        ListItem* next;
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
    T operator[](const int& index);

private:
    int size;
    ListItem* head;
    ListItem* tail;
};


template <class T>
LinkedList<T>::LinkedList() {
    size = 0;
    head = NULL;
}

template <class T>
LinkedList<T>::~LinkedList() {
    if(head){
        ListItem * curr_list_item = head;
        while(curr_list_item != NULL){
            ListItem * next_list_item = curr_list_item->next;
            delete(curr_list_item);
            curr_list_item = next_list_item;
        }
    }
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
        head = new ListItem;
        head->value = value;
        head->next = NULL;
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
T LinkedList<T>::operator[](const int &index) {
    return get(index);
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
