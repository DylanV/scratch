//
// Created by Dylan on 26/05/2016.
//

#include <iostream>
#include "linked_list.h"

LinkedList::LinkedList() {
    size = 0;
    head = NULL;
}

LinkedList::~LinkedList() {
    if(head){
        ListItem * curr_list_item = head;
        while(curr_list_item != NULL){
            ListItem * next_list_item = curr_list_item->next;
            delete(curr_list_item);
            curr_list_item = next_list_item;
        }
    }
}

int LinkedList::get_size() {
    return size;
}

int LinkedList::get_index(const int value) {
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

bool LinkedList::insert(const int value) {

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

int LinkedList::get(const int index) {

    if(index >= size || index < 0){
        return INT_MAX; // error value
    }

    ListItem * curr_list_item = head;
    for(int i=0; i<index; i++){
        curr_list_item = curr_list_item->next;
    }
    return curr_list_item->value;
}

int LinkedList::operator[](const int &index) {
    return get(index);
}

bool LinkedList::remove(const int index) {
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















