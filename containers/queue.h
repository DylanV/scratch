//
// Created by Dylan Verrezen on 2016/05/27.
//

#ifndef SCRATCH_QUEUE_H
#define SCRATCH_QUEUE_H

#include "linked_list.h"

template <class T> class Queue {
public:
    Queue();
    bool push(const T value);
    T peek();
    T pop();
    bool is_empty();
    int get_size();

private:
    LinkedList<T> items;
    int size;
    bool empty;
};

template <class T>
Queue<T>::Queue() : empty(true), size(0) {};

template <class T>
bool Queue<T>::is_empty() {
    return empty;
}

template <class T>
int Queue<T>::get_size() {
    return size;
}

template <class T>
bool Queue<T>::push(const T value) {
    items.insert(value);
    size++;

    if(empty){ empty = false; }

    return true;
}

template <class T>
T Queue<T>::pop() {
    if(empty){
        throw std::out_of_range("Queue is empty");
    }
    T value =  items.get(0);
    size--;
    if(size ==0 ){
        empty = true;
    }
    return  value;
}

template <class T>
T Queue<T>::peek() {
    if(empty){
        throw std::out_of_range("Queue is empty");
    }
    return items.peek_at(0);
}



#endif //SCRATCH_QUEUE_H
