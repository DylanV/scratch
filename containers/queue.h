//
// Created by Dylan Verrezen on 2016/05/27.
//

#ifndef SCRATCH_QUEUE_H
#define SCRATCH_QUEUE_H

#include "linked_list.h"

template <class T> class Queue {
public:
    T peek();
    bool add(const T value);
    bool remove(const T value);
    bool is_empty();

private:
    LinkedList<T> items;
    int size;
    bool empty;
};



#endif //SCRATCH_QUEUE_H
