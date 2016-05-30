//
// Created by Dylan Verrezen on 2016/05/27.
//

#ifndef SCRATCH_DOUBLE_LINKED_LIST_H
#define SCRATCH_DOUBLE_LINKED_LIST_H

#include <limits.h>

template <class T> class DoubleLinkedList {

    struct Node {
        T value;
        Node* next;
        Node* prev;
        Node() : next(NULL), prev(NULL) {};
        Node(T value) : value(value), next(nullptr), prev(nullptr) {};
    };

public:
    DoubleLinkedList();
    ~DoubleLinkedList();

    int get_size();
    bool insert(T value);
    T peek();
    T peek_at(int index);
    T get();
    T get_at(int index);
    int index_of(T value);
    int last_index_of(T value);
    bool remove(int index);

private:
    Node* head;
    Node* tail;
    int size;
};

template <class T>
DoubleLinkedList<T>::DoubleLinkedList() : head(NULL), tail(NULL), size(0) {}

template <class T>
DoubleLinkedList<T>::~DoubleLinkedList() {
    Node * curr= head;
    while(curr != nullptr){
        Node* next = curr->next;
        delete (curr);
        curr = next;
    }
    head = nullptr;
    tail = nullptr;
}

template <class T>
int DoubleLinkedList<T>::get_size() {
    return size;
}

template <class T>
bool DoubleLinkedList<T>::insert(T value) {
    if(size == 0) {
        head = new Node(value);
        tail = head;
    } else{
        Node* new_node = new Node(value);
        new_node->prev = tail;
        tail->next = new_node;
        tail = new_node;
    }
    size++;
    return true;
}

template <class T>
T DoubleLinkedList<T>::peek_at(int index) {
    if(index >= size || index < 0){
        throw std::out_of_range("Index out of range");
    }
    if(index == 0){
        return head->value;
    }
    else if(index == size - 1){
        return tail->value;
    }
    else{
        Node* curr = head;
        for(int i=0; i<index; i++){
            curr = curr->next;
        }
        return curr->value;
    }
}

template <class T>
T DoubleLinkedList<T>::peek(){
    return peek_at(0);
}

template <class T>
int DoubleLinkedList<T>::index_of(T value) {
    Node* current = head;
    int index = 0;
    while(current != nullptr){
        if(current->value == value){
            return index;
        }
        current = current->next;
        index++;
    }
    return INT_MAX; //error value
}

template <class T>
int DoubleLinkedList<T>::last_index_of(T value) {
    Node* current = tail;
    int index = size - 1;
    while(current != nullptr){
        if(current->value == value){
            return index;
        }
        current = current->prev;
        index--;
    }
    return INT_MAX; //error value
}

template <class T>
bool DoubleLinkedList<T>::remove(int index) {
    if(index <0 || index > size-1 || size == 0){
        return false;
    }
    if(index == 0){ //delete head
        Node* new_head = head->next;
        if(new_head != nullptr){
            new_head->prev = nullptr;
        }
        delete(head);
        head = new_head;
        if(size <= 2){
            tail = head;
        }
    }
    else if(index == size - 1){ //delete tail
        Node* new_tail = tail->prev;
        new_tail->next = nullptr;
        delete(tail);
        tail = new_tail;
    }
    else{
        Node* current = head;
        for(int i=0; i<index; i++){
            current = current->next;
        }
        Node* previous = current->prev;
        Node* next = current->next;
        previous->next = next;
        next->prev = previous;
        delete(current);
    }

    size--;
    return true;
}

template <class T>
T DoubleLinkedList<T>::get_at(int index) {
    if(size == 0){
        throw std::out_of_range("List is empty");
    }
    else if(index > size - 1 || index < 0){
        throw std::out_of_range("Index out of range");
    }

    T value = DoubleLinkedList<T>::peek_at(index);
    DoubleLinkedList<T>::remove(index);
    return value;
}

template <class T>
T DoubleLinkedList<T>::get() {
    if(size == 0){
        throw std::out_of_range("List is empty");
    }
    return DoubleLinkedList<T>::get_at(0);
}

#endif //SCRATCH_DOUBLE_LINKED_LIST_H
