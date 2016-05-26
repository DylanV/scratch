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
    bool insert(int value);
    int get_index(int value);
    int get(int index);
    bool remove(int index);

private:
    int size;
    ListItem* head;
};


#endif //SCRATCH_LINKED_LIST_H
