//
// Created by Dylan Verrezen on 2016/05/27.
//

#ifndef SCRATCH_STACK_H
#define SCRATCH_STACK_H

#include "double_linked_list.h"

template <class T> class Stack {
public:
    Stack();
    bool push(const T value);
    T peek();
    T pop();
    bool is_empty();
    int get_size();

private:
    DoubleLinkedList<T> items;
    int size;
    bool empty;
};

template <class T>
Stack<T>::Stack() : empty(true), size(0) {};

template <class T>
bool Stack<T>::is_empty() {
    return empty;
}

template <class T>
int Stack<T>::get_size() {
    return size;
}

template <class T>
bool Stack<T>::push(const T value) {
    items.insert(value);
    size++;

    if(empty){ empty = false; }

    return true;
}

template <class T>
T Stack<T>::pop() {
    if(empty){
        throw std::out_of_range("Stack is empty");
    }
    T value =  items.get_at(size - 1);
    size--;
    if(size ==0 ){
        empty = true;
    }
    return  value;
}

template <class T>
T Stack<T>::peek() {
    if(empty){
        throw std::out_of_range("Stack is empty");
    }
    return items.peek_at(size - 1);
}


#endif //SCRATCH_STACK_H
