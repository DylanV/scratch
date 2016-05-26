//
// Created by Dylan on 26/05/2016.
//

#include <iostream>
#include "linked_list.h"

LinkedList::LinkedList()
{
    size = 0;
    head = NULL;
}

LinkedList::~LinkedList()
{
    if(head){
        ListItem * curr_list_item = head;
        while(curr_list_item->next != NULL){
            ListItem * next_list_item = curr_list_item->next;
            delete(curr_list_item);
            curr_list_item = next_list_item;
        }
    }
}

int LinkedList::get_size() {
    return size;
}

int LinkedList::get_index(int value) {
    if(size ==0){
        return -1;
    }
    ListItem * curr_list_item = head;
    int index = 0;
    while(curr_list_item->next != NULL){
        if(curr_list_item-> value == value){
            return index;
        }
        curr_list_item = curr_list_item->next;
        index++;
    }
    return -1;
}

bool LinkedList::insert(int value) {

    if(size == 0){
        head = new ListItem;
        head->value = value;
        head->next = NULL;
        size += 1;
    }
    else{
        ListItem * curr_list_item = head;
        while(curr_list_item->next != NULL){
            curr_list_item = curr_list_item->next;
        }
        curr_list_item->next = new ListItem;
        curr_list_item->next->value = value;
        curr_list_item->next->next = NULL;
        size += 1;
    }
    return true;
}

int LinkedList::get(int index) {

    ListItem * curr_list_item = head;
    for(int i=0; i<index; i++){
        curr_list_item = curr_list_item->next;
    }
    return curr_list_item->value;
}

bool LinkedList::remove(int index) {
    if(index >= size){
        return false;
    }

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











