//
// Created by Dylan on 26/05/2016.
//

#ifndef SCRATCH_LINKED_LIST_H
#define SCRATCH_LINKED_LIST_H

#include <memory>

//typedef struct ListItem ListItem;



class LinkedList {

    struct ListItem{
        int value;
        ListItem* next;
};

public:

    LinkedList();
    ~LinkedList();

    int get_size();
    bool insert(const int value);
    int get_index(const int value);
    int get(const int index);
    bool remove(const int index);
    int operator[](const int& index);

private:
    int size;
    ListItem* head;
    ListItem* tail;
};


#endif //SCRATCH_LINKED_LIST_H
